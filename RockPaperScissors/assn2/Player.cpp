#include "Player.h"

//Default constructor
Player::Player()
{
}

//Destructor
Player::~Player()
{
}

//int constructor - takes an integer parameter and assigns it to the member variable score
Player::Player(int score)
{
	this->score = score;								//Sets member variable score to the value of the passed parameter
}

//getScore method - returns the member variable score
int Player::getScore() const
{
	return score;
}

//Decrement operator method - decrements the score and returns the player
Player& Player::operator--( )
{
	score--;											//Decrements the member variable score
	Player temp(score);									//Creates a temporary player with a score

	return temp;
}