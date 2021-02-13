#include <iostream>
#include "softwareStudent.h"

SoftwareStudent::SoftwareStudent()
{
	studentID = "333333333";
	studentFirstName = "Bob";
	studentLastName = "Davis";
	studentEmail = "BobbyD@email.com";
	studentAge = 60;
	numberDaysComplete[2] = { 25 };
	SetDegreeProgram(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string ID, string First, string Last, string Email, double Age, double * Days, Degree degree)
{
	SetDegreeProgram(SOFTWARE);
}

Degree SoftwareStudent::GetDegreeProgram()
{
	return SOFTWARE;
}

void SoftwareStudent::SetDegreeProgram(Degree degree)
{
	this->degreeProgram = SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << endl;
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
	delete this;
	cout << "Software destructor called" << endl;
}