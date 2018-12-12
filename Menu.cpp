#include <iostream>
#include <string>

using namespace std;

//A menu that is displayed on program run
class Menu
{
public:
	//constructs a menu w/ no options = Default Constructor
	Menu();
	//adds an option to the end of this menu
	//@param option the option to add
	void add_option(string option);
	//displays menu, with options numbered starting with 1, and prompts the user for input. Repeats until a valid input is supplied
	//@return the number that the user has supplied
	int get_input() const;
	//display menu
	void display() const;
private:
	string options;
	int counter;
};

Menu::Menu()
{
	string options;
	counter = 0;
}

void Menu::add_option(string option)
{
	counter++;
	string strcount = to_string(counter);
	string space = ("    ");
	options.append(strcount);
	options.append(space);
	options.append(option);
	options.append("\n");
}

int Menu::get_input() const
{
	int input;
	do
	{
		display();
		cin >> input;

	} while (input < 1 || input > counter);
	return input;
}

void Menu::display() const
{
	cout << options << endl;