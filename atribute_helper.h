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

    inline void ReadEquipment(Equipment available_equipment[40], int& total_equipment)
    {
        char types[10][50] =
        {
            "martial melee weapons",
			"martial ranged weapons",
			"simple melee weapons",
			"simple ranged weapons",
        };
        int nr_equipment = 0;
        for (int i = 0; i < 4; i++)
        {
            char file_name[50] = "resources/equipment/";
            strcat(file_name, types[i]);
            strcat(file_name, ".txt");
            std::ifstream fin(file_name);
            char line[250];
            while (fin.get(line, 140))
            {
                fin.get();
                char* ptr = strtok(line, "#");
                int index = 0;
                available_equipment[nr_equipment].SetAtributeType(types[i]);
                while (ptr != NULL) // cat timp linia are atribute de citit
                {
                    switch (index) // in functie de index sunt completate atributele echipamentului (in fisier sunt puse mereu in aceeasi ordine pt usurinta)
                    {
                    case 0: 
                    {
                        available_equipment[nr_equipment].SetAtributeName(ptr);
                        break;
                    }
                    case 1:
                    {
                        available_equipment[nr_equipment].SetCurrencyValue(ptr);
                        break;
                    }
                    case 2:
                    {
                        available_equipment[nr_equipment].SetDamage(ptr);
                        break;
                    }
                    case 3:
                    {
                        available_equipment[nr_equipment].SetWeight(ptr);
                        break;
                    }
                    case 4:
                    {
                        available_equipment[nr_equipment].SetAtributeDescription(ptr);
                        break;
                    }
                    default:
                        break;
                    }
                    index++;
                    ptr = strtok(NULL, "#");
                }
                nr_equipment++;
            }
            fin.close();
        }
        total_equipment = nr_equipment;
    }

}

#endif // !ATRIBUTEHELPER_H