/*
  파일명 : "HW5_21912193_신대홍"
  프로그램의 목적 및 기본 기능:
	- 클래스 Shape, Elps, ElpsCylinder를 만들고, 데이터를 생성, 출력함
  프로그램 작성자 : 신대홍(2022년 10월 7일)
  최종 Update : Version 1.0.0, 2022년 10월 7일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자	  수정일		 버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
	신대홍		 2022/10/07		v1.0.0		  최초작성
	신대홍		 2022/10/08		v1.1.0		  완성
===========================================================================================================
*/

#include "Color.h"
#include "Shape.h"
#include "Elps.h"
#include "ElpsCylinder.h"
#include <iostream>
#include <fstream>
#include <string>

#define OUTPUT "output.txt"

using namespace std;

int main()
{
	fstream fout;
	Shape shape(1, 1, 0, RGB_BLACK, "Shape");										// Shape 객체
	Elps red_elps(8, 8, 3.0, 4.0, 0, RGB_RED, "Red_Elps");							// Elps 객체
	ElpsCylinder blue_elpcyl(9, 9, 5.0, 6.0, 7.0, 0.0, RGB_BLUE, "Blue_Elp_Cyl");	// ElpsCylinder 객체
	
	// 파일 오픈 (쓰기모드로)
	fout.open(OUTPUT, 'w');
	if (fout.fail())
	{
		cout << "Failed in opening output.txt File !!" << endl;
		exit(-1);
	}
	
	// 파일 출력 
	fout << "List of shapes using operator<<() friend funtion " << endl;
	fout << shape << endl;
	fout << red_elps << endl;
	fout << blue_elpcyl << endl;

	fout.close();		// 파일 닫기
	return 0;
}