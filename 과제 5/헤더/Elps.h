#ifndef ELPS_H
#define ELPS_H

#include "Shape.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>


using namespace std;

class Elps : public Shape				// 타원 클래스 ellipse ( Shape를 상속 받음 ) 
{
	friend ostream& operator<< (ostream&, const Elps&);

public:
	// constructor
	Elps();
	Elps(string name);
	Elps(int px, int py, double r1, double r2, double ang, COLORREF clr, string name);
	// destructor
	~Elps();

	//member functions
	void draw();										// 타원 그리기 함수
	void print(ostream&) const;							// Elps 객체 

	// getter
	double Area() const;
	double Radius_1() const { return radius_1; }		// 가로 반지름 r1
	double Radius_2() const { return radius_2; }		// 세로 반지름 r2
	
	// setter
	void setRadius(double r1, double r2) { radius_1 = r1, radius_2 = r2; }	// 타원 반지름 설정

	// operator Overloading
	Elps& operator=(const Elps& elp);

protected:
	double radius_1;
	double radius_2;
};

#endif // !ELPS_H
