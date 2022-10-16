#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
#include <conio.h>
#include "Color.h"
#include "Position.h"

using namespace std;

#define PI 3.14159265358979323846			// pi

class Positon; 
class Shape
{
	friend ostream& operator<<(ostream& ostr, const Shape& s);
public:
	// constructor, destuctor
	Shape();
	Shape(string n);
	Shape(Position pos, double ang,  COLORREF clr, string n );
	virtual ~Shape();

	//member functions
	virtual void draw(ostream& ostr);		// ���� �׸��� �Լ�
	void print(ostream&) const;				// Shape ��ü ���

	//getter
	Position Pos() const { return pos;  }	// ��ǥ ��ȯ
	string Name() const { return name; }	// �̸�
	COLORREF Color() const { return color; }	// ����

	//setter 
	void SetPos(Position temp) { pos = temp; }	// ��ǥ ����
	void NameSet(string n) { name = n; }		// �̸� ����
	
	// operator Overloading
	Shape& operator=(const Shape& s);

protected:
	Position pos;							// ��ǥ
	double angle;							// ����
	string name;							// �̸�
	COLORREF color;							// ����
};


#endif // !SHAPE_H

