#ifndef __OWNMODULE_H__
#define __OWNMODULE_H__

#include "Module.h"
#include "Globals.h"
#include <conio.h>

class ModuleOwn : public Module
{
	bool Init()
	{
		LOG("OwnModule Init!");
		return true;
	}

	int Update()
	{
		LOG("OwnModule Update!");
		if (kbhit())
			return true;
	}

	bool CleanUp()
	{
		LOG("OwnModule CleanUp!");
		return true;
	}
};

#endif // __OWNMODULE_H__