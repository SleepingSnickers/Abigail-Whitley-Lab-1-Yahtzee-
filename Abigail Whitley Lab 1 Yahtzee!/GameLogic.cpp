#include <iostream>
#include <string>

#include "ConsoleUI.h"
#include "Die.h"
#include "GameLogic.h"

using namespace std;

//constructor setting each of the score slots to a value of 0 points
GameLogic::GameLogic() {
	for (int i = 0; i < 6; i++) {
		scorePositions[i] = 0;
		usedScorePositions[i] = 0;
	}
}

//destructor, doesn't really have a point but I wanted to add it
GameLogic::~GameLogic() {
	
}

//rotates through 6 rounds (the amount of score slots available)
void GameLogic::playGame() {
	for (int rounds = 0; rounds < 6; rounds++) {
		playRound();
	}
	//calls the user interface to show what the total is
	ui.displayFinalScores(totalScore());
}

//the logic for each individual round of the game
void GameLogic::playRound() {
	//rolls each of the 5 dice
	for (int i = 0; i < 5; i++) {
		dice[i].roll();
	}

	//user is allowed to roll 3 times before round is over
	for (int rolls = 1; rolls < 3; rolls++) {
		//displays each roll
		ui.displayDice(dice);

		//allows user to keep their wanted dice
		bool* keep = ui.keepDice();
		for (int i = 0; i < 5; i++) {
			//rerolls the unwanted dice
			if (!keep[i]) {
				dice[i].roll();
			}
		}
	}
	//displays the final round of kept dice
	ui.displayDice(dice);
	//shows the used/unused score slots
	ui.displayScores(scorePositions, usedScorePositions);
	
	int category = ui.scoreCategory(usedScorePositions);
	scorePositions[category] = calcScore(category);
	usedScorePositions[category] = 1;
}

//calculates the user's score for the round
int GameLogic::calcScore(int category) {
	int catTotal = 0;

	//the category in this case is each of the score slots, the value of the matching die is added. Only die with a face value matching the chosen score category will be added
	for (int i = 0; i < 5; i++) {
		if (dice[i].getFaceValue() == category + 1) {
			catTotal += dice[i].getFaceValue();
		}
	}
	return catTotal;
}

//calculates the score for the entire game
int GameLogic::totalScore() const {
	int scoreTotal = 0;

	//each score category gets added into the overall total
	for (int i = 0; i < 6; i++) {
		scoreTotal += scorePositions[i];
	}

	return scoreTotal;
}

//resets the score slots back to 0, allowing the game to restart
void GameLogic::reset() {
	for (int i = 0; i < 6; i++) {
		scorePositions[i] = 0;
		usedScorePositions[i] = 0;
	}
}

//initiates the replay of the game if the user chooses
bool GameLogic::replay() {
	int choice = ui.replay();
	return choice == 1;
}