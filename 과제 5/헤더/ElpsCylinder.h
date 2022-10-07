#ifndef ELPSCYL_H
#define ELPSCYL_H

#include "Elps.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

class ElpsCylinder : public Elps
{
	friend ostream& operator<<(ostream& ostr, const ElpsCylinder& elpcyl);
public:
	// constructor
	ElpsCylinder();
	ElpsCylinder(string n);
	ElpsCylinder(int px, int py, double r1, double r2, double h, double ang, COLORREF clr, string n);
	// destuctor
	virtual ~ElpsCylinder();
	
	//member functions
	void draw();
	void print(ostream&) const;				// ���

	// getter
	double Height() const { return height; }
	double Area() const;					// Ÿ������� �ѳ���
	double Volume() const;					// Ÿ������� ����

	// operator Overloading
	ElpsCylinder& operator=(const ElpsCylinder& right);

protected:
	double height;				// Ÿ������� ����
};
#endif // !ELPSCYL_H



