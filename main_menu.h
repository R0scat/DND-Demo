#ifndef MENU_H
#define MENU_H
#include <map>
#include <string>
#include <functional>
#include <iostream>
#include <limits>

// am facut asta doar pt ca voiam macar un meniu singleton (restul sut doar switch case-ur)

class Menu
{
    Menu() = default;
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;
    std::map<int, std::pair<std::string, std::function<void()>>> items_;
public:
    static Menu& GetInstance();
    void AddItem(int option, const std::string& description, std::function<void()> action);
    void ShowAndExecute();
};

#endif // MENU_H
