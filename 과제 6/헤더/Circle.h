#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Shape.h"

using namespace std;

class Circle : public Shape
{
	friend ostream& operator<< (ostream&, const Circle&);
public:
	// constructor, destuctor
	Circle();
	Circle(string n) : Shape(n), radius(0) {};
	Circle(Position temp, int r, double ang, COLORREF clr, string n);
	Circle(const Circle& tri);
	virtual ~Circle();

	//member functions
	virtual void draw(ostream&);					// 그리기 함수 ( 정보 출력 ) 

	//getter
	int Ra() const { return radius; }				// 반지름
	double Area() const;								// 넓이

	//setter 
	void Set_Ra(int r) { radius = r; }				// 반지름 대입

	// operator Overloading
	Circle& operator=(const Circle& tri);

protected:
	int radius;

};


#endif // !CIRCLE_H


