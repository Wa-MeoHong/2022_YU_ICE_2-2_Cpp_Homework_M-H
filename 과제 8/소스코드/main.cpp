/*
  파일명 : "HW8_21912193_신대홍"
  프로그램의 목적 및 기본 기능:
	- 탬플릿을 활용하여 Heap Priority Queue를 구성하여 정수형 데이터를 다룬다
  프로그램 작성자 : 신대홍(2022년 11월 5일)
  최종 Update : Version 1.0.0, 2022년 11월 5일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자	  수정일			버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
	신대홍		 2022/11/05		v1.0.0		  최초작성
===========================================================================================================
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "HeapPrioQ.h"

using namespace std;

#define INITIAL_CBT_CAPA 100			// CBT의 용량
#define NUM_DATA 15						// 정수 데이터의 개수
#define OUTPUT "output.txt"				// OUTPUT.txt

int main(void)
{
	ofstream fout;
	int* pD;
	int inputArray[NUM_DATA] =
		{ 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	// 정수형 데이터 15개

	// 파일 오픈
	fout.open(OUTPUT);
	if (fout.fail())
	{
		// 에러메세지 출력 후 종료
		cout << "Error!! Doesn't open output.txt!" << endl;
		exit(-1);
	}
	// HeapPrioQueue 객체 하나 생성
	HeapPrioQueue<int> HeapPriQ_int(INITIAL_CBT_CAPA, string("Heap_Priority_Queue_Int"));
	for (int i = 0; i < NUM_DATA; i++)
	{
		HeapPriQ_int.insert(inputArray[i]);			// 정수형 데이터 하나 집어넣음
		fout << "Insert" << setw(3) << inputArray[i];
		fout << " ==> Size of Heap Priority Queue : " << setw(3) << HeapPriQ_int.size() << endl;
	}

	// 모두 넣은 후, 출력
	fout << "Final status of insertions : " << endl;
	HeapPriQ_int.fprintCBT_byLevel(fout);

	// Root노드 삭제 
	for (int i = 0; i < NUM_DATA; i++)
	{
		// Root노드를 삭제하면서, 출력함.(출력이 먼저진행)
		fout << "\nCurrent top priority in Heap Priority Queue : ";
		pD = (int*)HeapPriQ_int.HeapMin();
		fout << setw(3) << *pD << endl;
		pD = (int*)HeapPriQ_int.removeHeapMin();			// 본 삭제
		fout << "RemoveMin (" << *pD << ") from HeapPriQ_int";
		fout << " ==> " << HeapPriQ_int.size() << "elements remains." << endl;
		// 큐 출력
		HeapPriQ_int.fprintCBT_byLevel(fout);
		fout << endl;
	}
	fout.close();			// 파일 닫기

	return 0;
}