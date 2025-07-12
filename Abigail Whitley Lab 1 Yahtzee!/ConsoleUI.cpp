#include <iostream>
#include <string>
#include "ConsoleUI.h"
#include "Die.h"
#include "GameLogic.h"

using namespace std;

void ConsoleUI::displayDice(Die* dice) {
	for (int i = 0; i < 5; i++) {
		cout << "Die " << (i + 1) << ": " << dice[i].getFaceValue() << endl;
	}
}

void ConsoleUI::displayScore(const int scores[6], const int used[6]) {
	for (int i = 0; i < 6; i++) {
		if (used[i]) {
			cout << i + 1 << ": " << scores[i] << endl;
		}
		else {
			cout << i + 1 << ": " << endl;
		}
	}
}

bool* ConsoleUI::keepDice() {
	static bool choice[5];

	cout << "(1) to keed the die, (0) to re-roll: " << endl;
	for (int i = 0; i < 5; i++) {
		cin >> choice[i];
	}

	return choice;
}

int ConsoleUI::scoreCategory(const int used[6]) {
	int choice;

	do {
		cout << "Choose the category (1 - 6) to store your score (empty categories only): " << endl;
		cin >> choice;
	} while (choice < 1 || choice > 6 || used[choice - 1]);

	return choice - 1;
}

int ConsoleUI::replay() {
	int input;

	cout << "Would you like to play again? No (1) or Yes (2): " << endl;
	cin >> input;

	return input == 2;
}