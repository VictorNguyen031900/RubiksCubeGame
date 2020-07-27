#ifndef EVERYTHING_H
#define EVERYTHING_H

using namespace std;

class everything
{
private:
	struct element
	{
		char square1 = '[';
		char square2 = ']';
		int colorCode;
	};

	element front[3][3];
	element back[3][3];
	element right[3][3];
	element left[3][3];
	element top[3][3];
	element bottom[3][3];

public:
	void start();
	void display();
	void colorRender();
	void topRowRight();  //Turn
	void topRowLeft();  //Turn
	void bottomRowRight();  //Turn
	void bottomRowLeft();  //Turn
	void leftColumnUp();  //Turn
	void leftColumnDown();  //Turn
	void rightColumnUp();  //Turn
	void rightColumnDown();  //Turn
	void frontFaceRight();  //Turn
	void frontFaceLeft();  //Turn
	bool isSolved();
	void randomizer();
};
#endif