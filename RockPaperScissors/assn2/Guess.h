#pragma once

class Guess
{
private:
	char guess;											//Holds 'R', 'P' or 'S' as a char 

public:
	Guess();											//Default constructor
	~Guess();											//Destructor
	Guess(char guess);									//char contructor - takes in a char parameter
	Guess(int integer);									//int constructor - takes in an int parameter

	int compare(const Guess &other) const;	//compare method - compares the guess member variable

	//getGuess (inline method) - returns the guess member variable
	char getGuess()
	{
		return guess;
	}
};

