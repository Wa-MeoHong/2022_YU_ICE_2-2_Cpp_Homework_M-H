/*
  파일명 : "HW4-1_21912193_신대홍"
  프로그램의 목적 및 기본 기능:
	- Cmplx 클래스를 만들고, 연산자 오버로드를 통해 배열을 생성후, 출력
  프로그램 작성자 : 신대홍(2022년 9월 23일)
  최종 Update : Version 1.0.0, 2022년 9월 23일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자		   수정일		 버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
	신대홍		 2022/09/23		v1.0.0		  최초작성

===========================================================================================================
*/

#include <iostream>
#include <fstream>
#include "Cmplx.h"
#include "CmplxArray.h"

#define INPUT "input.txt"
#define OUTPUT "output.txt"

using namespace std;

int main(void)
{
	ifstream fin;
	CmplxArray cmplxs(7);

	// 파일열기 실패시 오류메세지 출력 후 강제종료
	fin.open(INPUT);
	if (fin.fail())
	{
		cout << "Error in open input.txt!!" << endl; exit(0);
	}

	// 복소수 파일 입력
	fin >> cmplxs[0] >> cmplxs[1];

	// 복소수 연산
	cmplxs[2] = cmplxs[0] + cmplxs[1];					// 복소수 덧셈
	cmplxs[3] = cmplxs[0] - cmplxs[1];					// 복소수 뺄셈
	cmplxs[4] = cmplxs[0] * cmplxs[1];					// 복소수 곱셈
	cmplxs[5] = cmplxs[0] / cmplxs[1];					// 복소수 나눗셈
	cmplxs[6] = ~cmplxs[0];								// 복소수 반전(음의 복소수로)

	// 복소수 출력
	cout << "cmplxs[0] = " << cmplxs[0] << endl;
	cout << "cmplxs[1] = " << cmplxs[1] << endl;
	cout << "cmplxs[2] = cmplxs[0] + cmplxs[1] = " << cmplxs[2] << endl;
	cout << "cmplxs[3] = cmplxs[0] - cmplxs[1] = " << cmplxs[3] << endl;
	cout << "cmplxs[4] = cmplxs[0] * cmplxs[1] = " << cmplxs[4] << endl;
	cout << "cmplxs[5] = cmplxs[0] / cmplxs[1] = " << cmplxs[5] << endl;
	cout << "cmplxs[6] = ~cmplxs[0] (conjugate) = " << cmplxs[6] << endl;

	// 복소수 1, 복소수 2가 일치하는지 비교
	if(cmplxs[0] == cmplxs[1])								// 맞으면 같다고 출력
		cout << "cmplxs[0] is equal to cmplxs[1]" << endl;
	else
		cout << "cmplxs[0] is not equal to cmplxs[1]" << endl;		// 아니면 아니라고 출력

	cmplxs[1] = cmplxs[0];									// 복소수1에 복소수2의 값을 대입
	cout << "After cmplxs[1] = cmplxs[0]; ==> " << endl;

	// 다시한번 일치하는지 비교함
	if (cmplxs[0] == cmplxs[1])
		cout << "cmplxs[0] is equal to cmplxs[1]" << endl;
	else
		cout << "cmplxs[0] is not equal to cmplxs[1]" << endl;

	//cmplxs.sort();
	//cmplxs.print(cout);
	//파일 닫기  
	fin.close();

	return 0;
}
