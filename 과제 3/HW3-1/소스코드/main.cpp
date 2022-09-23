/*
  파일명 : "HW3-1_21912193_신대홍"
  프로그램의 목적 및 기본 기능:
	- Class BigArray (큰 난수배열 클래스)를 만들어 출력을 하는 프로그램
  프로그램 작성자 : 신대홍(2022년 9월 23일)
  최종 Update : Version 1.0.0, 2022년 9월 23일 (신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자		   수정일		 버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
   신대홍		 2022/09/23		v1.0.0		  최초작성, 완성

===========================================================================================================
*/

#include <iostream>
#include <fstream>
#include <Windows.h>
#include "BigArray.h"

using namespace std;

#define ELEMENTS_PER_LINE 10
#define SAMPLE_LINES 3
#define OUTPUT "output.txt"
#define Milli 1000

int main(void)
{
	LARGE_INTEGER freq, t_1, t_2;							// CPU 클럭 주파수, 시간을 측정하는 변수 t_1, t_2
	double t_diff, t_quick, t_select;						// 시간 측정 변수들
	ofstream fout;

	QueryPerformanceFrequency(&freq);						// CPU 클럭 측정

	//쓰기 파일 오픈
	fout.open(OUTPUT);
	if (fout.fail())
	{
		cout << "Error. Not opening output.txt !!" << endl; exit;
	}

	/*				배열 생성
		1. base_offset(시작점)은 -500000 이고, 100만개 생성한다.
		2. 동적할당을 통해 배열 생성을 진행함
		3. 생성한 배열을 각각 QuickSort, SelectSort로 정렬한 후, 출력해본다.*/	
	int base_offset = -500000, Rand_size = 1000000;
	BigArray Bigarray1(Rand_size);							// 배열 클래스 객체 생성
	
	cout << "Generate BigArray..." << endl;
	fout << "Generating big rand array of " << Bigarray1.size() <<	
		" elements with base_offset " << base_offset << "..." << endl;
	// 배열 출력
	Bigarray1.fprintBigArray(fout, ELEMENTS_PER_LINE);
	cout << "BigArray Generate Complete" << endl;
	// 배열의 데이터 계산(평균, 최대, 최소, 분산, 표준편차)를 구하고 출력
	Bigarray1.fprintStatistics(fout);
	cout << "BigArray Statistics Calculate Complete" << endl;

	/*				정렬 1 : QuickSort			*/	
	QueryPerformanceCounter(&t_1);							// 정렬 시작 전 시간 측정
	Bigarray1.quick_sort();									// 퀵정렬 시작
	QueryPerformanceCounter(&t_2);							// 정렬 후 시간 측정
	// 정렬에 걸린 시간 계산 (단위 : ms)
	t_diff = t_2.QuadPart - t_1.QuadPart;					// QuadPart = LARGE_INTEGER를 C++상의 실제값으로 사용하기 위해 사용
	t_quick = (t_diff / (double)freq.QuadPart) * Milli;
	// 최종 출력
	cout << "Big Array sort complete(Quick sort) ( time : " << t_quick << " ms )\n" << endl;
	fout << "sorted Big Array (Quick Sort) ( time : " << t_quick << " ms )" << endl;
	Bigarray1.fprintBigArray(fout, ELEMENTS_PER_LINE);
	Bigarray1.suffle();										// 정렬이 끝났으므로 다시 섞어준다.

	/*				정렬 2 : SelectionSort			*/
	QueryPerformanceCounter(&t_1);							// 정렬 시작 전 시간 측정
	Bigarray1.selection_sort();								// 선택정렬
	QueryPerformanceCounter(&t_2);							// 정렬 후 시간측정
	// 정렬에 걸린 시간 계산
	t_diff = t_2.QuadPart - t_1.QuadPart;
	t_select = (t_diff / (double)freq.QuadPart) * Milli;
	
	// 최종 출력
	cout << "Big Array sort complete(Select sort) ( time : " << t_select << " ms )" << endl;
	fout << "sorted Big Array (Select Sort) ( time : " << t_select << " ms )" << endl;
	Bigarray1.fprintBigArray(fout, ELEMENTS_PER_LINE);

	fout.close();											// 파일 닫기
	return 0;												// return 이후 소멸자가 작동함
}