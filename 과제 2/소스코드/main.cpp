/*
  파일명 : "HW2=2_21912193_신대홍"
  프로그램의 목적 및 기본 기능:
	- Class Date를 구성하여, 크리스마스와 날짜가 얼마 차이나는지 구하는 프로그램

  프로그램 작성자 : 신대홍(2022년 8월 30일)
  최종 Update : Version 1.0.0, 2022년 8월 30일 (신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자		   수정일		 버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
   신대홍		 2022/08/29		v1.0.0		  최초작성
   신대홍		 2022/09/01		v1.0.1		  완성 ( elapsed day 관련 수정 )

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
	Date AD010101(1, 1, 1);						// Date 클래스로 만든 1년1월1일 변수
	int year, month, day;
	int daysToChristmas;						// 크리스마스까지 며칠 남았는가
	time_t currentTime;							// 오늘 날짜를 구하기 위한 시간 변수 time_t
	struct tm* time_and_date;					// 현재 시각과 날짜를 담는 구조체 tm
	
	/*							>> 현재 시간 초기값 설정 <<
			1. time함수를 이용해 현재 시간과 날짜를 측정한 후, 구조체로 구성함(localtime 이용)
			2. year, month, day에 각각 오늘 날짜를 대입함
																			*/
	time(&currentTime);								// 현재 날짜와 시간을 알아냄
	time_and_date = localtime(&currentTime);		// 현재 날짜와 시간을 가져와서 구조체로 꾸밈
	year = time_and_date->tm_year + 1900;			// 1900년을 기준으로 시작하기 때문
	month = time_and_date->tm_mon + 1;				// 1월을 0으로 시작하는것 같다..
	day = time_and_date->tm_mday;					// 일수 대입

	// Date클래스 변수 newYearDay, today, christmas 설정
	Date newYearDay(year, 1, 1), today(year, month, day), christmas(year, 12, 25);
	// 오늘과 크리스마스 사이 남은 날 수 확인
	daysToChristmas = christmas.getElapsedDaysFromAD010101()
		- today.getElapsedDaysFromAD010101();

	/*									>> 출력 <<
		1. 1년 1월 1일의 정보를 출력 
		2. 오늘 날짜를 출력
		3. 이번년도의 1월 1일의 정보를 출력
		4. 이번년도의 크리스마스에 대한 정보 출력
		5. 오늘이 크리스마스일 경우 축하메세지를, 아닐 경우 크리스마스까지 며칠 남았는지 출력
																		*/
	cout << "AD Jan. 1. 1 is "; AD010101.printDate(); cout << endl;						// 1년 1월 1일 정보 출력
	cout << "Today is "; today.printDate(); cout << endl;								// 오늘 날짜 출력
	cout << "New Year's day of this year was "; newYearDay.printDate(); cout << endl;	// 이번년 시작일 출력
	cout << "Christmas of this year is "; christmas.printDate(); cout << endl;			// 이번년 크리스마스 출력

	// 만약 오늘이 크리스마스라면
	if (today.getMonth() == christmas.getMonth() &&
		today.getDay() == christmas.getDay())
	{
		cout << "Today is Christmas! Happy Christmas to you all !!" << endl;			// 축하메세지 출력
	}
	// 아니면
	else
	{
		// 크리스마스까지 며칠이 남았는지 계산
		cout << "Sorry, today is not Christmas!\n";
		cout << "You must wait " << daysToChristmas << " day(s) to Christmas !" << endl;
	}
	cout << endl;
	return 0;
}