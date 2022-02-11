#include<iostream>
#include<string>
#include "student.h"
#include "roster.h"


using namespace std;

int main() {
	cout << "Marquitta McClendon" << endl;
	cout << "Student ID: 001304269" << endl;
	cout << "Scripting and Programming Applications - C867" << endl;
	cout << "Programming Language used: C++ " << endl;
	cout << "**************************************************" << endl <<endl;

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,65,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",//jack not being read
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Marquitta,McClendon,mmcc351@wgu.edu,47,5,45,30,SOFTWARE" };
	
	//Iterate through all students
	roster classRoster;
	int i = 0;
	for (i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	}
	
	// Prints entire roster
	classRoster.printAll();
	cout << endl;

	// Print Invalid Emails
	classRoster.printinvalidEmails();

	//Average Days in Course	
	for (i = 0; i < 5; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
	}
	cout << endl;

	//Print by Degree Program
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	//Remove Student
	classRoster.remove("A3");
	cout << endl;

	//Print Updated Roster
	classRoster.printAll();
	cout << endl;

	//Calling Removed Student
	classRoster.remove("A3");
	cout << endl;
	
	

	
	 
	
	

	

		

	
	

	



	//classRoster.printAll



	//deconstructor to release memory



	return 0;
}