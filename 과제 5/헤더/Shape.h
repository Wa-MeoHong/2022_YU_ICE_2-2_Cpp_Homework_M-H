#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>


using namespace std;

class Shape									// Shape 클래스 ( 모양 ) 
{
	friend ostream& operator<<(ostream& out, const Shape s);
public:
	// constructor
	Shape();
	Shape(string name);
	Shape(int px, int py, double angle, COLORREF color, string name);
	// destuctor
	~Shape();

	//member functions
	void draw();							// 도형 그리기 함수
	void rotate(double rt_angle) { angle += rt_angle; }			// 각도 변경 ( 증가 ) 
	void move(int dx, int dy) { pos_x += dx; pos_y += dy; }		// 좌표 이동 
	void print(ostream&) const ;								// Shape 객체 출력

	//getter
	int Pos_X() const { return pos_x; }		// X 좌표
	int Pos_Y() const { return pos_y; }		// Y 좌표
	string Name() const { return name; }	// 이름
	//setter 
	void set_Pos_X(int x) { pos_x = x; }		// X 좌표 설정
	void set_Pos_Y(int y) { pos_y = y; }		// Y 좌표 설정
	void NameSet(string n) { name = n; }	// 이름 설정

	// operator Overloading
	Shape& operator=(const Shape& s);

protected:
	int pos_x;								// X 좌표
	int pos_y;								// Y 좌표
	double angle;							// 각도
	string name;							// 이름
	COLORREF color;							// 색깔
};

#endif // !SHAPE_H
