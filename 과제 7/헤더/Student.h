#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Person.h"
#include "Time.h"

using namespace std;

class Time;

class Student : public Person					// Person 클래스를 상속받음
{
	// operator Overloading (출력 연산자)
	friend ostream& operator<< (ostream&, const Student&);
public:
	// constructor
	Student();								// 기본 생성자
	Student(int id, string n, Date bd, Time avt, double GPA);	// 인자를 받는 생성자
	Student(const Student& );				// 복제 생성자

	// getter ( 학생 정보를 반환 )	( 학번, 성적 )	
	int ST_id() const { return st_id; }
	double GPA() const { return gpa; }

	// setter ( 학생 정보 (학번, 성적, 도착시간) 설정 함수들 )
	void set_ID(int id) { st_id = id; }
	void set_GPA(double g) { gpa = g; }
	void set_AVT(Time t) { arrivalTime = t; }

	// operator Overloading ( 비교, 도착시간을 기준으로 )
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
