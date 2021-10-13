
#include "roster.h"
using namespace std;

//Destructor
Roster::~Roster() {
	for (vector<Student*>::iterator i = classRosterArray.begin(); i != classRosterArray.end(); ++i) {
		classRosterArray.pop_back();
	}
}

void Roster::Add(Student* currStudent) {
	classRosterArray.push_back(currStudent);
}

void Roster::Remove(std::string studentID) {
	unsigned long int i;
	bool foundStudent = true;

	for (i = 0; i < classRosterArray.size(); ++i) {
		if (studentID == classRosterArray[i]->GetID()) {
			classRosterArray.erase(classRosterArray.begin() + i);
			foundStudent = false;
		}
	}

	if (foundStudent) {
		cout << "A student with this ID was not found." << endl << endl;
	}

}

void Roster::PrintAll() {
	unsigned long int i;

	if (classRosterArray.size() == 0) {
		classRosterArray[0]->PrintID();
		classRosterArray[0]->PrintFirstName();
		classRosterArray[0]->PrintLastName();
		classRosterArray[0]->PrintAge();
		classRosterArray[0]->PrintNumDaysToCompleteCourses();
		classRosterArray[0]->PrintDegree();
		cout << endl;
		cout << endl;
		return;
	}
	else if (classRosterArray.size() < 0) {
		cout << "There are no students on the roster." << endl;
		cout << endl;
		return;
	}
	else for (i = 0; i < classRosterArray.size(); ++i) {
		classRosterArray[i]->PrintID();
		classRosterArray[i]->PrintFirstName();
		classRosterArray[i]->PrintLastName();
		classRosterArray[i]->PrintAge();
		classRosterArray[i]->PrintNumDaysToCompleteCourses();
		classRosterArray[i]->PrintDegree();
		cout << endl;
	}

	cout << endl;
}

void Roster::PrintAverageDaysInCourse(std::string studentID) {
	unsigned long int i;
	Student currStudent("n/a", "n/a", "n/a", "n/a", -1, { -1, -1, -1 }, SECURITY);
	int daysSum = 0;
	int daysAvg = 0;

	for (i = 0; i < classRosterArray.size(); ++i) {
		
		if (classRosterArray[i]->GetID() == studentID) {
			currStudent = *classRosterArray[i];

			daysSum = (currStudent.GetNumDaysToCompleteCourses(0) + currStudent.GetNumDaysToCompleteCourses(1) + currStudent.GetNumDaysToCompleteCourses(2));
			daysAvg = (daysSum / 3);

			cout << "Average Days in Course for " << currStudent.GetFirstName() << ": " << daysAvg << endl;
			return;
		}
	}

	cout << "There are no students registered with that ID.";

}

void Roster::PrintInvalidEmails() {
	unsigned long int i;

	for (i = 0; i < classRosterArray.size(); ++i) {

		if (classRosterArray[i]->GetEmail().find('@') == std::string::npos ||
			classRosterArray[i]->GetEmail().find('.') == std::string::npos || classRosterArray[i]->GetEmail().find(' ') != std::string::npos) {
			cout << classRosterArray[i]->GetID() << " : " << classRosterArray[i]->GetEmail() << endl;
		}

	}

	cout << endl;
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
	unsigned long int i;
	bool foundInfo = false;
	Student currStudent("n/a", "n/a", "n/a", "n/a", -1, { -1, -1, -1 }, SECURITY);

	for (i = 0; i < classRosterArray.size(); ++i) {

		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			currStudent = *classRosterArray.at(i);
			currStudent.PrintID();
			currStudent.PrintFirstName();
			currStudent.PrintLastName();
			currStudent.PrintAge();
			currStudent.PrintNumDaysToCompleteCourses();
			currStudent.PrintDegree();
			cout << endl;
		}
	}

	if (foundInfo) {
		cout << "No students are enrolled in that degree program." << endl;
	}

	cout << endl;

}

int Roster::GetNumOfStudents() {
	return classRosterArray.size();
}

Student* Roster::GetStudent(int rosterPosition) {
	return classRosterArray.at(rosterPosition);
}