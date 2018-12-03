#pragma once

class Player
{
private:
	int score;											//Holds the score of the player			

public:
	Player();											//Default constructor
	~Player();											//Destructor
	Player(int score);									//int constructor - takes an integer parameter


	int getScore() const;								//getScore method - returns the score

	Player &operator--();								//Decrement operator - decrements the score
};

