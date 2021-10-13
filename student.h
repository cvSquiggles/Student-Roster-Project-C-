#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include "degree.h"

class Student {
public:
	//Constructor
	Student(std::string idIn, std::string firstNameIn, std::string lastNameIn, std::string emailIn,
		int ageIn, std::vector<int> numDaysToCompleteCoursesIn, DegreeProgram degreeProgramIn);
	// Get functions
	std::string GetID();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetEmail();
	int GetAge();
	int GetNumDaysToCompleteCourses(int course);
	DegreeProgram GetDegreeProgram();
	// Set functions
	void SetID(std::string idIn);
	void SetFirstName(std::string firstNameIn);
	void SetLastName(std::string lastNameIn);
	void SetEmailAddress(std::string emailIn);
	void SetAge(int ageIn);
	void SetNumDaysToCompleteCourses(int daysInCourse1, int daysInCourse2, int daysInCourse3);
	void SetDegreeProgram(DegreeProgram degree);
	// Print functions
	void PrintID();
	void PrintFirstName();
	void PrintLastName();
	void PrintEmail();
	void PrintAge();
	void PrintNumDaysToCompleteCourses();
	void PrintDegree();
private:
	std::string id = "n/a";
	std::string firstName = "n/a";
	std::string lastName = "n/a";
	std::string email = "n/a";
	int age = -1;
	std::vector<int> numDaysToCompleteCourses{ -1, -1, -1 };
	DegreeProgram degreeProgram = SECURITY;
};

#endif