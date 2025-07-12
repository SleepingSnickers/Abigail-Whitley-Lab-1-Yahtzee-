#include <iostream>
#include <string>
#include "Die.h"

using namespace std;

Die::Die() : numberOfSides(6) { faceValue = 1; };

void Die::setFaceValue(int value) {
	faceValue = value;
}

int Die::getFaceValue() const {
	return faceValue;
}

void Die::roll() {
	faceValue = rand() % numberOfSides + 1;
}