#pragma once
#include<string>

class Person
{
public:
	const std::string name;
	Person() {}
	Person(std::string n) : name(n) {};
	~Person();
};

