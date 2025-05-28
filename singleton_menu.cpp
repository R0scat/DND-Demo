#include "singleton_menu.h"

SingletonMenu* SingletonMenu::GetInstance() // functia care initiaza singurul obiect din clasa aceasta sau returneaza cel deja creeat
{
	if (!m_menu_ptr) // exista pointerul catre obiect?
	{
		// daca nu exista il creez
		m_menu_ptr = new SingletonMenu; 
		return m_menu_ptr;
	}
	// daca exista il returnez
	return m_menu_ptr;
}

void SingletonMenu::AddMenuItem(int option, const std::string& description, std::function<void()> action)
{
	// folosesc <map> si std::pair (idee de la o prietena) pt ca poate stoca toate tipurile de date de care am eu nevoie extrem de simplu --> dictionarul-ish (map) are ca si cheie numarul cerintei din meniu si ca membru un pair de string si functie (strng-ul descrie functia ce urmeaza sa fie apelata)

	m_menu[option] = { description, std::move(action) };
}

void SingletonMenu::StartMenu()
{
	int choice;

	for (auto& [option, desc] : m_menu)
	{
		std::cout << option << "." << desc.first << "\n";
	}

	std::cout << "Welcome to the Dungeons and Dragons simulator, please choose your role:\n";
	
	if (!(std::cin >> choice))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Eroare...\n";
		return;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	auto desc = items_.find(choice);
	if (desc != items_.end())
	{
		desc->second.second();
	}
	else {
		std::cout << "Invalid option...\n";
	}
}