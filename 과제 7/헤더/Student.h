#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Person.h"
#include "Time.h"

using namespace std;

class Time;

class Student : public Person					// Person Ŭ������ ��ӹ���
{
	// operator Overloading (��� ������)
	friend ostream& operator<< (ostream&, const Student&);
public:
	// constructor
	Student();								// �⺻ ������
	Student(int id, string n, Date bd, Time avt, double GPA);	// ���ڸ� �޴� ������
	Student(const Student& );				// ���� ������

	// getter ( �л� ������ ��ȯ )	( �й�, ���� )	
	int ST_id() const { return st_id; }
	double GPA() const { return gpa; }

	// setter ( �л� ���� (�й�, ����, �����ð�) ���� �Լ��� )
	void set_ID(int id) { st_id = id; }
	void set_GPA(double g) { gpa = g; }
	void set_AVT(Time t) { arrivalTime = t; }

	// operator Overloading ( ��, �����ð��� �������� )
	Student& operator=(const Student& st);
	bool operator<(const Student& st);
	bool operator<=(const Student& st);
	bool operator>(const Student& st);
	bool operator>=(const Student& st);
	bool operator==(const Student& st);

private:
	int st_id  ;
	double gpa ;
	Time arrivalTime;
};
#endif
