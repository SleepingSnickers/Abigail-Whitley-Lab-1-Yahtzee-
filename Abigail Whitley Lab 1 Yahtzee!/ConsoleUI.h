#ifndef CONSOLEUI
#define CONSOLEUI
#include <iostream>
#include <string>

using namespace std;

class ConsoleUI {
private:
	
public:
	void displayDie(Die* die);
	void displayDice(Die* dice, int size);
	int getUserChoice(string menu);

};

#endif