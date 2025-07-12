#ifndef GAMELOGIC
#define GAMELOGIC
#include <iostream>
#include <string>

#include "Die.h"
#include "ConsoleUI.h"

using namespace std;

class GameLogic {
private:
	Die* dice;
	int sizeOfHand;
	int scores[6];
	int used[6];
	ConsoleUI ui;

public:
	//setters
	void setDice(Die* dicePtr);
	void setSizeOfHand(int size);

	//getters
	Die* getDice() const;
	int getSizeOfHand() const;

	//other
	void rollDie(int dieNum);
	void rollAllDice();
	GameLogic();
	GameLogic(Die*, int);
	~GameLogic();
};

#endif