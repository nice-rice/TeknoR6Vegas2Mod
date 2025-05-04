#pragma once
#include <windows.h>

#include <string>
#include <cstring>

#define NUM(a) (sizeof(a) / sizeof(*a))
#define Roundby1000(a) (a / 0x1000 + ((a % 0x1000) > 0 ? 1 : 0)) * 0x1000



class IniConfig {
public:
	IniConfig();
	~IniConfig();
	void SavePreferences();
	bool WriteINI(LPCSTR file, LPCSTR section, LPCSTR key, LPCSTR value);

	void SetInternet();
	void SetSound();
	void SetWeapons();
	void SetGadgets();

	void SetMap(int map);
	void SetRespawn(bool on, int count);
	void SetSpawnRate(int count);
	void SetTimeLimit(int time);

	const std::string g_aMapList[17] = {
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
"MB14_Convent_MLG"
	};

	const std::string g_aWeaponList[20] = {
		"ConfigR6SubMP5N", "ConfigR6SubMP7A1", "ConfigR6SubUMP45", "ConfigR6SubP90",
		"ConfigR6SubMP9","ConfigR6SubMAC11","ConfigR6SubVZ83","ConfigR6SubType05JS","[R6Game.ConfigR6SubAUGPara]",
		
		"ConfigR6AssaultSCARHCQC","ConfigR6AssaultM8","ConfigR6AssaultAUGA3","ConfigR6AssaultG3KA4","ConfigR6Assault552Commando",
		"ConfigR6AssaultG36C","ConfigR6AssaultMTAR21","ConfigR6AssaultFamas","ConfigR6AssaultAK47","ConfigR6AssaultM468"
	};
};