#include <iostream>
#include <string>
#include "ConsoleUI.h"
#include "Die.h"
#include "GameLogic.h"

using namespace std;

Die::Die() {
	numberOfSides = 6;
	faceValue = 6;
}
Die::Die(int sides, int value) : numberOfSides(sides), faceValue(value) {
}

void Die::setNumberOfSides(int sides) {
	numberOfSides = sides;
}
void Die::setFaceValue(int value) {
	faceValue = value;
}
int Die::getNumberOfSides() const {
	return numberOfSides;
}
int Die::getFaceValue() const {
	return faceValue;
}
void Die::roll() {
	faceValue = rand() % numberOfSides + 1;
}
string Die::displayDie() const {
	return
		"A " + to_string(numberOfSides) + "-sided die showing " + to_string(faceValue) + ".";
}