// TeknoR6Vegas2.cpp : main project file.
#pragma once
#include "stdafx.h"
#include "Form1.h"
#include "Manager.h"
using namespace TeknoR6Vegas2;

DWORD WINAPI modLoop(void* data) {
	ModManager* manager = (ModManager*)data;
	manager->Init();
	return 0;
}

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	
	ModManager* ManagerInstance = &ModManager::GetInstance();
	HANDLE mainThread = CreateThread(NULL, 0, modLoop, (LPVOID)ManagerInstance, 0, NULL);
	
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1(*ManagerInstance));
	return 0;
}
