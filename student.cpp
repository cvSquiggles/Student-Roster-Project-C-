using namespace std;

#include "student.h"

//Constructor
Student::Student(std::string idIn, std::string firstNameIn, std::string lastNameIn, std::string emailIn,
	int ageIn, std::vector<int> numDaysToCompleteCoursesIn, DegreeProgram degreeProgramIn) {
	id = idIn;
	firstName = firstNameIn;
	lastName = lastNameIn;
	email = emailIn;
	age = ageIn;
	numDaysToCompleteCourses = numDaysToCompleteCoursesIn;
	degreeProgram = degreeProgramIn;
}

//Get Student Information
string Student::GetID() {
	return id;
}

string Student::GetFirstName() {
	return firstName;
}

string Student::GetLastName() {
	return lastName;
}

string Student::GetEmail() {
	return email;
}

int Student::GetAge() {
	return age;
}

int Student::GetNumDaysToCompleteCourses(int course) {
	return numDaysToCompleteCourses.at(course);
}

DegreeProgram Student::GetDegreeProgram() {
	return degreeProgram;
}

//Set Student Information
void Student::SetID(string idIn) {
	id = idIn;
}

void Student::SetFirstName(string firstNameIn) {
	firstName = firstNameIn;
}

void Student::SetLastName(string lastNameIn) {
	lastName = lastNameIn;
}

void Student::SetEmailAddress(string emailIn) {
	email = emailIn;
}

void Student::SetAge(int ageIn) {
	age = ageIn;
}

void Student::SetNumDaysToCompleteCourses(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
	numDaysToCompleteCourses[0] = daysInCourse1;
	numDaysToCompleteCourses[1] = daysInCourse2;
	numDaysToCompleteCourses[2] = daysInCourse3;
}

void Student::SetDegreeProgram(DegreeProgram degree) {
	degreeProgram = degree;
}

//Print Student Information
void Student::PrintID() {
	cout << id << "\t";
}
void Student::PrintFirstName() {
	cout << "First Name: " << firstName << "\t";
}
void Student::PrintLastName() {
	cout << "Last Name: " << lastName  << "\t";
}
void Student::PrintEmail() {
	cout << "Email: " << email << "\t";
}
void Student::PrintAge() {
	cout << "Age: " << age << "\t";
}
void Student::PrintNumDaysToCompleteCourses() {
	unsigned long int i;

	cout << "daysInCourse: {";

	for (i = 0; i < numDaysToCompleteCourses.size(); ++i) {
		cout << numDaysToCompleteCourses[i];

		if (i != numDaysToCompleteCourses.size() - 1) {
			cout << ", ";
		}
		else {
			cout << "}" << "\t";
		}
	}
}
void Student::PrintDegree() {
	if (degreeProgram == 0) {
		cout << "Degree Program: SECURITY \t";
	}
	else if (degreeProgram == 1) {
		cout << "Degree Program: NETWORK \t";
	}
	else if (degreeProgram == 2) {
		cout << "Degree Program: SOFTWARE \t";
	}
}