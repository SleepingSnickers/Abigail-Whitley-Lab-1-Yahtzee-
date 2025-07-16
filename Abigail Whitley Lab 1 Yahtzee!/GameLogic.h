#ifndef GAMELOGIC
#define GAMELOGIC
#include <iostream>
#include <string>

#include "Die.h"
#include "ConsoleUI.h"

using namespace std;

class GameLogic {
private:
	//array of 5 dice
	Die dice[5];
	//6 score categories
	int scorePositions[6];
	//allows the score categories to be used
	int usedScorePositions[6];
	//calls the ConsoleUI
	ConsoleUI ui;

public:
	//constructor
	GameLogic();
	//destructor
	~GameLogic();
	//function for the entire game
	void playGame();
	//function for just the round
	void playRound();
	//calculates category scores
	int calcScore(int);
	//calculates the total score
	int totalScore() const;
	//resets categories back to 0
	void reset();
	//replays the game
	bool replay();
};

#endif