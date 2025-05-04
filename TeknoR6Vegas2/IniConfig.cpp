#include "IniConfig.h"

IniConfig::IniConfig() {}
IniConfig::~IniConfig() {}


void IniConfig::SetInternet() {
	
	LPCSTR filename = "../KellerGame/Config/PCKellerEngine.ini";
	
	for (int i = 0; i < 2; ++i) {

		LPCSTR section = "Engine.Player";
		WriteINI(filename, section, "ConfiguredInternetSpeed", "500000");
		WriteINI(filename, section, "ConfiguredLanSpeed", "500000");

		section = "IpDrv.TcpNetDriver";
		WriteINI(filename, section, "AllowDownloads", "True");
		WriteINI(filename, section, "EnableTimeout", "True");
		WriteINI(filename, section, "ConnectionTimeout", "30.0");
		WriteINI(filename, section, "InitialConnectTimeout", "30.0");

		WriteINI(filename, section, "AckTimeout", "0.5");
		WriteINI(filename, section, "KeepAliveTime", "0.1");
		WriteINI(filename, section, "MaxClientRate", "100000");
		WriteINI(filename, section, "MaxInternetClientRate", "100000");

		WriteINI(filename, section, "RelevantTimeout", "10.0");
		WriteINI(filename, section, "SpawnPrioritySeconds", "0.5");
		WriteINI(filename, section, "ServerTravelPause", "10.0");
		WriteINI(filename, section, "NetServerMaxTickRate", "60");
		WriteINI(filename, section, "LanServerMaxTickRate", "60");

		//Repeat for BaseEngine file
		filename = "../Engine/Config/BaseEngine.ini";
	}
}

void IniConfig::SetSound() {
	LPCSTR filename = "../KellerGame/Config/PCKellerEngine.ini";
	LPCSTR section = "ALAudio.ALAudioDevice";

	for (int i = 0; i < 2; ++i) {
		WriteINI(filename, section, "MaxChannels", "64");
		WriteINI(filename, section, "TimeBetweenHWUpdates", "5");
		filename = "../Engine/Config/BaseEngine.ini";
	}
}

void IniConfig::SetWeapons() {
	//
	//R6Game.ConfigR6SubMP5N
//m_iDefaultAmmunitionRealistic 500
	
	LPCSTR filename = "../KellerGame/Config/DefaultWeaponsConfig.ini";
	LPCSTR key = "m_iDefaultAmmunitionRealistic";
	LPCSTR value = "500";
	LPCSTR section = "";

	for (int i = 0; i < NUM(g_aWeaponList); ++i) {
		std::string header = "R6Game." + g_aWeaponList[i];
		section = header.c_str();
		WriteINI(filename, section, key, value);
	}

}

void IniConfig::SetGadgets() {

	LPCSTR filename = "../KellerGame/Config/DefaultGadgetsConfig.ini";
	LPCSTR a_section[8] = { "R6Game.R6GadgetGrenadeFlashbang","R6Game.R6GadgetGrenadeFrag",
							"R6Game.R6GadgetGrenadeIncendiary","R6Game.R6GadgetGrenadeMolotov",
							"R6Game.R6GadgetGrenadeSmoke", "R6Game.R6GadgetGrenadeTearGas",
							"R6Game.R6GadgetExplosiveBreaching","R6Game.R6GadgetExplosiveDemolition"
							};
	LPCSTR key = "m_iMaxAmmoRealistic";
	LPCSTR value = "9";

	for (int i = 0; i < NUM(a_section); ++i) {
		WriteINI(filename, a_section[i], key, value);
	}

}

void IniConfig::SetTimeLimit(int time) {
	std::string time_limt = std::to_string(time);

	LPCSTR filename = "../KellerGame/Config/PC/R6VegasServerConfig.ini";
	LPCSTR section = "Engine.R6ServerOptions";
	LPCSTR key = "m_iRoundDuration";

	LPCSTR value = time_limt.c_str();
	WriteINI(filename, section, key, value);
}

void IniConfig::SetSpawnRate(int count) {
	std::string spawn = std::to_string(count);

	LPCSTR filename = "../KellerGame/Config/PlatformSpecificConfigPC.ini";
	LPCSTR section = "Gameplay";
	LPCSTR key = "MaxTerrorist";

	LPCSTR value = spawn.c_str();
	WriteINI(filename, section, key, value);
	
	key = "MaxTerroristTerroHunt";
	WriteINI(filename, section, key, value);
}

void IniConfig::SetMap(int map) {
	std::string map_code = std::to_string((map + 1) + 200);

	LPCSTR filename = "../KellerGame/Config/PC/R6VegasServerConfig.ini";
	LPCSTR section = "Engine.R6ServerOptions";
	LPCSTR value = map_code.c_str();

	for (int i = 0; i < NUM(g_aMapList); ++i) {
		std::string key_index = "m_iSelectedMaps[" + std::to_string(i) + "]";
		LPCSTR key = key_index.c_str();
		WriteINI(filename, section, key, value);
	}
}

void IniConfig::SetRespawn(bool on, int count) {
	LPCSTR filename = "../KellerGame/Config/PC/R6VegasServerConfig.ini";
	LPCSTR section = "Engine.R6ServerOptions";

	bool respawn_on = on;
	std::string respawn = std::to_string(count);
	
	WriteINI(filename, section, "m_iLimitRespawns", respawn.c_str());
	if (respawn_on)
		WriteINI(filename, section, "m_bRespawn", "True");
	else
		WriteINI(filename, section, "m_bRespawn", "False");
}
bool IniConfig::WriteINI(LPCSTR file, LPCSTR section, LPCSTR key, LPCSTR value) {

	if (WritePrivateProfileStringA(section, key, value, file)) {
		return true;
	}
	else {
		return false;
	}
}

void IniConfig::SavePreferences() {}