#pragma once
#include<iostream>
#include "degree.h"
using namespace std;

class Student{

private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int numDaysToComplete [3];
		DegreeProgram degreeProgram;
		

public:
	Student();
	Student(string xstudentID, string xfirstName, string xlastName, string xemailAddress, int xage,int* xnumDaysToComplete, DegreeProgram xdegreeProgram);
	void print();

//Setters
	void SetStudentID(string xstudentID);
	void SetStudentFirstName(string xfirstName);
	void SetStudentLastName(string xlastName);
	void SetEmailAddress(string xemailAddress);
	void SetAge(int xage);
	void SetNumDaysToComplete(int* xnumDaysToComplete);
	void SetDegreePrograms(DegreeProgram xdegreeProgram);

	//Getters
	
	string GetStudentID()const;
	string GetStudentFirstName()const;
	string GetStudentLastName()const;
	string GetEmailAddress()const;
	int GetAge()const;
	int* GetNumDaysToComplete();
	DegreeProgram GetDegreePrograms()const;

	};

