#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <string>
#include <iostream>
#include <windows.h>
#include "Person.h"
#include "Doctor.h"
#include "Department.h"

using namespace std;

//void Choose_Doc(int docIn, int &x, int &y, int &z, int &b);
Doctor Choose_Doc(int docIn);
void PrintEmergency();		
void PrintNutrition();	
void PrintEnt();		
void PrintPsychology();		
void PrintDent();		
void PrintDermatology();		
void PrintCardiology();		
void PrintChest();		
void PrintPhysiotheraphy();
void PrintGeneral();
void PrintTime(int timeL);

class Patient:public Person{
        private:
            char gender;
            string blood_type;
            string phone_number;
            string id_number;
        public:
            
            Patient();
            
            Patient(string name, string surname, char gender, string blood_type, string phone_number, string id_number):Person(name, surname){
                this->gender = gender;
                this->blood_type = blood_type;
                this->phone_number = phone_number;
                this->id_number = id_number;
            }
            
            //~Patient();
            
            
            void set_gender(char gender)
            {
                this->gender = gender;
            }
            
            char get_gender()
            {
                return gender;
            }
            
            void set_blood_type(string blood_type)
            {
                this->blood_type = blood_type;
            }
            
            string get_blood_type()
            {
                return blood_type;
            }
            
            void set_phone_number(long phone_number)
            {
                this->phone_number = phone_number;
            }
            
            string get_phone_number()
            {
                return phone_number;
            }
            
            void set_id_number(long id_number)
            {
                this->id_number = id_number;
            }
            
            string get_id_number()
            {
                return id_number;
            }
            friend ostream& operator<<(ostream& os, const Patient& obj);
};

ostream& operator<<(ostream& os, Patient &obj)
{
    cout <<"Name: " << obj.get_name() << endl <<"Surname: "<< obj.get_surname() << endl <<"Gender(m/f):" << obj.get_gender() << endl << "Blood type: " << obj.get_blood_type() << endl <<"Phone number:"<<obj.get_phone_number() << endl <<"National id:"<< obj.get_id_number()<< endl;
    return os;
}

int main() {
	bool verify = false;
	char gender;
	string name, surname, bloodType, phone, id;
	string hes;
	int timeL, timer;
	
	
	PrintTime(timeL);
	
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect); 
 
   MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 537, 600, TRUE);
	
	
    
	
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~          |Welcome to Hospital Reservation System|          ~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	
	
	
	
	
	while (verify == false)
	{
		cout << endl << "Due to the corona virus please enter your 10 digit HES code:" << endl;
		cin >> hes;

		if (hes.length() != 10)
		{
			cout << "Please make sure you have entered the HES code correctly!" << endl;
			verify = false;
		}

		else
		{
			verify = true;
		}
	}
	
	verify = false;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	while (verify == false)
	{
		cout << "Enter your name: ";
		cin >> name;

		for (int i = 0; i < name.length(); i++)
		{
			if ((int)(name[i]) < 65 || ((int)(name[i]) > 90 && (int)(name[i]) < 97) || (int)(name[i]) > 122)
			{
				cout << "Please enter a valid name!" << endl;
				verify = 0;
				break;
			}
			else
			{
				verify = true;
			}
		}
	}

	verify = false;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	while (verify == false)
	{
		cout << "Enter your surname: ";
		cin >> surname;
		for (int i = 0; i < surname.length(); i++)
		{
			if ((int)(surname[i]) < 65 || ((int)(surname[i]) > 90 && (int)(surname[i]) < 97) || (int)(surname[i]) > 122)
			{
				cout << "Please enter a valid surname!" << endl;
				verify = false;
				break;
			}
			else
			{
				verify = true;
			}
		}
	}

	verify = false;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	while (verify == false)
	{
		cout << "Enter your gender(m/f): " << endl;
		cin >> gender;

		if (gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F')
		{
			verify = true;
		}

		else
		{
			cout << "Please enter a valid gender code!" << endl;
			verify = false;
		}
	}

	verify = false;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	while (verify == false)
	{
		cout << "Enter your blood type(A|B|AB|0): " << endl;
		cin >> bloodType;

		if (bloodType == "a" || bloodType == "A" || bloodType == "b" || bloodType == "B" || bloodType == "AB" || bloodType == "ab" || bloodType == "Ab" || bloodType == "aB" || bloodType == "0")
		{
			verify = true;
		}

		else
		{
			cout << "Please enter a valid blood type!" << endl;
			verify = false;
		}
	}

	verify = false;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	while (verify == false)
	{
		cout << "Enter your 10 digit phone number(5*********): " << endl;
		cin >> phone;

		if (phone.length() != 10)
		{
			cout << "Please make sure you have entered the phone number correctly!" << endl;
			verify = false;
		}

		else
		{
			verify = true;
		}
	}

	verify = false;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	while (verify == false)
	{
		cout << "Enter your 11 digit national id: " << endl;
		cin >> id;

		if (id.length() != 11)
		{
			cout << "Please make sure you have entered the national id correctly!" << endl;
			verify = false;
		}

		else
		{
			verify = true;
		}
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                    |Patient Information|                     " << endl;
	Patient pt(name, surname, gender,  bloodType,  phone,  id);
	cout << pt;
	cout << "HES code: " << hes;
	cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	
	verify = false;
	while(verify == false){
		cout <<"                     |Departments|                     "<< endl;
		Department departments;
		departments.ShowMenu();
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Enter the department you want: ";
		int depIn;
		cin >> depIn;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		int docIn;
		
		
		switch(depIn){
			case 1:{
				while(verify == false){
					int sub, wait;
					cout << "                         |Emergency|                          " << endl;
					PrintTime(timeL);
					PrintEmergency();
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "Choose the doctor by entering id: ";
					cin >> docIn;
					//int x, y, z, b;
					//Choose_Doc(docIn, x, y, z, b);
					//Doctor doc(x, y, z, b);
					Doctor doc = Choose_Doc(docIn);
					cout << endl << "id: " << doc.get_doc_id() << " dep id: " << doc.get_dep_id() << " start: " << doc.get_shift_start() << endl;
					
					PrintTime(timeL);
					
					if(timeL != doc.get_shift_start())
					{
						if(timeL < doc.get_shift_start()){
							sub = doc.get_shift_start() - timeL; 
							cout << "The doctor is not availabe for " << sub << "hour(s)." << endl;
						}
						else if(timeL > doc.get_shift_start()){
							sub = 24 - (timeL - doc.get_shift_start());
							cout << "The doctor is not availabe for " << sub << "hour(s)." << endl;
						}
					}
						cout << "Do you want to wait here for " << sub << "hour(s)?" << endl;
						cout << "1-Wait here " << sub << " hour(s)." << endl << "2-Exit" << endl;
						cout << "Your choice: ";
						cin >> wait;
						
						while (wait != 1)
						{
							if(wait == 1)
							{	
								if (timeL + sub >= 24)
								{
									timeL = timeL + sub - 24;
								}
								else
								{
									timeL += sub;
								}
							}
						
							else if (wait == 2)
							{
								cout << endl << "Goes to department" << endl;
								verify = true;
								wait = 1;
							}
							
							else
							{
								cout << "Enter a valid choice please!" << endl;
							}
						}
						cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					}
					verify = false;
					break;
				}
			case 2:{
				cout << "                   |Nutrition and Dietetics|                  " << endl;
				PrintNutrition();
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Choose the doctor by entering id: ";
				cin >> docIn;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				break;
			}
			case 3:{
				PrintEnt();
				cout << "                      |Ear Nose Throat|                       " << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Choose the doctor by entering id: ";
				cin >> docIn;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				break;
			}
			case 4:{
				cout << "                         |Psychology|                         " << endl;
				PrintPsychology();
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Choose the doctor by entering id: ";
				cin >> docIn;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				break;
			}
			case 5:{
				cout << "                        |Dental Health|                       " << endl;
				PrintDent();
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Choose the doctor by entering id: ";
				cin >> docIn;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				break;
			}
			case 6:{
				cout << "                         |Dermatology|                        " << endl;
				PrintDermatology();
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Choose the doctor by entering id: ";
				cin >> docIn;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				break;
			}
			case 7:{
				cout << "                         |Cardiology|                         " << endl;
				PrintCardiology();
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Choose the doctor by entering id: ";
				cin >> docIn;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				break;
			}
			case 8:{
				cout << "                        |Chest Diseas|                        " << endl;
				PrintChest();
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Choose the doctor by entering id: ";
				cin >> docIn;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				break;
			}
			case 9:{
				cout << "                       |Physiotheraphy|                       " << endl;
				PrintPhysiotheraphy();
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Choose the doctor by entering id: ";
				cin >> docIn;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				break;
			}
			case 10:{
				cout << "                       |General Surgery|                      " << endl;
				PrintGeneral();
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Choose the doctor by entering id: ";
				cin >> docIn;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				break;
			}
			case 11:{
				cout << endl << endl << "Bye!";
				verify = true;
				break;
			}
			default:{
				cout << endl << endl << "Wrong Input!";
				break;
			}
		}
	}
	return 0;
}

Doctor Choose_Doc(int docIn){
	cout << "\n";
	ifstream file;
	file.open("Doctors.txt");
	if (!file) {
		cout << "no such file exist" << endl;
	}
	string line;
	
	for(int i = 1; i < docIn; i++){
		getline(file, line);
	}
	int x, y, z, b;
	file >> x;
	file.ignore();

	file >> y;
	file.ignore();

	file >> z;
	file.ignore();

	file >> b;
	file.ignore();
	/*
	string line;
	getline(file, line, ',');
	*/
	Doctor doc(x, y, z, b);
	return doc;
}

void PrintEmergency(){
	cout << "\n";
	ifstream file;
	file.open("Doctors.txt");
	
	if (!file) {
		cout << "no such file exist" << endl;
	}
	string depart;
	int x, y, z, b, i = 0;

	cout << setw(5) << "ID: " << setw(15) << "DEPARTMENT" << setw(15) << "NAME" << setw(15) << "TIMINGS" << endl << endl;
	while (i != 2) {
		file >> x;
		file.ignore();

		file >> y;
		file.ignore();

		file >> z;
		file.ignore();

		file >> b;
		file.ignore();

		string line;
		getline(file, line, ',');

		cout << setw(4) << x << setw(15) << " Emergency" << setw(20) << line << setw(7) << z << "-" << b << endl << endl;
		i++;
	}
	file.close();
}

void PrintNutrition() {
	cout << "\n";
	ifstream file;
	file.open("Doctors.txt");

	if (!file) {
		cout << "no such file exist" << endl;
	}
	string discard;
	getline(file, discard, '$');

	string depart;
	int x, y, z, b, i = 0;

	cout << setw(5) << "ID: " << setw(15) << " DEPARTMENT" << setw(15) << "NAME" << setw(15) << "TIMINGS" << endl << endl;
	while (i != 2) {
		file >> x;
		file.ignore();

		file >> y;
		file.ignore();

		file >> z;
		file.ignore();

		file >> b;
		file.ignore();

		string line;
		getline(file, line, ',');

		cout << setw(4) << x << setw(15) << " Nutrition and Dietetics" << setw(20) << line << setw(7) << z << "-" << b << endl << endl;
		i++;
	}
	file.close();
}

void PrintEnt() {
	cout << "\n";
	ifstream file;
	file.open("Doctors.txt");

	if (!file) {
		cout << "no such file exist" << endl;
	}
	string discard;
	getline(file, discard, '&');

	string depart;
	int x, y, z, b, i = 0;

	cout << setw(5) << "ID: " << setw(15) << " DEPARTMENT" << setw(15) << "NAME" << setw(15) << "TIMINGS" << endl << endl;
	while (i != 2) {
		file >> x;
		file.ignore();

		file >> y;
		file.ignore();

		file >> z;
		file.ignore();

		file >> b;
		file.ignore();

		string line;
		getline(file, line, ',');

		cout << setw(4) << x << setw(15) << " Ear Nose Throat" << setw(20) << line << setw(7) << z << "-" << b << endl << endl;
		i++;
	}
	file.close();
}

void PrintPsychology() {
	cout << "\n";
	ifstream file;
	file.open("Doctors.txt");

	if (!file) {
		cout << "no such file exist" << endl;
	}
	string discard;
	getline(file, discard, '@');

	string depart;
	int x, y, z, b, i = 0;

	cout << setw(5) << "ID: " << setw(15) << "DEPARTMENT" << setw(15) << "NAME" << setw(15) << "TIMINGS" << endl << endl;
	while (i != 2) {
		file >> x;
		file.ignore();

		file >> y;
		file.ignore();

		file >> z;
		file.ignore();

		file >> b;
		file.ignore();

		string line;
		getline(file, line, ',');

		cout << setw(4) << x << setw(15) << " Psychology" << setw(20) << line << setw(7) << z << "-" << b << endl << endl;
		i++;
	}
	file.close();
}

void PrintDent() {
	cout << "\n";
	ifstream file;
	file.open("Doctors.txt");

	if (!file) {
		cout << "no such file exist" << endl;
	}
	string discard;
	getline(file, discard, '#');

	string depart;
	int x, y, z, b, i = 0;

	cout << setw(5) << "ID: " << setw(15) << "DEPARTMENT" << setw(15) << "NAME" << setw(15) << "TIMINGS" << endl << endl;
	while (i != 2) {
		file >> x;
		file.ignore();

		file >> y;
		file.ignore();

		file >> z;
		file.ignore();

		file >> b;
		file.ignore();

		string line;
		getline(file, line, ',');

		cout << setw(4) << x << setw(15) << " Dental Health" << setw(20) << line << setw(7) << z << "-" << b << endl << endl;
		i++;
	}
	file.close();
}

void PrintDermatology() {
	cout << "\n";
	ifstream file;
	file.open("Doctors.txt");

	if (!file) {
		cout << "no such file exist" << endl;
	}
	string discard;
	getline(file, discard, '£');

	string depart;
	int x, y, z, b, i = 0;

	cout << setw(5) << "ID: " << setw(15) << "DEPARTMENT" << setw(15) << "NAME" << setw(15) << "TIMINGS" << endl << endl;
	while (i != 2) {
		file >> x;
		file.ignore();

		file >> y;
		file.ignore();

		file >> z;
		file.ignore();

		file >> b;
		file.ignore();

		string line;
		getline(file, line, ',');

		cout << setw(4) << x << setw(15) << " Dermatology" << setw(20) << line << setw(7) << z << "-" << b << endl << endl;
		i++;
	}
	file.close();
}

void PrintCardiology() {
	cout << "\n";
	ifstream file;
	file.open("Doctors.txt");

	if (!file) {
		cout << "no such file exist" << endl;
	}
	string discard;
	getline(file, discard, '%');

	string depart;
	int x, y, z, b, i = 0;

	cout << setw(5) << "ID: " << setw(15) << "DEPARTMENT" << setw(15) << "NAME" << setw(15) << "TIMINGS" << endl << endl;
	while (i != 2) {
		file >> x;
		file.ignore();

		file >> y;
		file.ignore();

		file >> z;
		file.ignore();

		file >> b;
		file.ignore();

		string line;
		getline(file, line, ',');

		cout << setw(4) << x << setw(15) << " Cardiology" << setw(20) << line << setw(7) << z << "-" << b << endl << endl;
		i++;
	}
	file.close();
}

void PrintChest() {
	cout << "\n";
	ifstream file;
	file.open("Doctors.txt");

	if (!file) {
		cout << "no such file exist" << endl;
	}
	string discard;
	getline(file, discard, '/');

	string depart;
	int x, y, z, b, i = 0;

	cout << setw(5) << "ID: " << setw(15) << "DEPARTMENT" << setw(15) << "NAME" << setw(15) << "TIMINGS" << endl << endl;
	while (i != 2) {
		file >> x;
		file.ignore();

		file >> y;
		file.ignore();

		file >> z;
		file.ignore();

		file >> b;
		file.ignore();

		string line;
		getline(file, line, ',');

		cout << setw(4) << x << setw(15) << " Chest Diseas" << setw(20) << line << setw(7) << z << "-" << b << endl << endl;
		i++;
	}
	file.close();
}

void PrintPhysiotheraphy() {
	cout << "\n";
	ifstream file;
	file.open("Doctors.txt");

	if (!file) {
		cout << "no such file exist" << endl;
	}
	string discard;
	getline(file, discard, '=');

	string depart;
	int x, y, z, b, i = 0;

	cout << setw(5) << "ID: " << setw(15) << "DEPARTMENT" << setw(15) << "NAME" << setw(15) << "TIMINGS" << endl << endl;
	while (i != 2) {
		file >> x;
		file.ignore();

		file >> y;
		file.ignore();

		file >> z;
		file.ignore();

		file >> b;
		file.ignore();

		string line;
		getline(file, line, ',');

		cout << setw(4) << x << setw(15) << " Physiotheraphy" << setw(20) << line << setw(7) << z << "-" << b << endl << endl;
		i++;
	}
	file.close();
}

void PrintGeneral() {
	cout << "\n";
	ifstream file;
	file.open("Doctors.txt");

	if (!file) {
		cout << "no such file exist" << endl;
	}
	string discard;
	getline(file, discard, '*');

	string depart;
	int x, y, z, b, i = 0;

	cout << setw(5) << "ID: " << setw(15) << "DEPARTMENT" << setw(15) << "NAME" << setw(15) << "TIMINGS" << endl << endl;
	while (i != 2) {
		file >> x;
		file.ignore();

		file >> y;
		file.ignore();

		file >> z;
		file.ignore();

		file >> b;
		file.ignore();

		string line;
		getline(file, line, ',');

		cout << setw(4) << x << setw(15) << " General Surgery" << setw(20) << line << setw(7) << z << "-" << b << endl << endl;
		i++;
	}
	file.close();
}

void PrintTime(int timeL)
{
	int timeR;
	
	srand (time(NULL));
	
	timeL = (rand() % 24);
	timeR = (rand() % 60);
	
	cout << "                                                 -------------" << endl;
	if (timeL < 10 && timeL >= 0)
	{
		if(timeR>= 0 && timeR <10)
		{
			cout << "                                                 |Time: " <<"0"<< timeL << ":" << "0" << timeR << "|" <<endl;
		}
		else
		{
			cout << "                                                 |Time: " <<"0"<< timeL << ":" << timeR << "|" <<endl;
		}
	}
	else if (timeL>=10)
	{
		if(timeR>= 0 && timeR <10)
		{
			cout << "                                                 |Time: " <<timeL << ":" << "0" << timeR << "|" << endl;
		}
		else
		{
			cout << "                                                 |Time: " <<timeL << ":" << timeR << "|" <<endl;
		}
	}
	
	cout << "                                                 -------------" << endl;
}
