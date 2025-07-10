#ifndef DIE
#define DIE
#include <iostream>
#include <string>

using namespace std;

class Die {
private:
	int numberOfSides;
	int faceValue;
public:
	//setters
	void setNumberOfSides(int sides);
	void setFaceValue(int value);
	//getters
	int getNumberOfSides() const;
	int getFaceValue() const;
	//others
	//roll() method
	void roll();
	//method that returns a string describing the Die object
	string displayDie() const;
	//prototype for the constructor
	Die();
	Die(int sides, int value);
};

#endif