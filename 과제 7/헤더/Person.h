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

	//getter ( ����� ������ ��ȯ. ����, �̸� )
	Date Birth() const { return BirthofDate; }
	string Name() const { return name; }
	
	//setter ( ��� ������(����, �̸�) ���� �Լ��� )
	void Set_Birth(Date bd) { BirthofDate = bd; }
	void Set_Name(string n) { name = n; }

protected:
	Date BirthofDate;				// ����
	string name;					// �̸�

};

#endif // !PERSON_H
