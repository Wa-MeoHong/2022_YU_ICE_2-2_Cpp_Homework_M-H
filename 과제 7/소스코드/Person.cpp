#include "Person.h"

/*				constructor ( 생성자 )
		1. default constructor ( 디폴트 생성자 )
		2. 이름을 받는 constructor					*/

Person::Person()
{
	Set_Name(" ");
	Set_Birth(Date(1, 1, 1));
}
Person::Person(string n)
{
	Set_Name(n);
	Set_Birth(Date(1, 1, 1));
}

/*				operator Overloading ( 연산자 오버로드 )		
		1. 출력 연산자 ( << )						*/
ostream& operator<<(ostream& ostr, const Person& p )
{
	// print format : name : Name, birth_of_date: (Date)
	// Date 클래스도 연산자 오버로딩을 통해 출력

	ostr << "name : " << left << setw(10) << p.Name() << ", " 
		<< "date_of_birth : " << p.Birth();

	return ostr;
}
