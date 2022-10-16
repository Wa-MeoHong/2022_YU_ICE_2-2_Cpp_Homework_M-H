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
	virtual void draw(ostream&);					// �׸��� �Լ� ( ���� ��� ) 

	//getter
	int Height() const { return height; }				// ����
	int Sur_Area() const;							// ����
	int Volume() const;								// ����

	//setter 
	void Set_Height(int h) { height = h; }				// ���� ����

	// operator Overloading
	Hexahedron& operator=(const Hexahedron& cyl);

protected:
	int height;
};


#endif // !HEXAHEDRON_H


