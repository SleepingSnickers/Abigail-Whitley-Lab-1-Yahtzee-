#include <iostream>
#include <string>

#include "ConsoleUI.h"
#include "Die.h"
#include "GameLogic.h"

using namespace std;

GameLogic::GameLogic() {
	for (int i = 0; i < 6; i++) {
		scorePositions[i] = 0;
		usedScorePositions[i] = 0;
	}
}

GameLogic::~GameLogic() {
	/*for (int i = 0; i < 5; i++) {
		delete[] dice;
	}*/
}

void GameLogic::playGame() {
	for (int rounds = 0; rounds < 6; rounds++) {
		playRound();
	}
	ui.displayFinalScores(totalScore());
}

void GameLogic::playRound() {
	for (int i = 0; i < 5; i++) {
		dice[i].roll();
	}

	for (int rolls = 1; rolls < 3; rolls++) {
		ui.displayDice(dice);

		bool* keep = ui.keepDice();
		for (int i = 0; i < 5; i++) {
			if (!keep[i]) {
				dice[i].roll();
			}
		}
	}
	ui.displayDice(dice);
	ui.displayScores(scorePositions, usedScorePositions);

	int category = ui.scoreCategory(usedScorePositions);
	scorePositions[category] = calcScore(category);
	usedScorePositions[category] = 1;
}

int GameLogic::calcScore(int category) {
	int catTotal = 0;

	for (int i = 0; i < 5; i++) {
		if (dice[i].getFaceValue() == category + 1) {
			catTotal += dice[i].getFaceValue();
		}
	}
	return catTotal;
}

int GameLogic::totalScore() const {
	int scoreTotal = 0;

	for (int i = 0; i < 6; i++) {
		scoreTotal += scorePositions[i];
	}

	return scoreTotal;
}

void GameLogic::reset() {
	for (int i = 0; i < 6; i++) {
		scorePositions[i] = 0;
		usedScorePositions[i] = 0;
	}
}

bool GameLogic::replay() {
	int choice = ui.replay();
	return choice == 1;
}