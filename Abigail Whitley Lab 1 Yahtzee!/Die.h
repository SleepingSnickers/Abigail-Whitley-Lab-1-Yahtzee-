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
	//setters
	void setFaceValue(int value);
	//getters
	int getFaceValue() const;
	//others
	//roll() method
	void roll();
	//default constructor
	Die();
};

#endif