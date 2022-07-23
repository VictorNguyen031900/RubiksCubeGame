#include "Everything.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{
	int userINPUT;
	everything theGAME;
	do {
		cout << "Hello welcome to my rubik's cube program!" << endl;
		cout << "Do you want to play?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cout << "INPUT HERE: ";
		cin >> userINPUT;
		switch (userINPUT)
		{
		case 1:
			system("cls");
			cout << "Let's play!" << endl;
			Sleep(300);
			theGAME.start();
			break;
		case 2:
			system("cls");
			cout << endl << "Ah shit oh okay it be like that sometimes pepehands." << endl << endl;
			break;
		default:
			system("cls");
			cout << endl << "Please pick 1 or 2!" << endl << endl;
			break;
		}
	} while ((userINPUT != 1) && (userINPUT != 2));
	return 0;
}
