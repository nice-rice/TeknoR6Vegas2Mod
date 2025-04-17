#pragma once
#include "Manager.h"
#include <msclr\marshal_cppstd.h>

ModManager::ModManager() {
	m_bStartProcess = false;
	m_sCurrentMap = "Mb01_Import";

	m_bIsHost = false;
	m_sServerName = "Default Server";
	m_sServerPassword = "";

	m_iMaxPlayers = 0;
	m_iTerrorCount = 0;
	m_iSpawnRate = 0;
	m_iTimeLimit = 0;
	m_iDifficulty = 2;
	m_iRespawnCount = 1;

}

ModManager::~ModManager() {}
ModManager& ModManager::GetInstance() {
	static ModManager instance;
	return instance;
}
void ModManager::Init() {
	bool ret = false;

	while (!ret) {
		if (m_bStartProcess) {
			ModifyMemory();
			m_bStartProcess = false;
		}
		else {
			Sleep(100);
		}
	}

}
void ModManager::StartProcess(bool start) {
	m_bStartProcess = start;
}
bool ModManager::LoadProcess(LPCSTR Filename){
	
	// Mutable string required by CreateProcess
	std::string commandLine = "../Binaries/RainbowSixVegas2_SADS.exe engine.servercommandlet " +
		m_sCurrentMap + "?AgO=0?AgU=" +
		m_sServerName + "?AgP=?SrvOptionFile=R6VegasServerConfig?PW=" +
		m_sServerPassword + "?GAME=R6Game.R6CoopTerroristHuntGame?GD=" +
		std::to_string(m_iDifficulty) + "?BT=30?TBR=0?RD="+std::to_string(m_iTimeLimit)+"?";
	char* cmdLineMutable = &commandLine[0];
	
	if (!CreateProcess(NULL, // No module name (use command line). 
		cmdLineMutable,			  // Command line.
		NULL,             // Process handle not inheritable. 
		NULL,             // Thread handle not inheritable. 
		FALSE,            // Set handle inheritance to FALSE. 
		CREATE_SUSPENDED | CREATE_NEW_PROCESS_GROUP, // suspended creation flags. 
		NULL,             // Use parent's environment block. 
		NULL,             // Use parent's starting directory. 
		&si,              // Pointer to STARTUPINFO structure.
		&pi)             // Pointer to PROCESS_INFORMATION structure.
		)
	{
		return false;
	}
	mycontext.ContextFlags = 0x00010000 + 1 + 2 + 4 + 8 + 0x10;
	return true;
}

int ModManager::RunTo(DWORD Address, DWORD Mode, DWORD Eip){
	
	char tempbuf[4];
	int count = 0;
	if (Eip != 0)
	{
		GetThreadContext(pi.hThread, &mycontext);
		mycontext.Eip = Eip;
		SetThreadContext(pi.hThread, &mycontext);
	}
	ReadProcessMemory(pi.hProcess, (LPVOID)Address, tempbuf, 4, 0);
	WriteProcessMemory(pi.hProcess, (LPVOID)Address, "\xEB\xFE", 2, 0);
	ResumeThread(pi.hThread);
	while (1)
	{
		if (count == 10) return 0;
		if (!GetThreadContext(pi.hThread, &mycontext)) count++;
		else count = 0;
		if (Mode == 0) Sleep(500);
		if (Mode == 1) WriteProcessMemory(pi.hProcess, (LPVOID)Address, "\xEB\xFE", 2, 0);
		if (mycontext.Eip == Address) break;
	}
	SuspendThread(pi.hThread);
	if (!GetThreadContext(pi.hThread, &mycontext)) return 0;
	WriteProcessMemory(pi.hProcess, (LPVOID)Address, tempbuf, 4, 0);
	return 1;
}



void ModManager::ModifyMemory(){

	PEStruct FilePEFile = getPEFileInformation("../Binaries/RainbowSixVegas2_SADS.exe");
	if (!LoadProcess("../Binaries/RainbowSixVegas2_SADS.exe"))
	{
		//WriteLog("Unable to create process for R6Vegas2_Game.exe");
		return;
	}
	//else WriteLog("Created process for R6Vegas2_Game.exe");
	DWORD OEP = FilePEFile.image_nt_headers.OptionalHeader.AddressOfEntryPoint + FilePEFile.image_nt_headers.OptionalHeader.ImageBase;
	if (!RunTo(OEP, 1, 0))
	{
	//	WriteLog("Process crashed on init");
		return;
	}
	//else WriteLog("Process initialized");
	DWORD codesize = Roundby1000(FilePEFile.image_section_header[0].Misc.VirtualSize);
	DWORD codebase = FilePEFile.image_section_header[0].VirtualAddress + FilePEFile.image_nt_headers.OptionalHeader.ImageBase;
	DWORD oldprot = 0;
	DWORD newprot = 0;
	VirtualProtectEx(pi.hProcess, (LPVOID)codebase, codesize, 0x40, &oldprot);
	if (m_bIsHost)
	{
		// Player Cap
		if (!m_bDefaultPlayers)
		{
			DWORD myval = System::Convert::ToInt32(m_iMaxPlayers);

			WriteProcessMemory(pi.hProcess, (LPVOID)0x10D4DA72, "\x90\x90", 2, 0);
			// Player count #1 here
			WriteProcessMemory(pi.hProcess, (LPVOID)0x10D4DA74, "\xBE\x00\x00\x00\x00", 5, 0);
			WriteProcessMemory(pi.hProcess, (LPVOID)0x10D4DA75, &myval, 4, 0);
			// Player count #2 here
		//	WriteProcessMemory(pi.hProcess,(LPVOID)0x10D67C41, "\xC7\x46\x14\x10\x00\x00\x00\x8B\x7E\x24\xEB\x1D", 12, 0);
			WriteProcessMemory(pi.hProcess, (LPVOID)0x10D679C1, "\xC7\x46\x14\x10\x00\x00\x00\x8B\x7E\x24\xEB\x1D", 12, 0);
			//WriteProcessMemory(pi.hProcess, (LPVOID)0x10D67C44, &myval, 4, 0);
			WriteProcessMemory(pi.hProcess, (LPVOID)0x10D679C4, &myval, 4, 0);
			//
			WriteProcessMemory(pi.hProcess, (LPVOID)0x10D67C67, "\xEB\xD8\x90", 3, 0);
			// Player count #3 here
			WriteProcessMemory(pi.hProcess, (LPVOID)0x10D63691, "\x83\x7E\x18\x02\x75\x47\xC7\x46\x14\x10\x00\x00\x00\xEB\x18", 15, 0);
			WriteProcessMemory(pi.hProcess, (LPVOID)0x10D6369A, &myval, 4, 0);
			WriteProcessMemory(pi.hProcess, (LPVOID)0x10D636B6, "\xEB\xD9\x83\x7E\x04\x00\x90", 7, 0);
			WriteProcessMemory(pi.hProcess, (LPVOID)0x10D636DE, "\xEB\x4D", 2, 0);
			WriteProcessMemory(pi.hProcess, (LPVOID)0x10D6372D, "\xEB\x42", 2, 0);
			WriteProcessMemory(pi.hProcess, (LPVOID)0x10D63771, "\x89\x46\x14\xE9\x3F\xFF\xFF\xFF", 8, 0);
		}
		// Terrorist Count
		if (!m_bDefaultTerrorCount)
		{
			DWORD myval = System::Convert::ToInt32(m_iTerrorCount);
			WriteProcessMemory(pi.hProcess, (LPVOID)0x10A2B38C, "\xEB\x45\x90\x90", 4, 0);
			WriteProcessMemory(pi.hProcess, (LPVOID)0x10A2B3D3, "\xB8\x00\x00\x00\x00\xEB\xB6", 7, 0);
			WriteProcessMemory(pi.hProcess, (LPVOID)0x10A2B3D4, &myval, 4, 0);
		}
	}
	//// Eyefinity
	//if (EyeMonitorBox->Checked == true)
	//{
	//	WriteProcessMemory(pi.hProcess, (LPVOID)0x12172ab8, "\x00\x00\x70\x40\x9A\x99\x99\x40\x00\x00\x80\x40", 12, 0);
	//}
	VirtualProtectEx(pi.hProcess, (LPVOID)codebase, codesize, oldprot, &newprot);

	ResumeThread(pi.hThread);
	WaitForSingleObject(pi.hThread, INFINITE);
	//while (GetThreadContext(pi.hThread, &mycontext)) 
	//	Sleep(1000);
	CloseHandle(pi.hThread);
	for (unsigned int i = 0; i < FilePEFile.numOfSecs; i++) {
		free(FilePEFile.image_section[i]);
		FilePEFile.image_section[i] = NULL;
	}
	free(FilePEFile.fileImage);
	FilePEFile.fileImage = NULL;
	//WriteLog("Process exited");

}
void ModManager::SetServer(bool s, System::String^ name, System::String^ pwd) {
	m_bIsHost = s;
	msclr::interop::marshal_context context;
	m_sServerName = context.marshal_as<std::string>(name);
	m_sServerPassword = context.marshal_as<std::string>(pwd);

}
void ModManager::SetRespawn(int val) {
	m_iRespawnCount = val;
}
void ModManager::SetDifficulty(System::String^ diff) {
	msclr::interop::marshal_context context;
	std::string difficulty_name = context.marshal_as<std::string>(diff);
	if (difficulty_name == "Realistic") { m_iDifficulty = 3; }
	else if (difficulty_name == "Normal") { m_iDifficulty = 2; }
	else if (difficulty_name == "Easy") { m_iDifficulty = 1; }
	else { m_iDifficulty = 3; }

}
void ModManager::SetTimeLimit(int val) {
	m_iTimeLimit = val*60;
}
void ModManager::SetSpawnRate(System::Object^ val) {
	if (val != "Default") {
		m_iSpawnRate = 8;
	}
	else {
		m_iSpawnRate = System::Convert::ToInt32(val);
	}
		std::string spawn = std::to_string(m_iSpawnRate);

		LPCSTR filename = "../KellerGame/Config/PlatformSpecificConfigPC.ini";
		LPCSTR key = "MaxTerrorist";
		
		LPCSTR value = spawn.c_str();
		BOOL ret = WritePrivateProfileStringA("Gameplay", key, value, filename);
		key = "MaxTerroristTerroHunt";
		ret = WritePrivateProfileStringA("Gameplay", key, value, filename);
	
}
void ModManager::SetTerrorCount(System::Object^ val) {
	if (val != "Default") {
		m_bDefaultTerrorCount = false;
		m_iTerrorCount = System::Convert::ToInt32(val);
		
	}
	else {
		m_bDefaultTerrorCount = true;
	}
}
void ModManager::SetMaxPlayers(int val) {
	if (val == 0) {
		m_bDefaultPlayers = true;
	}
	else {
		m_bDefaultPlayers = false;
		m_iMaxPlayers = val;
	}
}
void ModManager::SetMap(int map) {
	
	m_sCurrentMap = g_aMapList[map];

}