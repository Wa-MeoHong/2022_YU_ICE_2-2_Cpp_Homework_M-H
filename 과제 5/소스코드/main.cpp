/*
  ���ϸ� : "HW5_21912193_�Ŵ�ȫ"
  ���α׷��� ���� �� �⺻ ���:
	- Ŭ���� Shape, Elps, ElpsCylinder�� �����, �����͸� ����, �����
  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 10�� 7��)
  ���� Update : Version 1.0.0, 2022�� 10�� 7��(�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������	  ������		 ����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
	�Ŵ�ȫ		 2022/10/07		v1.0.0		  �����ۼ�
	�Ŵ�ȫ		 2022/10/08		v1.1.0		  �ϼ�
===========================================================================================================
*/

#include "Color.h"
#include "Shape.h"
#include "Elps.h"
#include "ElpsCylinder.h"
#include <iostream>
#include <fstream>
#include <string>

#define OUTPUT "output.txt"

using namespace std;

int main()
{
	fstream fout;
	Shape shape(1, 1, 0, RGB_BLACK, "Shape");										// Shape ��ü
	Elps red_elps(8, 8, 3.0, 4.0, 0, RGB_RED, "Red_Elps");							// Elps ��ü
	ElpsCylinder blue_elpcyl(9, 9, 5.0, 6.0, 7.0, 0.0, RGB_BLUE, "Blue_Elp_Cyl");	// ElpsCylinder ��ü
	
	// ���� ���� (�������)
	fout.open(OUTPUT, 'w');
	if (fout.fail())
	{
		cout << "Failed in opening output.txt File !!" << endl;
		exit(-1);
	}
	
	// ���� ��� 
	fout << "List of shapes using operator<<() friend funtion " << endl;
	fout << shape << endl;
	fout << red_elps << endl;
	fout << blue_elpcyl << endl;

	fout.close();		// ���� �ݱ�
	return 0;
}