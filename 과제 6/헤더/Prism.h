#ifndef PRISM_H
#define PRISM_H

#include <iostream>
#include "Shape.h"
#include "Triangle.h"

class Prism : public Triangle
{
	friend ostream& operator<< (ostream&, const Prism& );
public:
	// constructor, destuctor

	Prism();
	Prism(string n) : Triangle(n), pri_height(0) {};
	Prism(Position temp, int b, int h, int ph, double ang, COLORREF clr, string n);
	Prism(const Prism& pri);
	virtual ~Prism();

	//member functions
	virtual void draw(ostream&);					// 그리기 함수 ( 정보 출력 ) 

	//getter
	int Pri_Hei() const { return pri_height; }		// 프리즘 높이
	double Sur_Area() const;
	double Volume() const;

	//setter 
	void Set_PriH(int h) { pri_height = h; }				// 높이 대입

	// operator Overloading
	Prism& operator=(const Prism& pri);

protected:
	int pri_height;
};


#endif // !PRISM_H
