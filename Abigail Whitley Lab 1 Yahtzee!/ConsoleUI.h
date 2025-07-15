#ifndef CONSOLEUI
#define CONSOLEUI
#include <iostream>
#include <string>

#include "Die.h"

using namespace std;

class ConsoleUI {
private:
	
public:
	void displayDice(Die*);
	void displayScores(const int[], const int[]);
	bool* keepDice();
	int scoreCategory(const int[]);
	int replay();
	void displayFinalScores(int);
};

#endif