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
	Die();
	void setFaceValue(int value);
	int getFaceValue() const;
	void roll();
};

#endif