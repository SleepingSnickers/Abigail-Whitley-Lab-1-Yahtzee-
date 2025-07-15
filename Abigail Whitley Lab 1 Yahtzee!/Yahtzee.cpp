#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "ConsoleUI.h"
#include "Die.h"
#include "GameLogic.h"

using namespace std;

int main() {
	srand(time(0));

	GameLogic myGame;

	do {
		myGame.reset();
		myGame.playGame();
	} while (myGame.replay());

	return 0;
}