/*
  파일명 : "HW6_21912193_신대홍"
  프로그램의 목적 및 기본 기능:
	- 클래스를 생성, 상속하여 도형의 정보를 출력하자
  프로그램 작성자 : 신대홍(2022년 10월 14일)
  최종 Update : Version 1.1.0, 2022년 10월 16일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자	  수정일			버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
	신대홍		 2022/10/14		v1.0.0		  최초작성
	신대홍		 2022/10/16		v1.1.0		  완성
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

	// 도형 객체들 
	Shape s1(Position(1, 1), 0.0, RGB_BLUE, "Blue Shape");
	Triangle t1(Position(2, 2), 3, 4, 0, RGB_RED, "Red Triangle");
	Circle cir(Position(6, 6), 6, 0, RGB_MAGENTA, "Magenta Circle");
	Rect r1(Position(4, 4), 1, 2, 0, RGB_YELLOW, "Yellow Rectangle");
	Cylinder cyl(Position(7, 7), 8, 6, 0, RGB_WHITE, "White Cylinder");
	Hexahedron hx1(Position(5, 5), 5, 6, 7, 0, RGB_ORANGE, "Orange Hexahedtron");
	Prism p1(Position(3, 3), 6, 7, 8, 0, RGB_GREEN, "Green Prism");
	
	// 도형을 담는 상위클래스 배열(포인터 배열)
	Shape* shapes[NUM_SHAPES];
	

	fout.open(OUTPUT);
	if (fout.fail())
	{
		cout << "Failed to open output.txt !!" << endl;
		exit(-1);
	}
	// 배열에 담기
	shapes[0] = &s1; shapes[1] = &t1; shapes[2] = &p1;
	shapes[3] = &r1; shapes[4] = &hx1; shapes[5] = &cir;
	shapes[6] = &cyl;

	// 출력
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		shapes[i]->draw(fout);
	}

	fout.close();
	return 0;
}