#include "Person.h"

#include <iostream>

Person::Person()
{
}

Person::Person(string name, string surname)
{
	this->name = name;
	this->surname = surname;
}

void Person::set_name(string name)
{
	this->name = name;
}

string Person::get_name()
{
	return name;
}

void Person::set_surname(string surname)
{
	this->surname = surname;
}

string Person::get_surname()
{
	return surname;
}
