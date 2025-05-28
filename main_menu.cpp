#include "main_menu.h"

Menu& Menu::GetInstance()
{
	static Menu instance;
	return instance;
}

void Menu::AddItem(int option, const std::string& description, std::function<void()> action)
{
	items_[option] = { description, std::move(action) };
}

void Menu::ShowAndExecute()
{
    for (auto& [option, it] : items_) {
        std::cout << option << "." << it.first << '\n';
    }
    std::cout << "Alege o optiune: ";
    int choice;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Intrare invalida.\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    auto it = items_.find(choice);
    if (it != items_.end()) {
        it->second.second();
    }
    else {
        std::cout << "Optiune invalida.\n";
    }
}