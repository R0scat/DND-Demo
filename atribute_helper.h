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
#include <vector>
#include "ability.h"
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

    inline void ReadEquipment(Equipment available_equipment[100], int& total_equipment)
    {
        char types[10][50] =
        {
            "martial melee weapons",
            "martial ranged weapons",
            "simple melee weapons",
            "simple ranged weapons",
            "light armor",
            "medium armor",
            "heavy armor",
            "shield"
        };
        int nr_equipment = 0;
        for (int i = 0; i < 8; i++)
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

    inline void PopulateStaticAvailableEquipment()
    {
        Equipment array[100];
        int total_equipment;
        ReadEquipment(array, total_equipment);
        Class::SetAvailableEquipment(array, total_equipment);
        //Class::ShowAllAvailableEquipment();
    }
    
    inline int FindEquipmentContor(std::string line)
    {
        // fac codul mai citibil asa ca o sa copiez vectorul static de echipament intr-unul temporar din scope-ul asta
        std::vector<Equipment> temp = Class::GetAvailableEquipment();
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i].GetAtributeName() == line)
                return i; 
        }
        //std::cout << "Echipamentul nu a fost gasit :P\n";
        //std::cout << line << '\n';
        return -1;
    }

    inline void AddAtribute(std::string line, Ability& current_ability, int contor)
    {
        switch (contor)
        {
        case 1:
        {
            current_ability.SetAtributeName(line);
            break;
        }
        case 2:
        {
            try 
            {
                int level = std::stoi(line); // functie string to integer din libraria std care transforma string in integer yaya
                current_ability.SetAbilityLevel(level);
                //std::cout << "nivelul este: " << level << "\n";
            }
            catch (const std::invalid_argument&)
            {
                break;
                //std::cout << "Invalid input: The string is not a valid number (womp womp)\n";
            }
            catch (const std::out_of_range&)
            {
                break;
                //std::cout << "Number out of range (daca ai ajuns aici nu stiu ce ai gresit pt ca nu ar tb sa se gaseasca un nr mai mare de 20 ....)\n";
            }
             break;
        }
        case 3:
        {
            current_ability.SetAtributeDescription(line);
            break;
        }
        default:
            break;
        }
    }

    inline void ReadAtributes(Class& given_class/*, PlayerCharacter& pc*/)
    {
        std::string file_name = "resources/class_abilities/";
        file_name = file_name + given_class.GetName();
        file_name = file_name + ".txt";
        std::cout << file_name << "\n";
        std::ifstream fin(file_name);

        std::string line;
        //Class given_class;
        //PlayerCharacter pc;
        Ability current_ability;
        int current_class_atribute = 0;
        int contor_abilitati = 1;
        int contor_atribute_abilitate = 0;
        // class atributes in this order in file: proficiency, equipment, abilities
        
        while (std::getline(fin, line)) // reading given file
        {
            //std::cout << line << std::endl;
			current_class_atribute = UpdateCurrentAtribute(current_class_atribute, line);

            switch (current_class_atribute)
            {
            case 1:
            {
                if (line != "// proficiencies")
                    given_class.AddProficiency(line);
                break;
            }
            case 2:
            {
                if (line != "// equipment")
                {
                    int contor;
                    contor = FindEquipmentContor(line);
                    if (contor != -1)
                        given_class.AddEquipment(Class::GetSpecificAvailableEquipment(contor));
                    else
                    {
                        Equipment specific_class_equipment;
                        specific_class_equipment.SetAtributeName(line);
                        given_class.AddEquipment(specific_class_equipment);
                    }

                }
                //std::cout << current_class_atribute << "\n";
                break;
            }
            case 3:
            {
                /*std::cout << "---------------------------\n";
                std::cout << "contor: " << contor_atribute_abilitate << "\n";
                std::cout << line << '\n';*/
                //std::cout << "---------------------------\n";
                if (line != "// abilities")
                {
                    if (line == "~") // fiecare abilitate este despartita printr-un '~'
                    {
                        contor_abilitati++; // numarul total de abilitati 
                        contor_atribute_abilitate = 0; // fiecare atribut al unei abilitati este pastrat de contorul asta, atunci cand se trece la abilitate noua se reseteaza contorul
                        //std::cout << current_ability << '\n';
                        given_class.AddAbility(current_ability);
                    }
                    else
                    {
                        contor_atribute_abilitate++; // daca nu se trece la abilitate noua atunci creste contorul atributelor din abilitate
                        //std::cout << "contor: " << contor_atribute_abilitate << " pt abilitatea:\n " << line << "\n";
                        AddAtribute(line, current_ability, contor_atribute_abilitate);
                    }
                        
                    // OBS: fisierul este structurat asftel incat pt contor_atribute_abilitate = 1 sa apara numele abilitatii, pt 2 nivelul sau si pt 3 descrierea
                    
                }
                break;
                //std::cout << current_class_atribute << "\n";
            }
            
            }
            
        }

        //std::cout << "\nshowing al prof:\n";
        //given_class.ShowProficiencies();
        //std::cout << "\nshowing all equip: \n";
        //given_class.ShowEquipment();
        //std::cout << "------------------------\n";
        //given_class.ShowAbilities();

		//pc.AddCharacterClass(given_class);
        fin.close();
    }


}

#endif // !ATRIBUTEHELPER_H