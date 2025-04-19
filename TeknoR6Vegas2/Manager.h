#pragma once
#include <windows.h>
#include "PE.h"
#include "memory.h"

#include <string>
#include <cstring>


#define Roundby1000(a) (a / 0x1000 + ((a % 0x1000) > 0 ? 1 : 0)) * 0x1000


class ModManager {
public:
	ModManager();
	~ModManager();

	void Init();
	bool LoadProcess(LPCSTR Filename);
	int RunTo(DWORD Address, DWORD Mode, DWORD Eip);
	static ModManager& GetInstance();

	void StartProcess(bool start);
	void ModifyMemory();

	void SetServer(bool s, System::String^ name, System::String^ pwd);
	void SetRespawn(int val);
	void SetDifficulty(System::String^ diff);
	void SetTimeLimit(int val);
	void SetSpawnRate(System::Object^ val);
	void SetTerrorCount(System::Object^ val);
	void SetMaxPlayers(int val);
	void SetMap(int map);
	void SetReadyUp(bool val);
	
	const std::string g_aMapList[18] = {
	"Mb01_Import",
	"Mb02_Dantes_01",
	"Mb03_Neon_01",
	"Mb04_Oil",
	"Mb05_Chinese",
	"Mb06_Trainyard",
	"Mb07_Penthouse_01",
	"Mb08_Conven_01",
	"Mb_09_Murdertown",
	"Mb10_Training_01",
	"Mb11_Streets_01_linkapp",
	"Mb12_KillHouse",
	"Mb13_Presidio",
	"DLC_MP_Casino_01",
	"DLC_Murdertown_2",
	"DLC_Training_02",
	"MB14_Convent_MLG",
	"02_LVU_02"
	};

private:
	_CONTEXT mycontext;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	
	bool m_bStartProcess;
	
	bool m_bIsHost;
	bool m_bDefaultPlayers;
	bool m_bDefaultTerrorCount;
	std::string m_sServerName;
	std::string m_sServerPassword;

	int m_iMaxPlayers;
	int m_iTerrorCount;
	int m_iSpawnRate;
	int m_iTimeLimit;
	int m_iDifficulty;
	int m_iRespawnCount;
	std::string m_sCurrentMap;
	int m_iTimeBetween;
	//std::vector<std::string> m_vMapList;
};