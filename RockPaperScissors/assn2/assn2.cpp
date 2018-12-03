#include <iostream>
#include <string>

#include "Player.h"
#include "Computer.h"
#include "Human.h"
#include "Guess.h"

using namespace std;

int main(int argc, char *argv[])
{
	//Varaibles 
	string playerName;

	//Prompts the user for a player name
	cout << "Player name: ";
	cin >> playerName;

	//Creating human and computer players
	Human humanOne(playerName);
	Computer computerOne; 

	//Creating objects of type guess and assigning guesses of the human and the computer
	Guess humanGuess(humanOne.getGuess());
	Guess computerGuess(computerOne.getGuess());

	while ((humanOne.getScore() != 0) && (computerOne.getScore() != 0))				//while loop to keep updating the guesses and the scores
	{
		cout << "Human: " << humanGuess.getGuess() << " Computer: " << computerGuess.getGuess() << endl;		//Outputting guesses of each

		if ((humanGuess.compare(computerGuess)) == 0)								//Tie
		{
		}
		else if ((humanGuess.compare(computerGuess)) == 1)							//Computer wins
		{
			computerOne.operator--();
		}
		else if ((humanGuess.compare(computerGuess)) == -1)							//Human wins
		{
			humanOne.operator--();
		}
		else
		{
		}

		cout << "Human: " << humanOne.getScore() << " Computer: " << computerOne.getScore() << endl;			//Outputting the scores of each

		if (humanOne.getScore() == 0)												//Human wins output
		{
			cout << playerName <<" WON!!!" << endl;
			break;
		}
		else if (computerOne.getScore() == 0)										//Computer wins output
		{
			cout << "Computer WON!!!" << endl;
		}
		else
		{
		}

		humanGuess = humanOne.getGuess();
		computerGuess = computerOne.getGuess();
	}

	//Keeping the window open by asking for user input
	char inputChar;
	cin >> inputChar;
}