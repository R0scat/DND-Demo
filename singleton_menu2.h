#pragma once
#ifndef SINGLETON_MENU_H
#define SINGLETON_MENU_H

#include <iostream>
#include <map>
#include <functional>
#include <string>

class SingletonMenu {
public:
    // Get the singleton instance
    static SingletonMenu& GetInstance();

    // Add a menu item
    void AddMenuItem(int option, const std::string& description, std::function<void()> action);

    // Display and handle the menu
    void ShowMenu();

private:
    // Private constructor and deleted copy/move
    SingletonMenu() = default;
    SingletonMenu(const SingletonMenu&) = delete;
    SingletonMenu& operator=(const SingletonMenu&) = delete;

    // Menu map: option -> (description, action)
    std::map<int, std::pair<std::string, std::function<void()>>> m_menu;
};

#endif // SINGLETON_MENU_H
