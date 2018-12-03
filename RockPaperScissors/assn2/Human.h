#pragma once
#include "Player.h"
#include "Guess.h"

#include <string>

using namespace std;

class Human : public Player
{
private:
	string name;										//Holds the name of the human player

public:
	Human();											//Default contructor
	~Human();											//Destructor
	Human(string name);									//string contructor - sets the name and the score of the human player
	

	Guess getGuess() const;								//getGuess method - returns the guess of the human player

	//getName (inline method) - returns the name of the human player
	string getName() const 
	{
		return name;
	}	
};

