/*
  ���ϸ� : "HW11-3_21912193_�Ŵ�ȫ"
  ���α׷��� ���� �� �⺻ ���:
	- SkipList�� �����ϰ� �ܾ �ְ� �����ϴ� ������ ����غ���.
  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 11�� 29��)
  ���� Update : Version 1.1.0, 2022�� 11�� 29��(�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������	  ������			����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
	�Ŵ�ȫ		 2022/11/29		v1.0.0		  �����ۼ�
	�Ŵ�ȫ		 2022/11/29		v1.1.0		  �ϼ�

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