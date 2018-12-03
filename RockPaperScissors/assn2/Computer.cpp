#include "Computer.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

//Default constructor
Computer::Computer() : Player(5)
{
}

//Destructor
Computer::~Computer()
{
}

//getGuess method - assigns a random integer and creates an object of type Guss with a random value between 0 and 2
Guess Computer::getGuess() const
{
	srand(time(NULL));

	return Guess(rand()%3);							
}
