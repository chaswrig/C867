#include <iostream>
#include "securityStudent.h"

SecurityStudent::SecurityStudent()
{
	studentID = "111111111";
	studentFirstName = "Bob";
	studentLastName = "Davis";
	studentEmail = "BobbyD@email.com";
	studentAge = 60;
	numberDaysComplete[0] = { 30 };
	SetDegreeProgram(SECURITY);
}

SecurityStudent::SecurityStudent(string ID, string First, string Last, string Email, double Age, double * Days, Degree degree)
{
	SetDegreeProgram(SECURITY);
}

Degree SecurityStudent::GetDegreeProgram()
{
	return SECURITY;
}

void SecurityStudent::SetDegreeProgram(Degree degree)
{
	this->degreeProgram = SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << endl;
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
	delete this;
	cout << "Security destructor called" << endl;
}