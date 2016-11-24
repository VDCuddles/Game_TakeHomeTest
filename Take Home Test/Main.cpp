#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Game.h"

//Table of Contents

//Question 1) answers below in the main() function call; 1.4) - see Grid class

//Question 2) answers in Particle class

//Question 3) see Sprite and EnvironmentObject class

//Question 4) see Sprite, EnvironmentObject, and Game classes

//Question 5) in external file "Section 5—Problem Solving Capability .docx"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//global variables for demonstrating heap-based data for questions 1.2) and 1.3)

//global variables for question 1.3)

float num1 = 5;
float num2 = 78;
float num3 = 12;
float num4 = 63;
float num5 = 79;
float num6 = 64;
float num7 = 28;
float num8 = 18;
float num9 = 53;
float num10 = 12;

float average;

//function definition for question 1.3)

void calculateAverage() {

	int numarray[10];

	numarray[0] = num1;
	numarray[1] = num2;
	numarray[2] = num3;
	numarray[3] = num4;
	numarray[4] = num5;
	numarray[5] = num6;
	numarray[6] = num7;
	numarray[7] = num8;
	numarray[8] = num9;
	numarray[9] = num10;

	//int total;

	for (int i = 0; i < 10; i++) {
		//total += numarray[i];
		//total /= i;
		average += numarray[i];
	}
	//return average;
	average /= 10;

}

//global variables for question 1.2)

std::string globalVariable = "value"; //initialise a value for a variable
std::string globalVariable2 = "value2"; //initialise a value for a second variable

std::string* gPointer = &globalVariable; //initialise a pointer which points to the data stored in a variable

//function definition for question 1.2)

void showPointerData() {

	std::string* pointer3 = gPointer;
	std::cout << "gPointer: ";
	std::cout << gPointer << std::endl;
	std::cout << "gPointer data: ";
	std::cout << *gPointer << std::endl;
	std::cout << "pointer3: ";
	std::cout << pointer3 << std::endl;
	std::cout << "pointer3 data: ";
	std::cout << *pointer3 << std::endl;

	//+++++++++below code has to be commented, otherwise the rest of the program will break++++++++++++

	//delete gPointer;
	//std::cout << "pointer3: ";
	//std::cout << pointer3 << std::endl;
	//std::cout << "pointer3 data: ";
	//std::cout << *pointer3 << std::endl;

	//as the program crashes when the above is initialised, it proves that dangling pointers are generally
	//not a great idea.

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void runGame() {
	Game* game = new Game();
	game->run();
}

int main()
{
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	//1.1) pointer variables vs. reference variables

	std::string variable = "value"; //initialise a value for a variable
	std::string variable2 = "value2"; //initialise a value for a second variable

	std::string* pointer = &variable; //initialise a pointer which points to the data stored in a variable
	std::string& reference = variable; //initialise a direct reference to the first variable


	std::cout << "pointer: ";
	std::cout << pointer << std::endl;  //printing a pointer shows you that what exactly is stored here POINTS (using a memory address) to data,
									    //it does not in itself contain the data
	std::cout << "pointer data: ";
	std::cout << *pointer << std::endl;  //printing the actual data
										//stored at the above memory address
	std::cout << "variable: ";
	std::cout << variable << std::endl; //printing the variable, as expected, prints the variable.
										//it is passing by value, not by reference.
	std::cout << "reference: ";
	std::cout << reference << std::endl;//printing the reference prints the data stored in the variable
										//as it is a direct reference, not a pointer.

	pointer = &variable;
	std::cout << "pointer pointing to first variable: ";
	std::cout << pointer << std::endl; //this is the memory address of the first variable
	std::cout << "pointer data: ";	  
	std::cout << *pointer << std::endl;//data stored at that address
	pointer = &variable2;
	std::cout << "pointer pointing to second variable: ";
	std::cout << pointer << std::endl; //this is the memory address of the second variable 
	std::cout << "pointer data: ";     
	std::cout << *pointer << std::endl;//data stored at that address


	reference = variable2;				//changing the data the reference refers to
	pointer = &reference;				//changing the pointer to pass by reference rather than value

	std::cout << "pointer pointing to reference: ";
	std::cout << pointer << std::endl;  //even though the data for reference is now technically holding different information,
										//printing this pointer prints the same memory addess as what it was doing initially
										//because basically reference = variable2 is the same as variable = variable2

	std::cout << "first variable after (reference = variable2): ";
	std::cout << variable << std::endl; //this proves it

	variable += " with modified data"; //changing the variable's data

	std::cout << "pointer after variable changed: ";
	std::cout << pointer << std::endl;  //as the last call was essentially variable = variable2,
										//the pointer now holds variable2's data at variable's address
	std::cout << "pointer data: ";
	std::cout << *pointer << std::endl; //data stored at that address

	std::cout << "changed variable: ";
	std::cout << variable << std::endl; //since variable has variable2's data
										//printing this prints variable2's data with the modification

	std::cout << "reference data now that variable itself has changed: ";
	std::cout << reference << std::endl;//since this refers to variable2's data (now stored in variable)
										//this prints the same as above

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
	//1.2) - Dangling Pointers

	//Continuing on from the information in the previous section,
	//what happens if we delete the information that the pointer uses to get its data?

	//using stack based allocation

	std::string* pointer2 = pointer;	//initialise a pointer which points to the data stored in a variable by proxy

	std::cout << "pointer2: ";
	std::cout << pointer2 << std::endl;	//this is the data stored now; notice it shares the same memory address,
										//thus proving it is pointing to the same data
	std::cout << "pointer2 data: ";
	std::cout << *pointer << std::endl; //printing the data stored here as well to prove it


	//+++++++++below code has to be commented, otherwise the rest of the program will break++++++++++++


	//delete pointer;						//delete the proxy pointer
	//std::cout << "pointer2: ";
	//std::cout << pointer2 << std::endl;	//this is the data stored now; notice it shares the same memory address,
	//									//thus proving it is pointing to the same data
	//std::cout << "pointer2 data: ";
	//std::cout << *pointer << std::endl; //printing the data stored here as well to prove it

	//as the program crashes when the above is initialised, it proves that dangling pointers are generally
	//not a great idea.

	//using heap based allocation

	showPointerData();

	//(see above for function and global variable definitions)

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	//1.3) - Average Calculation

	//see above for function and global variable definitions
	
	//std::cout << "average = ";
	//std::cout << calculateAverage() << std::endl;
	calculateAverage();
	std::cout << "average variable data(average) = ";
	std::cout << average << std::endl;

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	runGame();

	return 0;
}
