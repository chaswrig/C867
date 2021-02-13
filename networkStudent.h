#pragma once
#include <string>
#include "student.h"

class NetworkStudent : public Student
{
public:
	NetworkStudent();
	NetworkStudent(string ID, string First, string Last, string Email, double Age, double* Days, Degree degree);

	Degree GetDegreeProgram();
	void SetDegreeProgram(Degree degree);
	void print();

	~NetworkStudent();
};