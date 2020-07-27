#include "Everything.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <Windows.h>
#include <string>
#include <time.h>

using namespace std;

void everything::start()
{
	int choice;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			front[i][j].colorCode = 1; // 10 Color Code for Green
			back[i][j].colorCode = 2; // 9 Color Code for Blue
			right[i][j].colorCode = 3; // 4 Color Code for Red
			left[i][j].colorCode = 4; // 6 Color Code for Orange
			top[i][j].colorCode = 5; // 15 Color Code for White
			bottom[i][j].colorCode = 6; // 14 Color Code for Yellow
		}
	}

	do {
		system("cls");
		display();
		cout << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //Baby BLue
		cout << "Show me your moves!" << endl;
		cout << "1. Turn top row right." << "      2. Turn top row left." << "           3. Turn bottom row right." << endl;
		cout << "4. Turn bottom row left." << "    5. Turn left column up." << "         6. Turn left column down." << endl;
		cout << "7. Turn right column up." << "    8. Turn right column down." << "      9. Turn front face right." << endl;
		cout << "10. Turn front face left." << "   11. Randomize." << "                  12. Quit." << endl;
		cout << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27); //Blue Background, Baby Blue text
		cout << "Choice: ";
		cin >> choice;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
		switch (choice)
		{
		case 1:
			topRowRight();
			break;
		case 2:
			topRowLeft();
			break;
		case 3:
			bottomRowRight();
			break;
		case 4:
			bottomRowLeft();
			break;
		case 5:
			leftColumnUp();
			break;
		case 6:
			leftColumnDown();
			break;
		case 7:
			rightColumnUp();
			break;
		case 8:
			rightColumnDown();
			break; 
		case 9:
			frontFaceRight();
			break;
		case 10:
			frontFaceLeft();
			break;
		case 11:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 207); //Red BackGround and White text
			cout << endl << "Randomizing!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			Sleep(500);
			randomizer();
			break;
		case 12:
			cout << "Damn what a quiter..." << endl;
			break;
		default:
			cout << "Pick a choice 1-12!" << endl;
			Sleep(500);
			break;
		}
	} while ((isSolved() == false) && (choice != 12));
}

bool everything::isSolved()
{
	return false;
}

void everything::randomizer()
{
	int choice;

	srand(time(NULL));

	for (int i = 0; i < 100; i++)
	{
		choice = rand() % 10 + 1;
		if (choice == 1)
		{
			topRowRight();
		}
		else if (choice == 2)
		{
			topRowLeft();
		}
		else if (choice == 3)
		{
			bottomRowRight();
		}
		else if (choice == 4)
		{
			bottomRowLeft();
		}
		else if (choice == 5)
		{
			leftColumnUp();
		}
		else if (choice == 6)
		{
			leftColumnDown();
		}
		else if (choice == 7)
		{
			rightColumnUp();
		}
		else if (choice == 8)
		{
			rightColumnDown();
		}
		else if (choice == 9)
		{
			frontFaceRight();
		}
		else if (choice == 10)
		{
			frontFaceLeft();
		}
	}
}

void everything::display()
{
	colorRender();
}

void everything::colorRender()
{
	for (int i = 0; i < 3; i++) //TOP
	{
		cout << "         ";
		for (int j = 0; j < 3; j++)
		{
			if (top[i][j].colorCode == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Green
				cout << top[i][j].square1 << top[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (top[i][j].colorCode == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Blue
				cout << top[i][j].square1 << top[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (top[i][j].colorCode == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Red
				cout << top[i][j].square1 << top[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (top[i][j].colorCode == 4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); //Orange
				cout << top[i][j].square1 << top[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (top[i][j].colorCode == 5)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
				cout << top[i][j].square1 << top[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (top[i][j].colorCode == 6)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //Yellow
				cout << top[i][j].square1 << top[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
		}
			cout << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) //LEFT
		{
			if (left[i][j].colorCode == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Green
				cout << left[i][j].square1 << left[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (left[i][j].colorCode == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Blue
				cout << left[i][j].square1 << left[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (left[i][j].colorCode == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Red
				cout << left[i][j].square1 << left[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (left[i][j].colorCode == 4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); //Orange
				cout << left[i][j].square1 << left[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (left[i][j].colorCode == 5)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
				cout << left[i][j].square1 << left[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (left[i][j].colorCode == 6)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //Yellow
				cout << left[i][j].square1 << left[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
		}

		for (int j = 0; j < 3; j++) //FRONT
		{
			if (front[i][j].colorCode == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Green
				cout << front[i][j].square1 << front[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (front[i][j].colorCode == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Blue
				cout << front[i][j].square1 << front[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (front[i][j].colorCode == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Red
				cout << front[i][j].square1 << front[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (front[i][j].colorCode == 4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); //Orange
				cout << front[i][j].square1 << front[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (front[i][j].colorCode == 5)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
				cout << front[i][j].square1 << front[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (front[i][j].colorCode == 6)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //Yellow
				cout << front[i][j].square1 << front[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
		}

		for (int j = 0; j < 3; j++) //RIGHT
		{
			if (right[i][j].colorCode == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Green
				cout << right[i][j].square1 << right[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (right[i][j].colorCode == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Blue
				cout << right[i][j].square1 << right[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (right[i][j].colorCode == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Red
				cout << right[i][j].square1 << right[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (right[i][j].colorCode == 4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); //Orange
				cout << right[i][j].square1 << right[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (right[i][j].colorCode == 5)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
				cout << right[i][j].square1 << right[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (right[i][j].colorCode == 6)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //Yellow
				cout << right[i][j].square1 << right[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
		}

		for (int j = 0; j < 3; j++) //BACK
		{
			if (back[i][j].colorCode == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Green
				cout << back[i][j].square1 << back[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (back[i][j].colorCode == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Blue
				cout << back[i][j].square1 << back[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (back[i][j].colorCode == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Red
				cout << back[i][j].square1 << back[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (back[i][j].colorCode == 4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); //Orange
				cout << back[i][j].square1 << back[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (back[i][j].colorCode == 5)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
				cout << back[i][j].square1 << back[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (back[i][j].colorCode == 6)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //Yellow
				cout << back[i][j].square1 << back[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
		}
		cout << endl;
	}
	
	for (int i = 0; i < 3; i++) //BOTTOM
	{
		cout << "         ";
		for (int j = 0; j < 3; j++)
		{
			if (bottom[i][j].colorCode == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Green
				cout << bottom[i][j].square1 << bottom[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (bottom[i][j].colorCode == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Blue
				cout << bottom[i][j].square1 << bottom[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (bottom[i][j].colorCode == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Red
				cout << bottom[i][j].square1 << bottom[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (bottom[i][j].colorCode == 4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); //Orange
				cout << bottom[i][j].square1 << bottom[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (bottom[i][j].colorCode == 5)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
				cout << bottom[i][j].square1 << bottom[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
			else if (bottom[i][j].colorCode == 6)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //Yellow
				cout << bottom[i][j].square1 << bottom[i][j].square2 << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //White
			}
		}
		cout << endl;
	}
}

//      top
//left front right back
//     bottom

void everything::topRowRight() //WORKS
{
	int temp1, temp2, temp3; //Used to hold three array elements at a time
	// 00 01 02 // 02 12 22 // 
	// 10 11 12 // 01 11 21 // How top array "spins"
	// 20 21 22 // 00 10 20 // 
	//Side Turns
	temp1 = top[0][1].colorCode;
	top[0][1].colorCode = top[1][2].colorCode;
	top[1][2].colorCode = top[2][1].colorCode;
	top[2][1].colorCode = top[1][0].colorCode;
	top[1][0].colorCode = temp1;
	//Corner Turns
	temp1 = top[0][2].colorCode;
	top[0][2].colorCode = top[2][2].colorCode;
	top[2][2].colorCode = top[2][0].colorCode;
	top[2][0].colorCode = top[0][0].colorCode;
	top[0][0].colorCode = temp1;

	//Left Front Right Back upper rows turn to the right
	temp1 = left[0][0].colorCode;
	temp2 = left[0][1].colorCode;
	temp3 = left[0][2].colorCode;
	left[0][0].colorCode = back[0][0].colorCode;
	left[0][1].colorCode = back[0][1].colorCode;
	left[0][2].colorCode = back[0][2].colorCode;
	back[0][0].colorCode = right[0][0].colorCode;
	back[0][1].colorCode = right[0][1].colorCode;
	back[0][2].colorCode = right[0][2].colorCode;
	right[0][0].colorCode = front[0][0].colorCode;
	right[0][1].colorCode = front[0][1].colorCode;
	right[0][2].colorCode = front[0][2].colorCode;
	front[0][0].colorCode = temp1;
	front[0][1].colorCode = temp2;
	front[0][2].colorCode = temp3;
}

void everything::topRowLeft()
{
	int temp1, temp2, temp3; //Used to hold three array elements at a time
	// 00 01 02 // 20 10 00 // 
	// 10 11 12 // 21 11 01 // How top array "spins"
	// 20 21 22 // 22 12 02//
	//Side Turns
	temp1 = top[0][1].colorCode;
	top[0][1].colorCode = top[1][0].colorCode;
	top[1][0].colorCode = top[2][1].colorCode;
	top[2][1].colorCode = top[1][2].colorCode;
	top[1][2].colorCode = temp1;
	//Corner Turns
	temp1 = top[0][2].colorCode;
	top[0][2].colorCode = top[0][0].colorCode;
	top[0][0].colorCode = top[2][0].colorCode;
	top[2][0].colorCode = top[2][2].colorCode;
	top[2][2].colorCode = temp1;

	//Left Front Right Back upper rows turn to the left
	temp1 = left[0][0].colorCode;
	temp2 = left[0][1].colorCode;
	temp3 = left[0][2].colorCode;
	left[0][0].colorCode = front[0][0].colorCode;
	left[0][1].colorCode = front[0][1].colorCode;
	left[0][2].colorCode = front[0][2].colorCode;
	front[0][0].colorCode = right[0][0].colorCode;
	front[0][1].colorCode = right[0][1].colorCode;
	front[0][2].colorCode = right[0][2].colorCode;
	right[0][0].colorCode = back[0][0].colorCode;
	right[0][1].colorCode = back[0][1].colorCode;
	right[0][2].colorCode = back[0][2].colorCode;
	back[0][0].colorCode = temp1;
	back[0][1].colorCode = temp2;
	back[0][2].colorCode = temp3;
}

void everything::bottomRowRight()
{
	int temp1, temp2, temp3; //Used to hold three array elements at a time
	//Side Turns
	temp1 = bottom[0][1].colorCode;
	bottom[0][1].colorCode = bottom[1][0].colorCode;
	bottom[1][0].colorCode = bottom[2][1].colorCode;
	bottom[2][1].colorCode = bottom[1][2].colorCode;
	bottom[1][2].colorCode = temp1;
	//Corner Turns
	temp1 = bottom[0][2].colorCode;
	bottom[0][2].colorCode = bottom[0][0].colorCode;
	bottom[0][0].colorCode = bottom[2][0].colorCode;
	bottom[2][0].colorCode = bottom[2][2].colorCode;
	bottom[2][2].colorCode = temp1;

	//Left Front Right Back upper rows turn to the right
	temp1 = left[2][0].colorCode;
	temp2 = left[2][1].colorCode;
	temp3 = left[2][2].colorCode;
	left[2][0].colorCode = back[2][0].colorCode;
	left[2][1].colorCode = back[2][1].colorCode;
	left[2][2].colorCode = back[2][2].colorCode;
	back[2][0].colorCode = right[2][0].colorCode;
	back[2][1].colorCode = right[2][1].colorCode;
	back[2][2].colorCode = right[2][2].colorCode;
	right[2][0].colorCode = front[2][0].colorCode;
	right[2][1].colorCode = front[2][1].colorCode;
	right[2][2].colorCode = front[2][2].colorCode;
	front[2][0].colorCode = temp1;
	front[2][1].colorCode = temp2;
	front[2][2].colorCode = temp3;
}

void everything::bottomRowLeft()
{
	int temp1, temp2, temp3; //Used to hold three array elements at a time
	//Side Turns
	temp1 = bottom[0][1].colorCode;
	bottom[0][1].colorCode = bottom[1][2].colorCode;
	bottom[1][2].colorCode = bottom[2][1].colorCode;
	bottom[2][1].colorCode = bottom[1][0].colorCode;
	bottom[1][0].colorCode = temp1;
	//Corner Turns
	temp1 = bottom[0][2].colorCode;
	bottom[0][2].colorCode = bottom[2][2].colorCode;
	bottom[2][2].colorCode = bottom[2][0].colorCode;
	bottom[2][0].colorCode = bottom[0][0].colorCode;
	bottom[0][0].colorCode = temp1;

	//Left Front Right Back upper rows turn to the left
	temp1 = left[2][0].colorCode;
	temp2 = left[2][1].colorCode;
	temp3 = left[2][2].colorCode;
	left[2][0].colorCode = front[2][0].colorCode;
	left[2][1].colorCode = front[2][1].colorCode;
	left[2][2].colorCode = front[2][2].colorCode;
	front[2][0].colorCode = right[2][0].colorCode;
	front[2][1].colorCode = right[2][1].colorCode;
	front[2][2].colorCode = right[2][2].colorCode;
	right[2][0].colorCode = back[2][0].colorCode;
	right[2][1].colorCode = back[2][1].colorCode;
	right[2][2].colorCode = back[2][2].colorCode;
	back[2][0].colorCode = temp1;
	back[2][1].colorCode = temp2;
	back[2][2].colorCode = temp3;
}

void everything::leftColumnUp()
{ 
	int temp1, temp2, temp3; //Used to hold three array elements at a time
	//Side Turns
	temp1 = left[0][1].colorCode;
	left[0][1].colorCode = left[1][2].colorCode;
	left[1][2].colorCode = left[2][1].colorCode;
	left[2][1].colorCode = left[1][0].colorCode;
	left[1][0].colorCode = temp1;
	//Corner Turns
	temp1 = left[0][2].colorCode;
	left[0][2].colorCode = left[2][2].colorCode;
	left[2][2].colorCode = left[2][0].colorCode;
	left[2][0].colorCode = left[0][0].colorCode;
	left[0][0].colorCode = temp1;

	//Left Column
	temp1 = top[0][0].colorCode;
	temp2 = top[1][0].colorCode;
	temp3 = top[2][0].colorCode;
	top[0][0].colorCode = front[0][0].colorCode;
	top[1][0].colorCode = front[1][0].colorCode;
	top[2][0].colorCode = front[2][0].colorCode;
	front[0][0].colorCode = bottom[0][0].colorCode;
	front[1][0].colorCode = bottom[1][0].colorCode;
	front[2][0].colorCode = bottom[2][0].colorCode;
	bottom[0][0].colorCode = back[0][2].colorCode;
	bottom[1][0].colorCode = back[1][2].colorCode;
	bottom[2][0].colorCode = back[2][2].colorCode;
	back[0][2].colorCode = temp1;
	back[1][2].colorCode = temp2;
	back[2][2].colorCode = temp3;
}

void everything::leftColumnDown()
{
	int temp1, temp2, temp3;
	//Side Turns
	temp1 = left[0][1].colorCode;
	left[0][1].colorCode = left[1][0].colorCode;
	left[1][0].colorCode = left[2][1].colorCode;
	left[2][1].colorCode = left[1][2].colorCode;
	left[1][2].colorCode = temp1;
	//Corner Turns
	temp1 = left[0][2].colorCode;
	left[0][2].colorCode = left[0][0].colorCode;
	left[0][0].colorCode = left[2][0].colorCode;
	left[2][0].colorCode = left[2][2].colorCode;
	left[2][2].colorCode = temp1;

	//Left Column
	temp1 = top[0][0].colorCode;
	temp2 = top[1][0].colorCode;
	temp3 = top[2][0].colorCode;
	top[0][0].colorCode = back[0][2].colorCode;
	top[1][0].colorCode = back[1][2].colorCode;
	top[2][0].colorCode = back[2][2].colorCode;
	back[0][2].colorCode = bottom[0][0].colorCode;
	back[1][2].colorCode = bottom[1][0].colorCode;
	back[2][2].colorCode = bottom[2][0].colorCode;
	bottom[0][0].colorCode = front[0][0].colorCode;
	bottom[1][0].colorCode = front[1][0].colorCode;
	bottom[2][0].colorCode = front[2][0].colorCode;
	front[0][0].colorCode = temp1;
	front[1][0].colorCode = temp2;
	front[2][0].colorCode = temp3;
}

void everything::rightColumnUp()
{
	int temp1, temp2, temp3;
	//Side Turns
	temp1 = right[0][1].colorCode;
	right[0][1].colorCode = right[1][0].colorCode;
	right[1][0].colorCode = right[2][1].colorCode;
	right[2][1].colorCode = right[1][2].colorCode;
	right[1][2].colorCode = temp1;
	//Corner Turns
	temp1 = right[0][2].colorCode;
	right[0][2].colorCode = right[0][0].colorCode;
	right[0][0].colorCode = right[2][0].colorCode;
	right[2][0].colorCode = right[2][2].colorCode;
	right[2][2].colorCode = temp1;

	//Right Column
	temp1 = top[0][2].colorCode;
	temp2 = top[1][2].colorCode;
	temp3 = top[2][2].colorCode;
	top[0][2].colorCode = front[0][2].colorCode;
	top[1][2].colorCode = front[1][2].colorCode;
	top[2][2].colorCode = front[2][2].colorCode;
	front[0][2].colorCode = bottom[0][2].colorCode;
	front[1][2].colorCode = bottom[1][2].colorCode;
	front[2][2].colorCode = bottom[2][2].colorCode;
	bottom[0][2].colorCode = back[0][0].colorCode;
	bottom[1][2].colorCode = back[1][0].colorCode;
	bottom[2][2].colorCode = back[2][0].colorCode;
	back[0][0].colorCode = temp1;
	back[1][0].colorCode = temp2;
	back[2][0].colorCode = temp3;
}

void everything::rightColumnDown()
{
	int temp1, temp2, temp3; //Used to hold three array elements at a time
	//Side Turns
	temp1 = right[0][1].colorCode;
	right[0][1].colorCode = right[1][2].colorCode;
	right[1][2].colorCode = right[2][1].colorCode;
	right[2][1].colorCode = right[1][0].colorCode;
	right[1][0].colorCode = temp1;
	//Corner Turns
	temp1 = right[0][2].colorCode;
	right[0][2].colorCode = right[2][2].colorCode;
	right[2][2].colorCode = right[2][0].colorCode;
	right[2][0].colorCode = right[0][0].colorCode;
	right[0][0].colorCode = temp1;

	//Left Column
	temp1 = top[0][2].colorCode;
	temp2 = top[1][2].colorCode;
	temp3 = top[2][2].colorCode;
	top[0][2].colorCode = back[0][0].colorCode;
	top[1][2].colorCode = back[1][0].colorCode;
	top[2][2].colorCode = back[2][0].colorCode;
	back[0][0].colorCode = bottom[0][2].colorCode;
	back[1][0].colorCode = bottom[1][2].colorCode;
	back[2][0].colorCode = bottom[2][2].colorCode;
	bottom[0][2].colorCode = front[0][2].colorCode;
	bottom[1][2].colorCode = front[1][2].colorCode;
	bottom[2][2].colorCode = front[2][2].colorCode;
	front[0][2].colorCode = temp1;
	front[1][2].colorCode = temp2;
	front[2][2].colorCode = temp3;
}

void everything::frontFaceRight()
{
	int temp1;
	//Side Turns
	temp1 = front[0][1].colorCode;
	front[0][1].colorCode = front[1][0].colorCode;
	front[1][0].colorCode = front[2][1].colorCode;
	front[2][1].colorCode = front[1][2].colorCode;
	front[1][2].colorCode = temp1;
	//Corner Turns
	temp1 = front[0][2].colorCode;
	front[0][2].colorCode = front[0][0].colorCode;
	front[0][0].colorCode = front[2][0].colorCode;
	front[2][0].colorCode = front[2][2].colorCode;
	front[2][2].colorCode = temp1;
}

void everything::frontFaceLeft()
{
	int temp1;
	//Side Turns
	temp1 = front[0][1].colorCode;
	front[0][1].colorCode = front[1][2].colorCode;
	front[1][2].colorCode = front[2][1].colorCode;
	front[2][1].colorCode = front[1][0].colorCode;
	front[1][0].colorCode = temp1;
	//Corner Turns
	temp1 = front[0][2].colorCode;
	front[0][2].colorCode = front[2][2].colorCode;
	front[2][2].colorCode = front[2][0].colorCode;
	front[2][0].colorCode = front[0][0].colorCode;
	front[0][0].colorCode = temp1;
}