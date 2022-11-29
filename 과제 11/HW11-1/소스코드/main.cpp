/*
  파일명 : "HW11-1_21912193_신대홍"
  프로그램의 목적 및 기본 기능:
	- Cyclic Shift를 이용하여 영단어의 Hash값을 처리되는 과정을 살펴본다 
  프로그램 작성자 : 신대홍(2022년 11월 27일)
  최종 Update : Version 1.0.0, 2022년 11월 27일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자	  수정일			버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
	신대홍		 2022/11/27		v1.0.0		  최초작성

===========================================================================================================
*/

#include "CyclicShiftHashCode.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "MyVoca.h"
#include "MyVocaList.h"

using namespace std;
#define SIX_BITS 64

int main(void)
{
	CyclicShiftHashCode hash;
	unsigned int h = 0, j = 0;
	string k;
	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		k = myToeicVocaList[i].KeyWord();
		h = hash(k);		// hash code 도출
		j = h % SIX_BITS;

		cout << "key : " << setw(15) << k << ", ";;
		printf(" hash code = % #12x, hash value = % 3d\n",  h, j);
	}

	return 0;
}