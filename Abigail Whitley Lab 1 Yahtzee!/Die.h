#ifndef DIE
#define DIE
#include <iostream>
#include <string>

using namespace std;

class Die {
private:
	const int numberOfSides;
	int faceValue;
public:
	//constructor
	Die();
	//setter
	void setFaceValue(int value);
	//getter
	int getFaceValue() const;
	//rolls the dice
	void roll();
};

#endif