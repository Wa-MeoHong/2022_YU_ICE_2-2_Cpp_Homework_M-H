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
	virtual void draw(ostream&);					// �׸��� �Լ� ( ���� ��� ) 

	//getter
	int Width() const { return width; }				// �غ�
	int Length() const { return length; }			// ����
	int Area() const;								// ����

	//setter 
	void Set_Width(int w) { width = w; }			// �غ� ����
	void Set_Length(int l) { length = l; }			// ���� ����

	// operator Overloading
	Rect& operator=(const Rect& rect);

protected:
	int width;
	int length;
};

#endif // !RECTANGLE_H