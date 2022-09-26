/*
  ���ϸ� : "HW4-1_21912193_�Ŵ�ȫ"
  ���α׷��� ���� �� �⺻ ���:
	- Cmplx Ŭ������ �����, ������ �����ε带 ���� �迭�� ������, ���
  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 9�� 23��)
  ���� Update : Version 1.0.1, 2022�� 9�� 26��(�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������		   ������		 ����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
	�Ŵ�ȫ		 2022/09/23		v1.0.0		  �����ۼ�
	�Ŵ�ȫ		 2022/09/26		v1.0.1		  Cmplx ����� ����

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

	// ���Ͽ��� ���н� �����޼��� ��� �� ��������
	fin.open(INPUT);
	if (fin.fail())
	{
		cout << "Error in open input.txt!!" << endl; exit(0);
	}

	// ���Ҽ� ���� �Է�
	fin >> cmplxs[0] >> cmplxs[1];

	// ���Ҽ� ����
	cmplxs[2] = cmplxs[0] + cmplxs[1];					// ���Ҽ� ����
	cmplxs[3] = cmplxs[0] - cmplxs[1];					// ���Ҽ� ����
	cmplxs[4] = cmplxs[0] * cmplxs[1];					// ���Ҽ� ����
	cmplxs[5] = cmplxs[0] / cmplxs[1];					// ���Ҽ� ������
	cmplxs[6] = ~cmplxs[0];								// ���Ҽ� ����(���� ���Ҽ���)

	// ���Ҽ� ���
	cout << "cmplxs[0] = " << cmplxs[0] << endl;
	cout << "cmplxs[1] = " << cmplxs[1] << endl;
	cout << "cmplxs[2] = cmplxs[0] + cmplxs[1] = " << cmplxs[2] << endl;
	cout << "cmplxs[3] = cmplxs[0] - cmplxs[1] = " << cmplxs[3] << endl;
	cout << "cmplxs[4] = cmplxs[0] * cmplxs[1] = " << cmplxs[4] << endl;
	cout << "cmplxs[5] = cmplxs[0] / cmplxs[1] = " << cmplxs[5] << endl;
	cout << "cmplxs[6] = ~cmplxs[0] (conjugate) = " << cmplxs[6] << endl;

	// ���Ҽ� 1, ���Ҽ� 2�� ��ġ�ϴ��� ��
	if(cmplxs[0] == cmplxs[1])								// ������ ���ٰ� ���
		cout << "cmplxs[0] is equal to cmplxs[1]" << endl;
	else
		cout << "cmplxs[0] is not equal to cmplxs[1]" << endl;		// �ƴϸ� �ƴ϶�� ���

	cmplxs[1] = cmplxs[0];									// ���Ҽ�1�� ���Ҽ�2�� ���� ����
	cout << "After cmplxs[1] = cmplxs[0]; ==> " << endl;

	// �ٽ��ѹ� ��ġ�ϴ��� ����
	if (cmplxs[0] == cmplxs[1])
		cout << "cmplxs[0] is equal to cmplxs[1]" << endl;
	else
		cout << "cmplxs[0] is not equal to cmplxs[1]" << endl;

	//���� �ݱ� 
	fin.close();

	return 0;
}