/*
  ���ϸ� : "HW7_21912193_�Ŵ�ȫ"
  ���α׷��� ���� �� �⺻ ���:
	- Ŭ������ ����, ���ø��� �����Ͽ� �л��� ����Ѵ�.
  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 10�� 17��)
  ���� Update : Version 1.0.0, 2022�� 10�� 17��(�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������	  ������			����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
	�Ŵ�ȫ		 2022/10/17		v1.0.0		  �����ۼ�
	�Ŵ�ȫ		 2022/10/17		v1.1.0		  �ϼ�
===========================================================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "Student.h"
#include "T_Array.h"

using namespace std;
#define ELEMENTS_PER_LINE 10
#define SAMPLE_LINES 5
#define NUM_ELEMENTS 500
#define MIN_NUM_ELEMENTS 10
#define OUTPUT "output.txt"
#define NUM_STUDENTS 5

// students�� �̸� ����
Student students[NUM_STUDENTS] =
{
	Student(21811000, string("Kim, G-M"), Date(1990, 10, 5), Time(3, 0, 30), 3.57),
	Student(21611075, string("Yoon, S-M"), Date(1990, 4, 5), Time(7, 30, 0), 4.37),
	Student(21411015, string("Hwang, S-S"), Date(1989, 1, 10), Time(2, 0, 50), 2.72),
	Student(21611054, string("Lee, K-M"), Date(1991, 5, 15), Time(5, 30, 0), 3.35),
	Student(21311340, string("Hong, G-M"), Date(1990, 2, 5), Time(1, 10, 0), 3.89)
};

int main(void)
{
	ofstream fout;
	T_Array<Student> studentArray(NUM_STUDENTS, "Array of Students");
	// studentArray �迭�� ����, Student Ŭ������ ������
	Student* pStu;

	// output.txt ����
	fout.open(OUTPUT);
	if (fout.fail())
	{
		cout << "Fail to Open output.txt file !!" << endl;
		exit(-2);
	}

	// T_Array�� insert�� ��
	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		pStu = &students[i];
		studentArray.insert(i, *pStu);
	}

	// �ʱⰪ ���
	fout << "Elements in studentArray after initialization : " << endl;
	studentArray.fprint(fout, 1);

	// �������� ��������
	fout << "Elements in studentArray after sorting : " << endl;
	studentArray.selection_sort(INCREASING);
	studentArray.fprint(fout, 1);

	// ������ ��������
	studentArray.shuffle();
	fout << "Elements in studentArray after sorting : " << endl;
	studentArray.quick_sort(DECREASING);
	studentArray.fprint(fout, 1);

	// ���� �ݱ�
	fout.close();

	return 0;
}