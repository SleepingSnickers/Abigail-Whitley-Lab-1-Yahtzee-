#include <iostream>
#include <string>
#include "ConsoleUI.h"
#include "Die.h"
#include "GameLogic.h"

using namespace std;

void ConsoleUI::displayDie(Die* die) {
	cout << "A " << die->getNumberOfSides() << "-sided die showing " << die->getFaceValue() << endl;
}

void ConsoleUI::displayDice(Die* dice, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Die " << (i + 1) << ": ";
		displayDie(&dice[i]);
	}
}

int ConsoleUI::getUserChoice(string menu) {
	int choice;

	cout << menu << "Enter choice: " << endl;
	cin >> choice;

	return choice;
}