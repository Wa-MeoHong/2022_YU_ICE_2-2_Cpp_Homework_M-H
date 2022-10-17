#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;

class Person
{
	friend ostream& operator<<(ostream&, const Person&);
public:
	// constructor
	Person();
	Person(string n);

	//getter ( 사람의 정보를 반환. 생일, 이름 )
	Date Birth() const { return BirthofDate; }
	string Name() const { return name; }
	
	//setter ( 사람 데이터(생일, 이름) 설정 함수들 )
	void Set_Birth(Date bd) { BirthofDate = bd; }
	void Set_Name(string n) { name = n; }

protected:
	Date BirthofDate;				// 생일
	string name;					// 이름

};

#endif // !PERSON_H
