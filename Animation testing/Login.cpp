#include "Login.h"
#include<iostream>
#include<fstream>
#include<string>
#include<fstream>
using namespace std;


Login* logins;
const string fileName = "Login.txt";
int countLogins = 0;


void insert(Login data)
{
	Login* temp = new Login[countLogins + 1];
	for (int  i = 0; i < countLogins; i++)
	{
		temp[i] = logins[i];
	}
	temp[countLogins] = data;
	countLogins++;
	logins = new Login[countLogins];
	for (int i = 0; i < countLogins; i++)
	{
		logins[i] = temp[i];
	}
	delete[]temp;

}



void init()
{
	ifstream fin;
	fin.open(fileName);
	bool isOpen = fin.is_open();

	if (isOpen==true)
	{
		while (!fin.eof())
		{
			Login temp;
			fin.ignore();
			getline(fin, temp.FullName);
			if (temp.FullName!="")
			{
				fin >> temp.Age;
				fin >> temp.email;
				fin >> temp.Password;
				insert(temp);
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		cout << "Error ! Can not open file !" << endl;

	}
}



void Registration()
{
	cout << "Registration form" << endl;
	ofstream fout;
	fout.open(fileName, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen==true)
	{
		Login newUser;
		cout << "Enter your full name please :";
		cin >> newUser.FullName;
		cout << "Enter your age please :";
		cin >> newUser.Age;
		cout << "Enter your email address :";
		cin >> newUser.email;
		cout << "Enter your password :";
		cin >> newUser.Password;
		insert(newUser);

		fout << newUser.FullName << endl;
		fout << newUser.Age << endl;
		fout << newUser.email << endl;
		fout << newUser.Password << endl;
		fout.close();
	}
	else
	{
		cout << "Error: Application can't open data file!" << endl;

	}
}

void Authorithation()
{
	string email;
	string password;
	int index = 0;
	cout << "Please enter your login (email) :";
	cin >> email;
	cout << "Please enter your password :";
	cin >> password;

	for (int i = 0; i < countLogins; i++)
	{
		if (email==logins[i].email&&password==logins[i].Password)
		{
			cout << "Welcome" << " " << logins[i].FullName << endl;
			index++;
		}
	}
	if (index==0)
	{
		cout << "You enter invalid login or password" << endl;
	}
	else
	{
		index--;
	}
}
