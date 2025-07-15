#ifndef GAMELOGIC
#define GAMELOGIC
#include <iostream>
#include <string>

#include "Die.h"
#include "ConsoleUI.h"

using namespace std;

class GameLogic {
private:
	Die dice[5];
	int scorePositions[6];
	int usedScorePositions[6];
	ConsoleUI ui;

public:
	GameLogic();
	~GameLogic();
	void playGame();
	void playRound();
	int calcScore(int);
	int totalScore() const;
	void reset();
	bool replay();
};

#endif