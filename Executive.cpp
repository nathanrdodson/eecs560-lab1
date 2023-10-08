#include <fstream>
#include <string>
#include "Executive.h"
#include "LinkedList.h"

Executive::Executive(std::string argIn)
{    
    filename = argIn;
}

Executive::~Executive()
{
}

// determine if strings are numeric from file input. Adapted from this stack overflow:
// https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c/16575025
bool Executive::isValidData(const std::string& input) 
{
	std::string::const_iterator it = input.begin();
    while (it != input.end() && std::isdigit(*it)) ++it;
    return !input.empty() && it == input.end();
}

void Executive::run()
{
	LinkedList<int> inputData = LinkedList<int>();

	// read data and store to linked list
	std::ifstream inFile;
    inFile.open(filename);

	std::string line;
	int lineItem;
	int count = 1;


	while(inFile >> line)
	{
		if(isValidData(line))
		{
			lineItem = std::stoi(line);
			inputData.insert(count,lineItem);
		} else {
			std::cout << "Input contains non-numeric types. Exiting...\n";
			return;
		}
		count++;
	}
	
	inFile.close();

	// print menu and run operations on linked list
	int menuInput = 0;

	while(menuInput != 9)
	{
		std::cout <<
			"=================\n" <<
			"Please choose one of the following operations:\n" <<
			"1. isEmpty()\n" <<
			"2. length()\n" <<
			"3. insert()\n" <<
			"4. delete()\n" <<
			"5. find()\n" <<
			"6. appendList(newList)\n" <<
			"7. print()\n" <<
			"8. reverseList()\n" <<
			"9. exit()\n"
			"=================\n" <<
			"=> ";

		while(!(std::cin >> menuInput))
		{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				std::cout << "Invalid input. Try again:\n=> ";
		}		

		LinkedList<int> appendableList = LinkedList<int>();

		switch (menuInput)
		{
		case 1:
			std::cout << ((inputData.length()) ? "List is not empty" : "List is empty") << '\n';
			break;
		
		case 2:
			std::cout << "The length of the list is: " << inputData.length() << '\n';
			break;

		case 3:
			std::cout << "Choose a number to be inserted into the list: ";
			while(!(std::cin >> menuInput))
			{
				std::cin.clear();
				std::cin.ignore(10, '\n');
				std::cout << "Invalid input. Try again:\n=> ";
			}
			inputData.insert(1,menuInput);
			std::cout << menuInput << " is inserted.\n";
			break;

		case 4:
			std::cout << "Choose a number to be deleted from the list: ";
			while(!(std::cin >> menuInput))
			{
				std::cin.clear();
				std::cin.ignore(10, '\n');
				std::cout << "Invalid input. Try again:\n=> ";
			}
			if(inputData.find(menuInput))
			{
				inputData.removeByValue(menuInput);
				std::cout << menuInput << " was successfully deleted!\n";
			} else {
				std::cout << menuInput << " was not found in the list...\n";
			}
			break;

		case 5:
			std::cout << "Choose a number to search for: ";
			while(!(std::cin >> menuInput))
			{
				std::cin.clear();
				std::cin.ignore(10, '\n');
				std::cout << "Invalid input. Try again:\n=> ";
			}			
			std::cout << menuInput << ((inputData.find(menuInput)) ? " was successfully found!\n" : " was not found in the list.\n");
			break;
		
		case 6:
			std::cout << "Appending first five elements...\n";
			inFile.open(filename);
			for(int i = 1; i <= 5; i++)
			{
				inFile >> lineItem;
				appendableList.insert(i,lineItem);
			}
			inFile.close();
			inputData.appendList(appendableList);

			for(int i = 1; i <= inputData.length(); i++)
				std::cout << inputData.getEntry(i) << ' ';
			std::cout << '\n';
			break;
		
		case 7:
			inputData.printList();
			break;
		
		case 8:
			inputData.reverse();
			for(int i = 1; i <= inputData.length(); i++)
			{
				std::cout << inputData.getEntry(i) << ' ';
			}
			std::cout << '\n';
			break;

		default:
			std::cout << "Invalid input. Try again\n";
			break;
		}
	}
}

