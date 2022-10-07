#ifndef ELPS_H
#define ELPS_H

#include "Shape.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>


using namespace std;

class Elps : public Shape				// Ÿ�� Ŭ���� ellipse ( Shape�� ��� ���� ) 
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
	void draw();										// Ÿ�� �׸��� �Լ�
	void print(ostream&) const;							// Elps ��ü 

	// getter
	double Area() const;
	double Radius_1() const { return radius_1; }		// ���� ������ r1
	double Radius_2() const { return radius_2; }		// ���� ������ r2
	
	// setter
	void setRadius(double r1, double r2) { radius_1 = r1, radius_2 = r2; }	// Ÿ�� ������ ����

	
	Elps& operator=(const Elps& elp);

protected:
	double radius_1;
	double radius_2;
};

#endif // !ELPS_H