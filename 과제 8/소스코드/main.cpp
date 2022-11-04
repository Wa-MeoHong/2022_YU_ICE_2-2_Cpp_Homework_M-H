/*
  ���ϸ� : "HW8_21912193_�Ŵ�ȫ"
  ���α׷��� ���� �� �⺻ ���:
	- ���ø��� Ȱ���Ͽ� Heap Priority Queue�� �����Ͽ� ������ �����͸� �ٷ��
  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 11�� 5��)
  ���� Update : Version 1.0.0, 2022�� 11�� 5��(�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������	  ������			����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
	�Ŵ�ȫ		 2022/11/05		v1.0.0		  �����ۼ�
===========================================================================================================
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "HeapPrioQ.h"

using namespace std;

#define INITIAL_CBT_CAPA 100			// CBT�� �뷮
#define NUM_DATA 15						// ���� �������� ����
#define OUTPUT "output.txt"				// OUTPUT.txt

int main(void)
{
	ofstream fout;
	int* pD;
	int inputArray[NUM_DATA] =
		{ 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	// ������ ������ 15��

	// ���� ����
	fout.open(OUTPUT);
	if (fout.fail())
	{
		// �����޼��� ��� �� ����
		cout << "Error!! Doesn't open output.txt!" << endl;
		exit(-1);
	}
	// HeapPrioQueue ��ü �ϳ� ����
	HeapPrioQueue<int> HeapPriQ_int(INITIAL_CBT_CAPA, string("Heap_Priority_Queue_Int"));
	for (int i = 0; i < NUM_DATA; i++)
	{
		HeapPriQ_int.insert(inputArray[i]);			// ������ ������ �ϳ� �������
		fout << "Insert" << setw(3) << inputArray[i];
		fout << " ==> Size of Heap Priority Queue : " << setw(3) << HeapPriQ_int.size() << endl;
	}

	// ��� ���� ��, ���
	fout << "Final status of insertions : " << endl;
	HeapPriQ_int.fprintCBT_byLevel(fout);

	// Root��� ���� 
	for (int i = 0; i < NUM_DATA; i++)
	{
		// Root��带 �����ϸ鼭, �����.(����� ��������)
		fout << "\nCurrent top priority in Heap Priority Queue : ";
		pD = (int*)HeapPriQ_int.HeapMin();
		fout << setw(3) << *pD << endl;
		pD = (int*)HeapPriQ_int.removeHeapMin();			// �� ����
		fout << "RemoveMin (" << *pD << ") from HeapPriQ_int";
		fout << " ==> " << HeapPriQ_int.size() << "elements remains." << endl;
		// ť ���
		HeapPriQ_int.fprintCBT_byLevel(fout);
		fout << endl;
	}
	fout.close();			// ���� �ݱ�

	return 0;
}