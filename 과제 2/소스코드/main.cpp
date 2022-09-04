/*
  ���ϸ� : "HW2=2_21912193_�Ŵ�ȫ"
  ���α׷��� ���� �� �⺻ ���:
	- Class Date�� �����Ͽ�, ũ���������� ��¥�� �� ���̳����� ���ϴ� ���α׷�

  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 8�� 30��)
  ���� Update : Version 1.0.0, 2022�� 8�� 30�� (�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������		   ������		 ����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
   �Ŵ�ȫ		 2022/08/29		v1.0.0		  �����ۼ�
   �Ŵ�ȫ		 2022/09/01		v1.0.1		  �ϼ� ( elapsed day ���� ���� )

===========================================================================================================
*/

#include <iostream>
#include <time.h>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;

int main()
{
	Date AD010101(1, 1, 1);						// Date Ŭ������ ���� 1��1��1�� ����
	int year, month, day;
	int daysToChristmas;						// ũ������������ ��ĥ ���Ҵ°�
	time_t currentTime;							// ���� ��¥�� ���ϱ� ���� �ð� ���� time_t
	struct tm* time_and_date;					// ���� �ð��� ��¥�� ��� ����ü tm
	
	/*							>> ���� �ð� �ʱⰪ ���� <<
			1. time�Լ��� �̿��� ���� �ð��� ��¥�� ������ ��, ����ü�� ������(localtime �̿�)
			2. year, month, day�� ���� ���� ��¥�� ������
																			*/
	time(&currentTime);								// ���� ��¥�� �ð��� �˾Ƴ�
	time_and_date = localtime(&currentTime);		// ���� ��¥�� �ð��� �����ͼ� ����ü�� �ٹ�
	year = time_and_date->tm_year + 1900;			// 1900���� �������� �����ϱ� ����
	month = time_and_date->tm_mon + 1;				// 1���� 0���� �����ϴ°� ����..
	day = time_and_date->tm_mday;					// �ϼ� ����

	// DateŬ���� ���� newYearDay, today, christmas ����
	Date newYearDay(year, 1, 1), today(year, month, day), christmas(year, 12, 25);
	// ���ð� ũ�������� ���� ���� �� �� Ȯ��
	daysToChristmas = christmas.getElapsedDaysFromAD010101()
		- today.getElapsedDaysFromAD010101();

	/*									>> ��� <<
		1. 1�� 1�� 1���� ������ ��� 
		2. ���� ��¥�� ���
		3. �̹��⵵�� 1�� 1���� ������ ���
		4. �̹��⵵�� ũ���������� ���� ���� ���
		5. ������ ũ���������� ��� ���ϸ޼�����, �ƴ� ��� ũ������������ ��ĥ ���Ҵ��� ���
																		*/
	cout << "AD Jan. 1. 1 is "; AD010101.printDate(); cout << endl;						// 1�� 1�� 1�� ���� ���
	cout << "Today is "; today.printDate(); cout << endl;								// ���� ��¥ ���
	cout << "New Year's day of this year was "; newYearDay.printDate(); cout << endl;	// �̹��� ������ ���
	cout << "Christmas of this year is "; christmas.printDate(); cout << endl;			// �̹��� ũ�������� ���

	// ���� ������ ũ�����������
	if (today.getMonth() == christmas.getMonth() &&
		today.getDay() == christmas.getDay())
	{
		cout << "Today is Christmas! Happy Christmas to you all !!" << endl;			// ���ϸ޼��� ���
	}
	// �ƴϸ�
	else
	{
		// ũ������������ ��ĥ�� ���Ҵ��� ���
		cout << "Sorry, today is not Christmas!\n";
		cout << "You must wait " << daysToChristmas << " day(s) to Christmas !" << endl;
	}
	cout << endl;
	return 0;
}