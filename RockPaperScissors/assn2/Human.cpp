#include "Human.h"

#include <iostream>

using namespace std;

//Default constructor
Human::Human() 
{
}

//Destructor
Human::~Human()
{
}

//string constructor - sets the name of the member variable and creates a player object with score of 3 using initiliazation list
Human::Human(string name) : name(name), Player(3)
{
}

//getGuess method - prompts user for a guess and returns an object of type guess
Guess Human::getGuess() const
{
	char guess;

	cout << "Enter (R,P,S): ";
	cin >> guess;										//Prompts the user for a char and assigns it to guess			

	return Guess(guess);								//Calls char constructor in Guess to create an object of type Guess with a member variable of guess
}
