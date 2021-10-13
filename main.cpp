#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cstring>
#include <cassert>
using namespace std;

#include "roster.h"
#include <iostream>

int main() {

	Roster classRoster;
	int i;

	//Project information.
	cout << "Course: C867 Scripting & Programming" << endl << "Language Used : C++" <<
		endl << "Student ID: 001994084" << endl << "Name: Steven A. Jones" << endl << endl;

	//Create Students.
	Student A1("A1", "John", "Smith", "John1989@gm ail.com", 20, { 30, 35, 40 }, SECURITY);
	Student A2("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, { 50, 30, 40 }, NETWORK);
	Student A3("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, { 20, 40, 33 }, SOFTWARE);
	Student A4("A4", "Erin", "Black", "Erin.black@comcast.net", 22, { 50, 58, 40 }, SECURITY);
	Student A5("A5", "Steven", "Jones", "sjo1956@wgu.edu", 27, { 30, 50, 32 }, SOFTWARE);

	//Populate classRoster with Student objects.
	classRoster.Add(&A1);
	classRoster.Add(&A2);
	classRoster.Add(&A3);
	classRoster.Add(&A4);
	classRoster.Add(&A5);

	//Print all student information from classRoster.
	cout << "Full class roster:" << endl;
	classRoster.PrintAll();

	//Print a list of all of the invalid emails in the classRoster.
	cout << "Invalid email addresses:" << endl;
	classRoster.PrintInvalidEmails();

	//Print the averageDaysInCourse for each student in the roster.
	cout << "Average days per student:" << endl;
	for (i = 0; i < classRoster.GetNumOfStudents(); ++i) {
		classRoster.PrintAverageDaysInCourse(classRoster.GetStudent(i)->GetID());
	}

	cout << endl;

	//Print student information for a particular degree program.
	cout << "Student information by degree type:" << endl;
	classRoster.PrintByDegreeProgram(SOFTWARE);

	//Remove a student by specifying their student ID.
	classRoster.Remove("A3");

	//Print all student information from classRoster again.
	cout << "Full class roster:" << endl;
	classRoster.PrintAll();

	//Attempt to remove the already removed A3 student.
	classRoster.Remove("A3");

	return 0;
}
/*const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Steven,Jones,sjo1956@wgu.edu,27,40,50,32,SOFTWARE" };*/
