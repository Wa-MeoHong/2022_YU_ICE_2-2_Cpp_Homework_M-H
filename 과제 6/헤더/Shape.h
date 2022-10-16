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
	virtual void draw(ostream& ostr);		// 도형 그리기 함수
	void print(ostream&) const;				// Shape 객체 출력

	//getter
	Position Pos() const { return pos;  }	// 좌표 반환
	string Name() const { return name; }	// 이름
	COLORREF Color() const { return color; }	// 색깔

	//setter 
	void SetPos(Position temp) { pos = temp; }	// 좌표 대입
	void NameSet(string n) { name = n; }		// 이름 설정
	
	// operator Overloading
	Shape& operator=(const Shape& s);

protected:
	Position pos;							// 좌표
	double angle;							// 각도
	string name;							// 이름
	COLORREF color;							// 색깔
};


#endif // !SHAPE_H

