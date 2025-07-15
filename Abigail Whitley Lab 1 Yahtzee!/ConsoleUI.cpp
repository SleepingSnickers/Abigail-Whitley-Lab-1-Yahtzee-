#include <iostream>
#include <string>
#include "ConsoleUI.h"
#include "Die.h"

using namespace std;

void ConsoleUI::displayDice(Die* dice) {
	for (int i = 0; i < 5; i++) {
		cout << "Die " << i + 1 << ": " << dice[i].getFaceValue() << endl;
	}
}

void ConsoleUI::displayScores(const int scores[6], const int used[6]) {
	for (int i = 0; i < 6; i++) {
		if (used[i]) {
			cout << i + 1 << ": " << scores[i] << endl;
		}
		else cout << i + 1 << ": (available score)" << endl;
	}
}

bool* ConsoleUI::keepDice() {
	bool keep[5];

	cout << "For each dice, enter 1 to keep, 0 to re-roll." << endl;

	for (int i = 0; i < 5; i++) {
		cin >> keep[i];
	}

	return keep;
}

int ConsoleUI::scoreCategory(const int used[6]) {
	int userChoice;

	do {
		cout << "Choose an empty category to add your score into: ";
		cin >> userChoice;
	} while (userChoice < 1 || userChoice > 6 || used[userChoice - 1]);

	return userChoice- 1;
}

int ConsoleUI::replay() {
	int userReplay;

	cout << "Would you like to play again? Yes (1) or No (2): " << endl;
	cin >> userReplay;

	return userReplay;
}

void ConsoleUI::displayFinalScores(int total) {
	cout << "Final Score: " << total << endl;
}