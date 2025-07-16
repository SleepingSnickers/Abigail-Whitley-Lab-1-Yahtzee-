#ifndef CONSOLEUI
#define CONSOLEUI
#include <iostream>
#include <string>

#include "Die.h"

using namespace std;

class ConsoleUI {
private:
	//no private variables are needed
public:
	//displays the dice
	void displayDice(Die*);
	//displays the scores
	void displayScores(const int[], const int[]);
	//prompts user to keep the dice
	bool* keepDice();
	//prompts user to select a score category
	int scoreCategory(const int[]);
	//prompts user to replay
	int replay();
	//displays the final score of the game
	void displayFinalScores(int);
};

#endif