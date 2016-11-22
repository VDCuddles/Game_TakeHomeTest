#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Game.h"

//Table of Contents

//Question 1 answers below; 1.4) - see header and source files

//Question 2 answers in Particle class

void runGame() {
	Game* game = new Game();
	game->run();
}

int main()
{

	//1.1) pointer variables vs. reference variables

	std::string variable = "value"; //initialise a value for a variable
	std::string variable2 = "value2"; //initialise a value for a second variable

	std::string* pointer = &variable; //initialise a pointer which points to the data stored in a variable
	std::string& reference = variable; //initialise a direct reference to the first variable


	std::cout << "pointer: ";
	std::cout << pointer << std::endl;  //printing a pointer shows you that what exactly is stored here POINTS (using a memory address) to data,
									    //it does not in itself contain the data
	std::cout << "variable: ";
	std::cout << variable << std::endl; //printing the variable, as expected, prints the variable.
										//it is passing by value, not by reference.
	std::cout << "reference: ";
	std::cout << reference << std::endl;//printing the reference prints the data stored in the variable
										//as it is a direct reference, not a pointer.

	pointer = &variable;
	std::cout << "pointer pointing to first variable: ";
	std::cout << pointer << std::endl; //this is the memory address of the first variable
	pointer = &variable2;
	std::cout << "pointer pointing to second variable: ";
	std::cout << pointer << std::endl; //this is the memory address of the second variable 


	reference = variable2;				//changing the data the reference refers to
	pointer = &reference;				//changing the pointer to pass by reference rather than value

	std::cout << "pointer pointing to reference: ";
	std::cout << pointer << std::endl;  //even though the data for reference is now technically holding different information,
										//printing this pointer prints the same memory addess as what it was doing initially
										//because basically reference = variable2 is the same as variable = variable2

	std::cout << "first variable after reference = variable2: ";
	std::cout << variable << std::endl; //this proves it

	variable += " with modified data";

	std::cout << "pointer after variable changed: ";
	std::cout << pointer << std::endl;  //as the last call was essentially variable = variable2,
										//the pointer now holds variable2's data at variable's address

	std::cout << "changed variable: ";
	std::cout << variable << std::endl; //since variable has variable2's data
										//printing this prints variable2's data with the modification

	std::cout << "reference data now that variable itself has changed: ";
	std::cout << reference << std::endl;//since this refers to variable2's data (now stored in variable)
										//this prints the same as above

	runGame();

	return 0;
}