#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Shape.h"

class Rect : public Shape
{
	friend ostream& operator<< (ostream&, const Rect&);
public:
	// constructor, destuctor
	Rect();
	Rect(string n) : Shape(n), width(0), length(0) {};
	Rect(Position temp, int w, int h, double ang, COLORREF clr, string n);
	Rect(const Rect& rect);
	~Rect();

	//member functions
	virtual void draw(ostream&);					// 그리기 함수 ( 정보 출력 ) 

	//getter
	int Width() const { return width; }				// 밑변
	int Length() const { return length; }			// 높이
	int Area() const;								// 넓이

	//setter 
	void Set_Width(int w) { width = w; }			// 밑변 대입
	void Set_Length(int l) { length = l; }			// 높이 대입

	// operator Overloading
	Rect& operator=(const Rect& rect);

protected:
	int width;
	int length;
};

#endif // !RECTANGLE_H