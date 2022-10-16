/*
  ���ϸ� : "HW6_21912193_�Ŵ�ȫ"
  ���α׷��� ���� �� �⺻ ���:
	- Ŭ������ ����, ����Ͽ� ������ ������ �������
  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 10�� 14��)
  ���� Update : Version 1.1.0, 2022�� 10�� 16��(�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������	  ������			����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
	�Ŵ�ȫ		 2022/10/14		v1.0.0		  �����ۼ�
	�Ŵ�ȫ		 2022/10/16		v1.1.0		  �ϼ�
===========================================================================================================
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Cylinder.h"
#include "Hexahedron.h"
#include "Prism.h"

using namespace std;

#define OUTPUT "Output.txt"
#define NUM_SHAPES 7

int main(void)
{
	ofstream fout;

	// ���� ��ü�� 
	Shape s1(Position(1, 1), 0.0, RGB_BLUE, "Blue Shape");
	Triangle t1(Position(2, 2), 3, 4, 0, RGB_RED, "Red Triangle");
	Circle cir(Position(6, 6), 6, 0, RGB_MAGENTA, "Magenta Circle");
	Rect r1(Position(4, 4), 1, 2, 0, RGB_YELLOW, "Yellow Rectangle");
	Cylinder cyl(Position(7, 7), 8, 6, 0, RGB_WHITE, "White Cylinder");
	Hexahedron hx1(Position(5, 5), 5, 6, 7, 0, RGB_ORANGE, "Orange Hexahedtron");
	Prism p1(Position(3, 3), 6, 7, 8, 0, RGB_GREEN, "Green Prism");
	
	// ������ ��� ����Ŭ���� �迭(������ �迭)
	Shape* shapes[NUM_SHAPES];
	

	fout.open(OUTPUT);
	if (fout.fail())
	{
		cout << "Failed to open output.txt !!" << endl;
		exit(-1);
	}
	// �迭�� ���
	shapes[0] = &s1; shapes[1] = &t1; shapes[2] = &p1;
	shapes[3] = &r1; shapes[4] = &hx1; shapes[5] = &cir;
	shapes[6] = &cyl;

	// ���
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		shapes[i]->draw(fout);
	}

	fout.close();
	return 0;
}