#pragma warning(disable : 4996)
#pragma once
#ifndef ATRIBUTEHELPER_H
#define ATRIBUTEHELPER_H

#include <iostream>
#include <fstream>
#include <string>
#include "class.h"
#include "player_character.h"
#include <cstring>
#include "equipment.h"
//#include <regex>

namespace Atribute_Helper
{
    inline int UpdateCurrentAtribute(int current_class_atribute, std::string line)
    {
        if (line == "// proficiencies")
        {
            current_class_atribute = 1;
            //std::cout << current_class_atribute << "\n";
        }
        else if (line == "// equipment")
        {
            current_class_atribute = 2;
            //std::cout << current_class_atribute << "\n";
        }
        else if (line == "// abilities")
        {
            current_class_atribute = 3;
            //std::cout << current_class_atribute << "\n";
        }
        return current_class_atribute;
    }

    inline void ReadAtributes()
    {
        char file_name[50] = "resources/class_abilities/paladin.txt";
        std::ifstream fin(file_name);

        std::string line;
        Class given_class;
        PlayerCharacter pc;
        int current_class_atribute = 0;
        // class atributes in this order in file: proficiency, equipment, abilities
        
        while (std::getline(fin, line)) // reading given file
        {
            std::cout << line << std::endl;
			current_class_atribute = UpdateCurrentAtribute(current_class_atribute, line);

            switch (current_class_atribute)
            {
            case 1:
            {
                if (line != "// proficiencies")
                    given_class.AddProficiency(line);
            }
            case 2:
            {
                if (line != "// equipment")
                    break;
                //std::cout << current_class_atribute << "\n";
            }
            case 3:
            {
                if (line != "// abilities")
                    break;
                //std::cout << current_class_atribute << "\n";
            }
            
            }
            
        }
		pc.AddCharacterClass(given_class);
        fin.close();
    }

    inline void ReadEquipment(Equipment available_equipment[40])
    {
        char files[10][50] =
        {
            "resources/equipment/martial melee weapons.txt",
			"resources/equipment/martial ranged weapons.txt",
			"resources/equipment/simple melee weapons.txt",
			"resources/equipment/simple ranged weapons.txt",
        };
        for (int i = 0; i < 4; i++)
        {
            std::ifstream fin(files[i]);
            char line[250];
            while (fin.get(line, 140))
            {
                fin.get();
                char* ptr = strtok(line, "#");
                while (ptr != NULL)
                {
					std::cout << ptr << std::endl;
                    ptr = strtok(NULL, "#");
                }
            }
            fin.close();
        }
    }

}

#endif // !ATRIBUTEHELPER_H