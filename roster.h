#ifndef ROSTER_H
#define ROSTER_H


#include "student.h"

class Roster {
	public:
		void Add(Student* currStudent);
		void Remove(std::string studentID);
		void PrintAll();
		void PrintAverageDaysInCourse(std::string studentID);
		void PrintInvalidEmails();
		void PrintByDegreeProgram(DegreeProgram degreeProgram);
		int GetNumOfStudents();
		Student* GetStudent(int rosterPosition);
		~Roster();
	private:
		std::vector<Student*> classRosterArray;
};
#endif