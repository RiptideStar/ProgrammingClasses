#include "student.h"

int main()
{
	double honor = 3.6;
	Student s1("G10", 3.9);
	Student s2("G20", 3.5);

	s1.print();
	s2.print();

	//write code to test Student::isLessThanByID
	if (s1.isLessThanByID(s2))
		cout << "Student 1's id is less than Student 2's ID" << endl;
	else
		cout << "Student 1's id is not less than Student 2's ID" << endl;
	

	//write code to test Student::qualifyForHonor
	if (s1.qualifyForHonor(honor))
		cout << "Student 1 qualifies for honor (minimum gpa: " << honor << ")" << endl;
	else
		cout << "Student 1 doesn't qualify for honor (minimum gpa: " << honor << ")" << endl;
	if (s2.qualifyForHonor(honor))
		cout << "Student 2 qualifies for honor (minimum gpa: " << honor << ")" << endl;
	else
		cout << "Student 2 doesn't qualify for honor (minimum gpa: " << honor << ")" << endl;

	return 0;
}
