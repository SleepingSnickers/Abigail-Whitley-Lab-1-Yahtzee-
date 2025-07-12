#ifndef CONSOLEUI
#define CONSOLEUI
#include <iostream>
#include <string>

using namespace std;

class ConsoleUI {
private:
	
public:
	void displayDice(Die*);
	void displayScore(const int, const int);
	bool* keepDice();
	int scoreCategory(const int);
	int replay();
};

#endif