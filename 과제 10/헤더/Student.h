#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"

using namespace std;


class Student
{
	friend ostream& operator<<(ostream& ostr, Student& st)			// 출력함수
	{
		// print format : [ stid, name, birth, gpa ]
		ostr.setf(ios::left);
		ostr << "[ " << st.StID() << ", " << st.Name() << ", "
			<< st.BirthDate() << ", " ;
		ostr.precision(3);	ostr.fixed;
		ostr << st.GPA() << " ]";
		return ostr;
	}
public:
	// constructor
	Student() : _StID(0), _name(""), _birthDate(1, 1, 1), _GPA(0.0) {};
	Student(int sid, string name, Date pd, double gpa)
		: _StID(sid), _name(name), _birthDate(pd), _GPA(gpa) {};

	// getter
	int StID() { return _StID; }
	Date BirthDate() { return _birthDate; }
	string Name() { return _name; }
	double GPA() { return _GPA; }

	// setter 
	void SetStID(int stid) { _StID = stid; }
	void SetBirth(Date pd) { _birthDate = pd; }
	void SetName(string nm) { _name = nm; }
	void SetGPA(double gpa) { _GPA = gpa; }


private:
	int _StID;
	string _name;
	Date _birthDate;
	double _GPA;
};
#endif // !STUDENT_H


