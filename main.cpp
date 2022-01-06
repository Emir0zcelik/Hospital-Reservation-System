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
void PrintTime(int timeL, int timeR);
void WriteToFile(string patient_name, string patient_surname, int doc_name, int dep_name, int hour);
void PrintAppointment();

void PatientInput(bool &verify ,string &hes, string &name, string &surname, char &gender, string &bloodType, string &phone, string &id);

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


ostream& operator<<(ostream& os, Patient &obj){
    cout <<"Name: " << obj.get_name() << endl <<"Surname: "<< obj.get_surname() << endl <<"Gender(m/f):" << obj.get_gender() << endl << "Blood type: " << obj.get_blood_type() << endl <<"Phone number:"<<obj.get_phone_number() << endl <<"National id:"<< obj.get_id_number()<< endl;
    return os;
}

void RegisterPatient(bool &verify, int &docIn, int &timeL, int timeR, Patient pt);
void RegistrationInfo(Doctor doc, string problems, bool &verify, Patient pt, int hour);

int main() {
	bool verify = false;
	char gender;
	string name, surname, bloodType, phone, id;
	string hes;
	int timeL, timeR;
	
	srand (time(NULL));
	
	timeL = (rand() % 24);
	timeR = (rand() % 60);
	
	PrintTime(timeL, timeR);
	
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect); 
 
   MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 561, 650, TRUE);
	
	
    
	
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~           |Welcome to Hospital Reservation System|            ~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	
	while(verify == false)
	{
		int menuIn;
		cout<< endl << "                           |Main Menu|                           " << endl << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "1-Make a new appointment" << endl << "2-Show previous appointments" << endl << "3-Exit to hospital" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Choice: ";
		cin >> menuIn;
		
		
		if(menuIn == 1)
		{
			PatientInput(verify, hes, name, surname , gender, bloodType, phone, id);
			
			
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "                    |Patient Information|                     " << endl;
			Patient pt(name, surname, gender,  bloodType,  phone,  id);
			cout << pt;
			cout << "HES code: " << hes;
			cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			
			while(verify == false){
				cout <<"                     |Departments|                     "<< endl;
				Department departments;
				departments.ShowMenu();
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Enter the department you want: ";
				int depIn;
				cin >> depIn;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				int docIn;
				
				
				switch(depIn){
					case 1:{
						while(verify == false){
							cout << "                         |Emergency|                          " << endl;
							PrintTime(timeL, timeR);
							PrintEmergency();
							RegisterPatient(verify, docIn, timeL, timeR, pt);		
						}
						verify = false;
						break;		
					}
					case 2:{
						while(verify == false){
						cout << "                   |Nutrition and Dietetics|                  " << endl;
						
						PrintTime(timeL, timeR);
						PrintNutrition();
						RegisterPatient(verify, docIn, timeL, timeR, pt);
						}
						verify = false;
						break;
					}
					case 3:{
						while(verify == false){
							cout << "                      |Ear Nose Throat|                       " << endl;
							PrintTime(timeL, timeR);
							PrintEnt();
							RegisterPatient(verify, docIn, timeL, timeR, pt);
						}
						verify = false;
						break;
					}
					case 4:{
						while(verify == false){
							cout << "                         |Psychology|                         " << endl;
							PrintTime(timeL, timeR);
							PrintPsychology();
							RegisterPatient(verify, docIn, timeL, timeR, pt);
						}
						verify = false;
						break;
					}
					case 5:{			
						while(verify == false){
							cout << "                        |Dental Health|                       " << endl;
							PrintTime(timeL, timeR);
							PrintDent();
							RegisterPatient(verify, docIn, timeL, timeR, pt);
						}
						verify = false;
						break;
					}
					case 6:{
						while(verify == false){
							cout << "                         |Dermatology|                        " << endl;
							PrintTime(timeL, timeR);
							PrintDermatology();
							RegisterPatient(verify, docIn, timeL, timeR, pt);
						}
						verify = false;
						break;
					}
					case 7:{
						while(verify == false){
							cout << "                         |Cardiology|                         " << endl;
							PrintTime(timeL, timeR);
							PrintCardiology();
							RegisterPatient(verify, docIn, timeL, timeR, pt);
						}
						verify = false;
						break;
					}
					case 8:{
						while(verify == false){
							cout << "                        |Chest Diseas|                        " << endl;
							PrintTime(timeL, timeR);
							PrintChest();
							RegisterPatient(verify, docIn, timeL, timeR, pt);
						}
						verify = false;
						break;
					}
					case 9:{				
						while(verify == false){
							cout << "                       |Physiotheraphy|                       " << endl;
							PrintTime(timeL, timeR);
							PrintPhysiotheraphy();
							RegisterPatient(verify, docIn, timeL, timeR, pt);
						}
						verify = false;
						break;
					}
					case 10:{		
						while(verify == false){
							cout << "                       |General Surgery|                      " << endl;
							PrintTime(timeL, timeR);
							PrintGeneral();
							RegisterPatient(verify, docIn, timeL, timeR, pt);
						}
						verify = false;
						break;
					}
					case 11:{
						verify = true;
						break;
					}
					default:{
						cout << endl << endl << "Wrong Input!";
						break;
					}
				}
			}
			verify = false;
		}
		
		else if(menuIn == 2)
		{
			int app_choice;
			
			PrintAppointment();
		}
		
		else if(menuIn == 3)
		{
			cout << "Bye!!" << endl;
			return 0;
		}
		
		else
		{
			cout << "Please enter a valid input!" << endl;
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
	
	string name;
	getline(file, name, ',');
	
	Doctor doc(x, y, z, b, name);
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

		cout << setw(4) << x << setw(15) << " Emergency" << setw(20) << line << setw(7) << z << "-" << b <<":59" << endl << endl;
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

		cout << setw(4) << x << setw(15) << " Nutrition and Dietetics" << setw(20) << line << setw(7) << z << "-" << b <<":59" << endl << endl;
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

		cout << setw(4) << x << setw(15) << " Ear Nose Throat" << setw(20) << line << setw(7) << z << "-" << b <<":59" << endl << endl;
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

		cout << setw(4) << x << setw(15) << " Psychology" << setw(20) << line << setw(7) << z << "-" << b <<":59" << endl << endl;
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

		cout << setw(4) << x << setw(15) << " Dental Health" << setw(20) << line << setw(7) << z << "-" << b <<":59" << endl << endl;
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

		cout << setw(4) << x << setw(15) << " Dermatology" << setw(20) << line << setw(7) << z << "-" << b <<":59" << endl << endl;
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

		cout << setw(4) << x << setw(15) << " Cardiology" << setw(20) << line << setw(7) << z << "-" << b <<":59" << endl << endl;
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

		cout << setw(4) << x << setw(15) << " Chest Diseas" << setw(20) << line << setw(7) << z << "-" << b <<":59" << endl << endl;
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

		cout << setw(4) << x << setw(15) << " Physiotheraphy" << setw(20) << line << setw(7) << z << "-" << b <<":59" << endl << endl;
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

		cout << setw(4) << x << setw(15) << " General Surgery" << setw(20) << line << setw(7) << z << "-" << b <<":59" << endl << endl;
		i++;
	}
	file.close();
}

void PrintTime(int timeL, int timeR)
{	
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

void RegisterPatient(bool &verify, int &docIn, int &timeL, int timeR, Patient pt)
{	
	int hour;
	string problem;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Choose the doctor by entering id: ";
	cin >> docIn;
	Doctor doc = Choose_Doc(docIn);
	PrintTime(timeL, timeR);
	
	if(timeL < doc.get_shift_start() || timeL > doc.get_shift_end())
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "At this time the doctor is not available."<< endl <<"Please make an appointment for later hours." << endl;
		
		while (verify == false)
		{
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Enter a hour for appointment: ";
			cin >> hour;
			if (hour < doc.get_shift_start() || hour > doc.get_shift_end())
			{
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Please enter a available hour!" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			}
			else
			{
				verify = true;
			}
		}
		verify = false;	
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Please enter you problem with few sentences." << endl;
		getline(cin, problem);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "                    |Patient Information|                     " << endl;
		RegistrationInfo(doc, problem, verify, pt, hour);
	}
	
	else
	{
		int app;
		cout << "Doctor is avaliable at the moment would you like to take an appointment for now or future? " << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "1-Make an appointment for now." << endl << "2-Choose an hour to make an appointment for future." << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cin >> app;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		
		if(app == 1)
		{
			cout << "Please enter you problem with few sentences." << endl;
			getline(cin, problem);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "                    |Patient Information|                     " << endl;
			RegistrationInfo(doc, problem, verify, pt, hour);
		}
		else if (app == 2)
		{
			while (verify == false)
			{
				cout << "Enter a hour for appointment: ";
				cin >> hour;
			
				if (hour < doc.get_shift_start() || hour > doc.get_shift_end())
				{
					cout << "Please enter a available hour!" << endl;
				}
				else
				{
					verify = true;
				}
			}
			
			verify = false;	
			
			cout << "Please enter you problem with few sentences." << endl;
			getline(cin, problem);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "                    |Patient Information|                     " << endl;
			RegistrationInfo(doc, problem, verify, pt, hour);
		}
	}
}

void PatientInput(bool &verify ,string &hes, string &name, string &surname, char &gender, string &bloodType, string &phone, string &id)
{
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
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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
	verify = false;
}


void RegistrationInfo(Doctor doc, string problems, bool &verify, Patient pt, int hour)
{
	while(verify == false)
	{
		cout <<"Name: " << pt.get_name() << endl <<"Surname: "<< pt.get_surname() << endl <<"Gender(m/f):" << pt.get_gender() << endl << "Blood type: " << pt.get_blood_type() << endl << "Patient's complaint:" << problems << endl;
		
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "                    |Appointment information|                    " << endl << "Doctor name: ";
		
		switch(doc.get_doc_id()){
			case 1:{
				cout << "Burak Guler" << endl;
				break;
			}
			case 2:{
				cout << "Fadime Ozer" << endl;
				break;
			}
			case 3:{
				cout << "Zeynep Kosea" << endl;
				break;
			}
			case 4:{
				cout << "Melike Korkmaz" << endl;
				break;
			}
			case 5:{
				cout << "Selma Sari" << endl;
				break;
			}
			case 6:{
				cout << "Elif Unal" << endl;
				break;
			}
			case 7:{
				cout << "Emrah Yavuz" << endl;
				break;
			}
			case 8:{
				cout << "Furkan Yavuz" << endl;
				break;
			}
			case 9:{
				cout << "Esra Can" << endl;
				break;
			}
			case 10:{
				cout << "Kubra Ozdemir" << endl;
				break;
			}
			case 11:{
				cout << "Sultan Ozcan" << endl;
				break;
			}
			case 12:{
				cout << "Hasan Ozcan" << endl;
				break;
			}
			case 13:{
				cout << "Emre Arslan" << endl;
				break;
			}
			case 14:{
				cout << "Tuba Ozer" << endl;
				break;
			}
			case 15:{
				cout << "Medine Buyuk" << endl;
				break;
			}
			case 16:{
				cout << "Umran Korkmaz" << endl;
				break;
			}
			case 17:{
				cout << "Efe Koyuncu" << endl;
				break;
			}
			case 18:{
				cout << "Caner Aymaz" << endl;
				break;
			}
			case 19:{
				cout << "Fadime Maraz" << endl;
				break;
			}
			case 20:{
				cout << "Aynur Yolucu" << endl;
				break;
			}
		}
		cout << "Department: ";
		switch (doc.get_dep_id()){
			case 0:{
				cout << "Emergency" << endl;
				break;
			}
			
			case 1:{
				cout << "Nutrition and Dietetics" << endl;
				break;
			}
			
			case 2:{
				cout << "Ear Nose Throat" << endl;
				break;
			}
			
			case 3:{
				cout << "Psychology" << endl;
				break;
			}
			
			case 4:{
				cout << "Dental Health" << endl;
				break;
			}
			
			case 5:{
				cout << "Dermatology" << endl;
				break;
			}
			
			case 6:{
				cout << "Cardiology" << endl;
				break;
			}
			
			case 7:{
				cout << "Chest Diseas" << endl;
				break;
			}
			
			case 8:{
				cout << "Physiotheraphy" << endl;
				break;
			}
			
			case 9:{
				cout << "General Surgery" << endl;
				break;
			}	
		}
		
		cout << "Appointment hour: " << hour << ":00" << endl;
		while(verify == false){
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "Do you accept?" << endl << "1.Yes" << endl << "2.No" << endl;
			int yes_no;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cin >> yes_no;
			if(yes_no == 1){
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Your appointment has been recorded!" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				WriteToFile(pt.get_name(), pt.get_surname(), doc.get_doc_id(), doc.get_dep_id(), hour);
				verify = true;
			}
			else if(yes_no == 2){
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Appointment cancelled going back to the menu!" << endl;
				verify = true;
			}
			else{
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Wrong input!";
			}
		}
	}
}

void WriteToFile(string patient_name, string patient_surname, int doc_name, int dep_name, int hour){
	ofstream file ("Appointments.txt", ios::app);
	
	if (!file.is_open()) {
		cout << "no such file exist" << endl;
	}
	
	string name, dep;
	switch(doc_name){
			case 1:{
				name = "Burak Guler";
				break;
			}
			case 2:{
				name = "Fadime Ozer";
				break;
			}
			case 3:{
				name = "Zeynep Kosea";
				break;
			}
			case 4:{
				name = "Melike Korkmaz";
				break;
			}
			case 5:{
				name = "Selma Sari";
				break;
			}
			case 6:{
				name = "Elif Unal";
				break;
			}
			case 7:{
				name = "Emrah Yavuz";
				break;
			}
			case 8:{
				name = "Furkan Yavuz";
				break;
			}
			case 9:{
				name = "Esra Can";
				break;
			}
			case 10:{
				name = "Kubra Ozdemir";
				break;
			}
			case 11:{
				name = "Sultan Ozcan";
				break;
			}
			case 12:{
				name = "Hasan Ozcan";
				break;
			}
			case 13:{
				name = "Emre Arslan";
				break;
			}
			case 14:{
				name = "Tuba Ozer";
				break;
			}
			case 15:{
				name = "Medine Buyuk";
				break;
			}
			case 16:{
				name = "Umran Korkmaz";
				break;
			}
			case 17:{
				name = "Efe Koyuncu";
				break;
			}
			case 18:{
				name = "Caner Aymaz";
				break;
			}
			case 19:{
				name = "Fadime Maraz";
				break;
			}
			case 20:{
				name = "Aynur Yolucu";
				break;
			}
		}
	
	switch (dep_name){
			case 0:{
				dep = "Emergency";
				break;
			}
			
			case 1:{
				dep = "Nutrition and Dietetics";
				break;
			}
			
			case 2:{
				dep = "Ear Nose Throat";
				break;
			}
			
			case 3:{
				dep = "Psychology";
				break;
			}
			
			case 4:{
				dep = "Dental Health";
				break;
			}
			
			case 5:{
				dep = "Dermatology";
				break;
			}
			
			case 6:{
				dep = "Cardiology";
				break;
			}
			
			case 7:{
				dep = "Chest Diseas";
				break;
			}
			
			case 8:{
				dep = "Physiotheraphy";
				break;
			}
			
			case 9:{
				dep = "General Surgery";
				break;
			}	
		}

	file << patient_name << " | " << patient_surname << " | " << dep << " | " << hour << " | " << name << " | " << endl;
	file << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
																			  
	file.close();
}

void PrintAppointment()
{
	cout << "\n";
	ifstream file;
	file.open("Appointments.txt");
	
	if (!file) {
		cout << "no such file exist" << endl;
	}
	int x, y, z, b;
	cout << "-----------------------------------------------------------------"<< endl;
	cout << setw(5) << "|Name" << setw(2) << "|" << setw(1) << "Surname|"<< setw(17) <<  "DEPARTMENT" << setw(9) << "|" <<setw(1) << "TIME|" <<setw(8) << "DOCTOR NAME|" << endl;
	cout << "-----------------------------------------------------------------"<< endl << endl; 
			
	if(file.is_open())
	{
		cout << file.rdbuf();
	}
	
	file.close();
}
