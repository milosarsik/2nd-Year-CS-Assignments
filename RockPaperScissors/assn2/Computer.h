#pragma once

#include "Player.h"
#include "Guess.h"

class Computer : public Player
{
public:
	Computer();											//Default constructor
	~Computer();										//Destructor

	Guess getGuess() const;								//getGuess method - creates an object of type Guess and returns it
};

