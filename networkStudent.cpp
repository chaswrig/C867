#include <iostream>
#include "networkStudent.h"

NetworkStudent::NetworkStudent()
{
	studentID = "222222222";
	studentFirstName = "Bob";
	studentLastName = "Davis";
	studentEmail = "BobbyD@email.com";
	studentAge = 60;
	numberDaysComplete[1] = { 60 };
	SetDegreeProgram(NETWORK);
}

NetworkStudent::NetworkStudent(string ID, string First, string Last, string Email, double Age, double * Days, Degree degree)
{
	SetDegreeProgram(NETWORK);
}

Degree NetworkStudent::GetDegreeProgram()
{
	return NETWORK;
}

void NetworkStudent::SetDegreeProgram(Degree degree)
{
	this->degreeProgram = NETWORK;
}

void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << endl;
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
	delete this;
	cout << "Network destructor called" << endl;
}