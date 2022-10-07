#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>


using namespace std;

class Shape									// Shape Ŭ���� ( ��� ) 
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
	void draw();							// ���� �׸��� �Լ�
	void rotate(double rt_angle) { angle += rt_angle; }			// ���� ���� ( ���� ) 
	void move(int dx, int dy) { pos_x += dx; pos_y += dy; }		// ��ǥ �̵� 
	void print(ostream&) const ;								// Shape ��ü ���

	//getter
	int Pos_X() const { return pos_x; }		// X ��ǥ
	int Pos_Y() const { return pos_y; }		// Y ��ǥ
	string Name() const { return name; }	// �̸�
	//setter 
	void set_Pos_X(int x) { pos_x = x; }		// X ��ǥ ����
	void set_Pos_Y(int y) { pos_y = y; }		// Y ��ǥ ����
	void NameSet(string n) { name = n; }	// �̸� ����

	// operator Overloading
	Shape& operator=(const Shape& s);

protected:
	int pos_x;								// X ��ǥ
	int pos_y;								// Y ��ǥ
	double angle;							// ����
	string name;							// �̸�
	COLORREF color;							// ����
};

#endif // !SHAPE_H
