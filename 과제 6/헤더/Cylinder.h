#ifndef CYLINDER_H
#define CYLINDER_H

#include <iostream>
#include "Shape.h"
#include "Circle.h"

using namespace std;

class Cylinder : public Circle
{
	friend ostream& operator<< (ostream&, const Cylinder&);
public:
	// constructor, destuctor
	Cylinder();
	Cylinder(string n) : Circle(n), height(0) {};
	Cylinder(Position temp, int r, int h, double ang, COLORREF clr, string n);
	Cylinder(const Cylinder& cyl);
	virtual ~Cylinder();

	//member functions
	virtual void draw(ostream&);					// 그리기 함수 ( 정보 출력 ) 

	//getter
	int Height() const { return height; }				// 높이
	double Sur_Area() const;							// 넓이
	double Volume() const;

	//setter 
	void Set_Height(int h) { height = h; }				// 반지름 대입

	// operator Overloading
	Cylinder& operator=(const Cylinder& cyl);

protected:
	int height;
};



#endif // !CYLINDER_H

