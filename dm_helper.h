#pragma once
#ifndef DMHELPER_H
#define DMHELPER_H

#include <iostream>

namespace DM_Helper {
	inline void ShowDmMenu()
	{
		std::cout << "Dungeon Master settings:\n";
		std::cout << "1. create a creature\n";
		std::cout << "2. create a character\n";
		std::cout << "3. show all entities\n";
		std::cout << "4. calculate strenghts for all entities\n";
		std::cout << "5. apply effect on given entity\n";
		std::cout << "6. roll dice menu\n";
		std::cout << "7. exit\n";
	}

	inline void DmMenuPicker(int option, bool &ongoing)
	{
		switch (option)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			std::cout << "Quitting...";
			ongoing = false;
			break;
		}
		default:
		{
			std::cout << "Option unavailable, try another input?";
			std::cin >> option;
			DmMenuPicker(option, ongoing);
			break;
		}
			
		}
	}
}

#endif // !DMHELPER_H
