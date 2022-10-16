#ifndef HEXAHEDRON_H
#define HEXAHEDRON_H

#include <iostream>
#include "Shape.h"
#include "Rectangle.h"

using namespace std;

class Hexahedron : public Rect
{
	friend ostream& operator<< (ostream&, const Hexahedron&);
public:
	// constructor, destuctor
	Hexahedron();
	Hexahedron(string n) : Rect(n), height(0) {};
	Hexahedron(Position temp, int w, int l, int h, double ang, COLORREF clr, string n);
	Hexahedron(const Hexahedron& cyl);
	virtual ~Hexahedron();

	//member functions
	virtual void draw(ostream&);					// 그리기 함수 ( 정보 출력 ) 

	//getter
	int Height() const { return height; }				// 높이
	int Sur_Area() const;							// 넓이
	int Volume() const;								// 부피

	//setter 
	void Set_Height(int h) { height = h; }				// 높이 대입

	// operator Overloading
	Hexahedron& operator=(const Hexahedron& cyl);

protected:
	int height;
};


#endif // !HEXAHEDRON_H


