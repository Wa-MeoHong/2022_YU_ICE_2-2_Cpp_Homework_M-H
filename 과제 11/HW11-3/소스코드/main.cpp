/*
  파일명 : "HW11-3_21912193_신대홍"
  프로그램의 목적 및 기본 기능:
	- SkipList를 구성하고 단어를 넣고 삭제하는 과정을 출력해본다.
  프로그램 작성자 : 신대홍(2022년 11월 29일)
  최종 Update : Version 1.1.0, 2022년 11월 29일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자	  수정일			버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
	신대홍		 2022/11/29		v1.0.0		  최초작성
	신대홍		 2022/11/29		v1.1.0		  완성

===========================================================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "SkipLIst.h"
#include "MyVoca.h"
#include "MyVocaList.h"

using namespace std;

#define OUTPUT "output.txt"

int main(void)
{
	ofstream fout(OUTPUT);

	if (fout.fail())
	{
		cout << "Error !! in opening output.txt !!" << endl;
		exit(-1);
	}

	fout << "\n===================================================" << endl;
	fout << "Text SkipList<int, MyVoca> . . . " << endl;
	SkipList<int , MyVoca*> VocaSkipList;
	typedef SkipList<int , MyVoca*>::Position Pos_Voca;

	Pos_Voca pVoca;
	int DeleteList[NUM_MY_TOEIC_VOCA] = {2, 3, 5, 6, 1, 4, 8, 7 , 10, 12, 13, 11, 9, 15, 16, 17, 14,19, 18, 20 };
	int key;

	fout << "Inserting Vocas to Voca SkipList . . . " << endl;
	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		fout << "Inserting Voca[" << i << "]:\n"
			<< myToeicVocaList[i] << endl;
		key = myToeicVocaList[i].Key();
		VocaSkipList.SkipListInsert(fout, key, &myToeicVocaList[i]);
		VocaSkipList.PrintSkipList(fout);
		fout << endl;
	}
	cout << "Input Complete !" << endl;

	fout << "\n*********************" << endl;
	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		fout << "Search planetSkipList and delete the Voca ("
			<< DeleteList[i] << " ) : ";
		pVoca = VocaSkipList.SkipListSearch(DeleteList[i]);
		if (pVoca != Pos_Voca(NULL))
		{
			fout << *pVoca << endl;
			VocaSkipList.SkipListRemove(fout, DeleteList[i]);
		}
		VocaSkipList.PrintSkipList(fout);
		fout << endl;
	}
	cout << "Remove Complete!" << endl;
	return 0;
}