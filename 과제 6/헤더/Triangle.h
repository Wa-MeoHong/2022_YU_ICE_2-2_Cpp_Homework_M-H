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
	virtual void draw(ostream&);					// �׸��� �Լ� ( ���� ��� ) 

	//getter
	int Base() const { return base; }				// �غ�
	int Height() const { return height; }			// ����
	int Area() const;								// ����
	
	//setter 
	void Set_Base(int b) { base = b; }				// �غ� ����
	void Set_Height(int h) { height = h; }			// ���� ����

	// operator Overloading
	Triangle& operator=(const Triangle& tri);

protected:
	int base;
	int height;

};


#endif // !TRIANGLE_H


