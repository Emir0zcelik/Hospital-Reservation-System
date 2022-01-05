#ifndef PERSON_H
#define PERSON_H
#include <iostream>

using namespace std;

class Person
{
protected:
	string name;
	string surname;

public:
	Person();
	Person(string name, string surname);

	void set_name(string name);
	string get_name();

	void set_surname(string surname);
	string get_surname();
};

#endif
