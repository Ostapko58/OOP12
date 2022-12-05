#pragma once
#include<iostream>
#include<string>
#include<exception>
using namespace std;

class MyExceptionInherit : public exception
{
public:
	MyExceptionInherit(char const* const massage) :exception(massage) {}
};

