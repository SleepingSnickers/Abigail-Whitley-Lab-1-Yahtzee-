#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "ConsoleUI.h"
#include "Die.h"
#include "GameLogic.h"

using namespace std;

int main() {
	//seeds the random dice rolls
	srand(time(0));

	//instantiates the game
	GameLogic myGame;

	//do while loop to allow the replay system to work
	do {
		myGame.reset();
		myGame.playGame();
	} while (myGame.replay());

	return 0;
}