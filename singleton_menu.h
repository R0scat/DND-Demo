#pragma once
#ifndef SINGLETONMENU_H
#define SINGLETONMENU_H

#include <map>
#include <string>
#include <functional>


class SingletonMenu() // menu ce trebuie instantiat doar o data 
{
protected:
	SingletonMenu() = default;
	SingletonMenu(const SingletonMenu&) = delete;
	std::map<int, std::pair<std::string, std::function<void()>>> m_menu();
	SingletonMenu* m_menu_ptr;
public:
	static SingletonMenu* GetInstance();
	void AddMenuItem(int option, const std::string& description, std:function<void()> action);
	void StartMenu();
}

#endif // !SINGLETONMENU_H
