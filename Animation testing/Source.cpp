#include <windows.h>
#include <iostream>
#include<ctime>
#include<string>
#include "Login.h"

using namespace std;

void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

void word() {
	
	


		SetColor(10, 0);
		cout << "\t\t*          *     * * * *     * * * *      * * * *      * * *         *     *   " << endl;

		Sleep(500);
		SetColor(7, 0);

		SetColor(12, 0);
		cout << "\t\t*         * *       *           *         *            *    *         *   *    " << endl;
		Sleep(500);
		SetColor(7, 0);

		SetColor(9, 0);
		cout << "\t\t*        *   *      *           *         * * *        * * *            *      " << endl;
		Sleep(500);


		SetColor(13, 0);
		cout << "\t\t*         * *       *           *         *            *    *           *      " << endl;
		Sleep(500);
		SetColor(7, 0);

		SetColor(14, 0);
		cout << "\t\t* * *      *        *           *         * * * *      *      *         *      " << endl;
		Sleep(500);
		SetColor(7, 0);
		
	
	
}



void OpenDoor(int deposit, int attempt) {
	
	cout << "DEPOSIT :" << deposit << "$" << endl;
	int door = 0;
	cout << "Select door 1 - 5 for switch present" << endl;

	for (int i = 0; i < 5; i++)
	{
		cin >> door;
		if (door == 5) {

			srand(time(0));
			string present[5];
			for (int i = 0; i < 1; i++)
			{
				present[i] = rand() % 5 + 1;
				cout << "\t\tYOU WIN! Your present is :" << present[i] << endl;

			}
		}
		else if (deposit == 0)
		{
			cout << "\t\tGAME OVER!\n" << endl;
		}

		else {

			(door <= 4);

			cout << "Opps. You loose! The present in the other door" << endl;
			deposit -= attempt;
			cout << "DEPOSIT :" << deposit << "$" << endl;

		}

	}



}



void Game(int deposit, int withdrawal, int attempt) {
	word();
	srand(time(0));
	int rnd = rand();
	int number;
	string Y = "y";
	string N = "n";
	cout << endl;
	cout << "\t\t\t\t\tEnter your deposit" << endl;
	cin >> deposit;
	cout << "\t\tYour deposit is :" << " " << deposit << "$" << endl;
	cout << endl;


	cout << "\t\t\t\t\tL O T T E R R Y\n" << endl;

	cout << "\t\tEnter number, you have 5 attempts\n" << endl;

	cout << "Warning! One attemp coast 200$ !\n" << endl;

	for (int i = 0; i < 5; i++)
	{
		cin >> number;
		rnd = rand() % 15 + 1;
		if (number == rnd)
		{
			cout << "\t\tYOU WIN!!! Go to prizes =)\n" << endl;
			OpenDoor(deposit, attempt);
		}
		else
		{
			cout << "Number is\t" << rnd << "\tYou Loose =(\n" << endl;
			deposit -= withdrawal;
			cout << "Your deposit is :" << deposit << "$\n" << endl;
		}
		if (deposit == 0)
		{
			cout << "\tGame over!\n" << endl;
			cout << "Do You Want Try Aggain, Y/N?" << endl;
			cin >> Y, N;
			if (Y == "y")
			{
				cout << "Your balance is 0 $! Replenish your balance please! -->\n" << endl;
				Game(deposit, withdrawal, attempt);
			}
			else
			{
				N == "n";
				cout << "\t\t\tGOOD BYE!\n" << endl;

			}

		}
		cout << endl;
	}
}






int main()
{
	init();

	int action = 0;
	do
	{
		cout << "\t\t\tHello, you want to play game lottery, but first you must do :\n" << endl;
		cout << "1. Registration" << endl;
		cout << "2. Authorithation" << endl;
		cout << "3. Exit" << endl;
		cout << endl;
		cout << "Select action :";
		cin >> action;

		switch (action)
		{
		case 1: {
			Registration();
		}break;

		case 2: {
			Authorithation();
			int deposit = 0;
			int withdrawal = 200;
			int attempt = 50;
			string present[5] = { "1 Million $","iPnone 100s","Lamborgini","Yacht","1 $" };
			Game(deposit, withdrawal, attempt);
			OpenDoor(deposit, attempt);
		}break;

		case 3: {
			cout << "Goodbye" << endl;

		}break;


		default: {
			cout << "Error: Please, select action only from list" << endl;
		}break;
		}
	} while (action != 3);
	
	
	
	
    
	
	
	












	
   /*cout << "\n\n";
   cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
   cout << "&| 7 | * | 23 | *  | 44| *  | 60 | 71| *  |&\n";
   cout << "&| * | 11| *  | 36 | * | 56 | 63 | * | 85 |&\n";
   cout << "&| 9 | * | *  | 41 | * | 55 | *  | 74| 83 |&\n";
   cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
   cout << "\n\n";


	



   cout << "\n\n";
   cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
   cout << "&| * | 17 | 25 | * | 43 | 52 | 68 | * | * |&\n";
   cout << "&| 2 | *  | *  | 37| *  | 56 | 64 | 78| * |&\n";
   cout << "&| 5 | 13 | 29 | 35| *  | *  | *  | * | 86|&\n";
   cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
   cout << "\n\n";






   cout << "\n\n";
   cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
   cout << "&| 1 | * | 24 | 33 | * | 50 | * | * | 81 |&\n";
   cout << "&| * | 16| *  | 38 | * | 54 | 61| 73| *  |&\n";
   cout << "&| * | 19| *  | *  | 48| *  | 66| 75| 84 |&\n";
   cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
   cout << "\n\n";*/









	

		
	

	system("pause");
	return 0;
}











