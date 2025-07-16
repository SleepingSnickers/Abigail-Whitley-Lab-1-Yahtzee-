#include <iostream>
#include <string>
#include "Die.h"

using namespace std;

//default constructor
Die::Die() : numberOfSides(6) { faceValue = 1; };

//setter for the face value of the die
void Die::setFaceValue(int value) {
	faceValue = value;
}

//getter for the face value of the die
int Die::getFaceValue() const {
	return faceValue;
}

//rolls the die to a random number between 1 and the highest face value
void Die::roll() {
	faceValue = rand() % numberOfSides + 1;
}