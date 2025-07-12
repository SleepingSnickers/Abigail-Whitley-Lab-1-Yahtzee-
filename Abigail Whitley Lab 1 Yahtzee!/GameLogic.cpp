#include <iostream>
#include <string>

#include "ConsoleUI.h"
#include "Die.h"
#include "GameLogic.h"

using namespace std;

GameLogic::GameLogic() : GameLogic(new Die[5], 5) {

}

GameLogic::GameLogic(Die* dicePtr, int size) {
	sizeOfHand = size;
	//allocating the memory for new dice
	dice = dicePtr;
}

GameLogic::~GameLogic() {
	delete[] dice;
}

void GameLogic::setDice(Die* dicePtr) {
	dice = dicePtr;
}

void GameLogic::setSizeOfHand(int size) {
	sizeOfHand = size;
}

Die* GameLogic::getDice() const {
	return dice;
}

int GameLogic::getSizeOfHand() const {
	return sizeOfHand;
}

//dieNum works the same as i in the previous for loop
void GameLogic::rollDie(int dieNum) {
	//if statement is used here because I'm only rolling a single die
	if (dieNum >= 0 && dieNum < sizeOfHand) {
		dice[dieNum].roll();
	}
}

void GameLogic::rollAllDice() {
	//for loop is used here because I'm rolling thru all of the dice in my hand
	for (int i = 0; i < sizeOfHand; i++) {
		dice[i].roll();
	}
}