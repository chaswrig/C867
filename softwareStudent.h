#pragma once
#include <string>
#include "student.h"

class SoftwareStudent : public Student
{
public:
	SoftwareStudent();
	SoftwareStudent(string ID, string First, string Last, string Email, double Age, double* Days, Degree degree);

	Degree GetDegreeProgram();
	void SetDegreeProgram(Degree degree);
	void print();

	~SoftwareStudent();
};