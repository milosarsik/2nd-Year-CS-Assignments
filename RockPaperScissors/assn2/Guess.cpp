#include "Guess.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

//Default constructor - randomly assigns a guess to the guess member variable using rand
Guess::Guess()
{
	srand(time(NULL));
	
	Guess(rand()%3);									//Calls the third constructor
}

Guess::~Guess()
{
}

//char constructor - converts the char that is passed to an uppercase value  
Guess::Guess(char guess)
{
	if ((guess == 'R') | (guess == 'r'))				//R
	{
		this->guess = 'R';								//Set member varialbe guess to 'R'
	}
	else if ((guess == 'P') | (guess == 'p'))			//P
	{
		this->guess = 'P';								//Set member variable guess to 'P'
	}
	else												//S
	{
		this->guess = 'S';								//Set member variable guess to 'S'
	}
}

//int constructor - takes in an int value and assigns a char to guess member variable based on the integer passed
Guess::Guess(int guess)
{
	if (guess == 0)										//If passed integer is 0
	{
		this->guess = 'R';								//Set member variable to 'R'
	}
	else if (guess == 1)								//If passed integer is 
	{
		this->guess = 'P';								//Set member variable to 'P'
	}
	else												//If passed integer is anything else
	{
		this->guess = 'S';								//Set member variable to 'S'
	}

}

//compare method - compares the guesses to see if the round is a win, loss or tie
int Guess::compare(const Guess &other) const
{
	if (this->guess == other.guess) 
	{
		return 0;
	}
	else if (((this->guess == 'S') && (other.guess == 'R')) || ((this->guess == 'R') && (other.guess == 'P')) || ((this->guess == 'P') && (other.guess == 'S')))
	{
		return 1;
	}
	else if (((this->guess == 'R') && (other.guess == 'S')) || ((this->guess == 'P') && (other.guess == 'R')) || ((this->guess == 'S') && (other.guess == 'P')))
	{
		return -1;
	}
}

