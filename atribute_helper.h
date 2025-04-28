#pragma once
#ifndef ATRIBUTEHELPER_H
#define ATRIBUTEHELPER_H

#include <iostream>
#include <fstream>
#include <string>
#include "class.h"

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
        Class test_class;
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
                    test_class.AddProficiency(line);
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
        test_class.ShowProficiencies();
        std::cout << std::endl;
        
        test_class.DeleteFirstProficiency();
        test_class.ShowProficiencies();
        std::cout << std::endl;

        test_class.DeleteLastProficiency();
        test_class.ShowProficiencies();
        std::cout << std::endl;

        fin.close();
    }
}

#endif // !ATRIBUTEHELPER_H
