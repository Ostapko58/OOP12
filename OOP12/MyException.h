#pragma once
#include<iostream>
#include<string>
using namespace std;

class MyException
{
	string massage;
public:
	MyException(string massage) 
	{
		this->massage = massage;
	}
	string what() { return massage; }
};

