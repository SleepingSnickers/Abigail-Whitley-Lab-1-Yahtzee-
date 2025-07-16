#include <iostream>
#include <string>
#include "ConsoleUI.h"
#include "Die.h"

using namespace std;

//displays the face value of each of the 5 dice
void ConsoleUI::displayDice(Die* dice) {
	for (int i = 0; i < 5; i++) {
		cout << "Die " << i + 1 << ": " << dice[i].getFaceValue() << endl;
	}
}

//displays the current scores, and if a category has not been filled it declares that
void ConsoleUI::displayScores(const int scores[6], const int used[6]) {
	for (int i = 0; i < 6; i++) {
		if (used[i]) {
			cout << i + 1 << ": " << scores[i] << endl;
		}
		else cout << i + 1 << ": (available score)" << endl;
	}
}

//allows the user to choose which dice they want to keep
bool* ConsoleUI::keepDice() {
	bool keep[5];

	cout << "For each dice, enter 1 to keep, 0 to re-roll." << endl;

	for (int i = 0; i < 5; i++) {
		cin >> keep[i];
	}

	return keep;
}

//allows the user to add their current score to an empty category
int ConsoleUI::scoreCategory(const int used[6]) {
	int userChoice;

	do {
		cout << "Choose an empty category to add your score into: ";
		cin >> userChoice;
	} while (userChoice < 1 || userChoice > 6 || used[userChoice - 1]);

	return userChoice- 1;
}

//gives user the choice of playing again
int ConsoleUI::replay() {
	int userReplay;

	cout << "Would you like to play again? Yes (1) or No (2): " << endl;
	cin >> userReplay;

	return userReplay;
}

//displays the final score
void ConsoleUI::displayFinalScores(int total) {
	cout << "Final Score: " << total << endl;
}