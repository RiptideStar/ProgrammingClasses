#include "student.h"
#include <cstring>

//implement the required 3 functions here
void Student::print() const
{
	cout << id << '\t' << gpa << endl;
}

Student::Student(const char initId[], double gpa) {
	strcpy(id, initId);
	Student::gpa = gpa;
}

bool Student::isLessThanByID(const Student& aStudent) const {
	return strcmp(id, aStudent.id) < 0;
}

bool Student::qualifyForHonor(double minGpaForHonor) const {
	return gpa > minGpaForHonor;
}
