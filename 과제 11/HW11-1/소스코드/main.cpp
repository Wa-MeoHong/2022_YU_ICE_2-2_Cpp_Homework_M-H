/*
  ���ϸ� : "HW11-1_21912193_�Ŵ�ȫ"
  ���α׷��� ���� �� �⺻ ���:
	- Cyclic Shift�� �̿��Ͽ� ���ܾ��� Hash���� ó���Ǵ� ������ ���캻�� 
  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 11�� 27��)
  ���� Update : Version 1.0.0, 2022�� 11�� 27��(�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������	  ������			����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
	�Ŵ�ȫ		 2022/11/27		v1.0.0		  �����ۼ�

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
		h = hash(k);		// hash code ����
		j = h % SIX_BITS;

		cout << "key : " << setw(15) << k << ", ";;
		printf(" hash code = % #12x, hash value = % 3d\n",  h, j);
	}

	return 0;
}