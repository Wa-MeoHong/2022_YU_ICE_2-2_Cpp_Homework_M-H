#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "Shape.h"
#include "Position.h"

class Triangle : public Shape
{
	friend ostream& operator<< (ostream&, const Triangle&);
public:
	// constructor, destuctor
	Triangle();
	Triangle(string n) : Shape(n), base(0), height(0) {};
	Triangle(Position temp, int b, int h, double ang, COLORREF clr, string n);
	Triangle(const Triangle& tri);
	virtual ~Triangle();

	//member functions
	virtual void draw(ostream&);					// 그리기 함수 ( 정보 출력 ) 

	//getter
	int Base() const { return base; }				// 밑변
	int Height() const { return height; }			// 높이
	int Area() const;								// 넓이
	
	//setter 
	void Set_Base(int b) { base = b; }				// 밑변 대입
	void Set_Height(int h) { height = h; }			// 높이 대입

	// operator Overloading
	Triangle& operator=(const Triangle& tri);

protected:
	int base;
	int height;

};


#endif // !TRIANGLE_H


