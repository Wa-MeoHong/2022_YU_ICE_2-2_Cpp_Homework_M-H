/*
  ���ϸ� : "HW3-1_21912193_�Ŵ�ȫ"
  ���α׷��� ���� �� �⺻ ���:
	- Class BigArray (ū �����迭 Ŭ����)�� ����� ����� �ϴ� ���α׷�
  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 9�� 23��)
  ���� Update : Version 1.0.0, 2022�� 9�� 23�� (�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������		   ������		 ����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
   �Ŵ�ȫ		 2022/09/23		v1.0.0		  �����ۼ�, �ϼ�

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
	LARGE_INTEGER freq, t_1, t_2;							// CPU Ŭ�� ���ļ�, �ð��� �����ϴ� ���� t_1, t_2
	double t_diff, t_quick, t_select;						// �ð� ���� ������
	ofstream fout;

	QueryPerformanceFrequency(&freq);						// CPU Ŭ�� ����

	//���� ���� ����
	fout.open(OUTPUT);
	if (fout.fail())
	{
		cout << "Error. Not opening output.txt !!" << endl; exit;
	}

	/*				�迭 ����
		1. base_offset(������)�� -500000 �̰�, 100���� �����Ѵ�.
		2. �����Ҵ��� ���� �迭 ������ ������
		3. ������ �迭�� ���� QuickSort, SelectSort�� ������ ��, ����غ���.*/	
	int base_offset = -500000, Rand_size = 1000000;
	BigArray Bigarray1(Rand_size);							// �迭 Ŭ���� ��ü ����
	
	cout << "Generate BigArray..." << endl;
	fout << "Generating big rand array of " << Bigarray1.size() <<	
		" elements with base_offset " << base_offset << "..." << endl;
	// �迭 ���
	Bigarray1.fprintBigArray(fout, ELEMENTS_PER_LINE);
	cout << "BigArray Generate Complete" << endl;
	// �迭�� ������ ���(���, �ִ�, �ּ�, �л�, ǥ������)�� ���ϰ� ���
	Bigarray1.fprintStatistics(fout);
	cout << "BigArray Statistics Calculate Complete" << endl;

	/*				���� 1 : QuickSort			*/	
	QueryPerformanceCounter(&t_1);							// ���� ���� �� �ð� ����
	Bigarray1.quick_sort();									// ������ ����
	QueryPerformanceCounter(&t_2);							// ���� �� �ð� ����
	// ���Ŀ� �ɸ� �ð� ��� (���� : ms)
	t_diff = t_2.QuadPart - t_1.QuadPart;					// QuadPart = LARGE_INTEGER�� C++���� ���������� ����ϱ� ���� ���
	t_quick = (t_diff / (double)freq.QuadPart) * Milli;
	// ���� ���
	cout << "Big Array sort complete(Quick sort) ( time : " << t_quick << " ms )\n" << endl;
	fout << "sorted Big Array (Quick Sort) ( time : " << t_quick << " ms )" << endl;
	Bigarray1.fprintBigArray(fout, ELEMENTS_PER_LINE);
	Bigarray1.suffle();										// ������ �������Ƿ� �ٽ� �����ش�.

	/*				���� 2 : SelectionSort			*/
	QueryPerformanceCounter(&t_1);							// ���� ���� �� �ð� ����
	Bigarray1.selection_sort();								// ��������
	QueryPerformanceCounter(&t_2);							// ���� �� �ð�����
	// ���Ŀ� �ɸ� �ð� ���
	t_diff = t_2.QuadPart - t_1.QuadPart;
	t_select = (t_diff / (double)freq.QuadPart) * Milli;
	
	// ���� ���
	cout << "Big Array sort complete(Select sort) ( time : " << t_select << " ms )" << endl;
	fout << "sorted Big Array (Select Sort) ( time : " << t_select << " ms )" << endl;
	Bigarray1.fprintBigArray(fout, ELEMENTS_PER_LINE);

	fout.close();											// ���� �ݱ�
	return 0;												// return ���� �Ҹ��ڰ� �۵���
}