/*
  파일명 : "HW7_21912193_신대홍"
  프로그램의 목적 및 기본 기능:
	- 클래스를 생성, 탬플릿을 구성하여 학생을 출력한다.
  프로그램 작성자 : 신대홍(2022년 10월 17일)
  최종 Update : Version 1.0.0, 2022년 10월 17일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자	  수정일			버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
	신대홍		 2022/10/17		v1.0.0		  최초작성
	신대홍		 2022/10/17		v1.1.0		  완성
===========================================================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "Student.h"
#include "T_Array.h"

using namespace std;
#define ELEMENTS_PER_LINE 10
#define SAMPLE_LINES 5
#define NUM_ELEMENTS 500
#define MIN_NUM_ELEMENTS 10
#define OUTPUT "output.txt"
#define NUM_STUDENTS 5

// students를 미리 정의
Student students[NUM_STUDENTS] =
{
	Student(21811000, string("Kim, G-M"), Date(1990, 10, 5), Time(3, 0, 30), 3.57),
	Student(21611075, string("Yoon, S-M"), Date(1990, 4, 5), Time(7, 30, 0), 4.37),
	Student(21411015, string("Hwang, S-S"), Date(1989, 1, 10), Time(2, 0, 50), 2.72),
	Student(21611054, string("Lee, K-M"), Date(1991, 5, 15), Time(5, 30, 0), 3.35),
	Student(21311340, string("Hong, G-M"), Date(1990, 2, 5), Time(1, 10, 0), 3.89)
};

int main(void)
{
	ofstream fout;
	T_Array<Student> studentArray(NUM_STUDENTS, "Array of Students");
	// studentArray 배열을 만듦, Student 클래스를 가져옴
	Student* pStu;

	// output.txt 열기
	fout.open(OUTPUT);
	if (fout.fail())
	{
		cout << "Fail to Open output.txt file !!" << endl;
		exit(-2);
	}

	// T_Array에 insert를 함
	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		pStu = &students[i];
		studentArray.insert(i, *pStu);
	}

	// 초기값 출력
	fout << "Elements in studentArray after initialization : " << endl;
	studentArray.fprint(fout, 1);

	// 선택정렬 오름차순
	fout << "Elements in studentArray after sorting : " << endl;
	studentArray.selection_sort(INCREASING);
	studentArray.fprint(fout, 1);

	// 퀵정렬 내림차순
	studentArray.shuffle();
	fout << "Elements in studentArray after sorting : " << endl;
	studentArray.quick_sort(DECREASING);
	studentArray.fprint(fout, 1);

	// 파일 닫기
	fout.close();

	return 0;
}