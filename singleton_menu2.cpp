#include "singleton_menu2.h"

SingletonMenu& SingletonMenu::GetInstance() {
    static SingletonMenu instance;
    return instance;
}

void SingletonMenu::AddMenuItem(int option, const std::string& description, std::function<void()> action) {
    m_menu[option] = { description, std::move(action) };
}

void SingletonMenu::ShowMenu() {
    int choice;

    std::cout << "Welcome to the Dungeons and Dragons simulator, please choose your role:\n";
    for (const auto& menu_item : m_menu) {
        // in c++ '17 poti lua direct un pair de ex [option, desc] dar aici tb luate fiecare in parte + tb casted ca int in loc de const ... 
        int option = static_cast<int>(menu_item.first);
        const auto& pair = menu_item.second;
        std::cout << option << ". " << pair.first << "\n";
        // luand fiecare elem din "dictionar"
    }
    std::cout << "Your choice: ";

    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input... Maybe enter a number?\n";
        return;
        // aici e singurul loc in care chiar am facut o verificare daca user-ul introduce sau nu un numar! In rest poate pica oops...
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    auto it = m_menu.find(choice);
    if (it != m_menu.end()) {
        it->second.second(); // call the action!!!
    }
    else {
        std::cout << "Invalid option...\n";
    }
}