#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"
#include "Module.h"
#include "Dummy.h"
#include "OwnModule.h"

#define NUM_MODULES 2

class Application
{
public:

	Module* modules[NUM_MODULES];

public:

	Application()
	{
		modules[0] = new ModuleDummy();
		modules[1] = new ModuleOwn();
		// TODO 4: Create your new module
		// it should check if player it ESC key
		// use kbhit()
		// http://www.cprogramming.com/fod/kbhit.html
	}

	// INIT all modules
	bool Init() 
	{
		for (int i = 0; i < NUM_MODULES; ++i)
		{
			if (modules[i]->Init() == false)
				return false;
		}
		
		return true; 
	}

	// UPDATE all modules
	// TODO 2: Make sure all modules receive its update
	int Update() { 
		for (int i = 0; i < NUM_MODULES; ++i)
		{
			if (modules[i]->Update() != UPDATE_CONTINUE)
				return UPDATE_ERROR;
		}
		
		return UPDATE_STOP; 
	}

	// EXIT Update 
	// TODO 3: Make sure all modules have a chance to cleanup
	bool CleanUp()
	{
		for (int i = NUM_MODULES-1; i >= 0; --i)
		{
			if (modules[i]->CleanUp() == false)
				return false;
		}
		return true;
	}

};

#endif // __APPLICATION_H__