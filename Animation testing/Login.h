#pragma once
#include<string>
using namespace std;



struct Login {

	string FullName;
	int Age;
	string email;
	string Password;

};


void init();
void insert(Login temp);
void Registration();
void Authorithation();

