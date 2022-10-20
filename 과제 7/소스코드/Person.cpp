#include "Person.h"

/*				constructor ( ������ )
		1. default constructor ( ����Ʈ ������ )
		2. �̸��� �޴� constructor					*/

Person::Person()
{
	Set_Name(" ");						// �л� �̸� �ʱ�ȭ
	Set_Birth(Date(1, 1, 1));			// ������ 1�� 1�� 1�Ϸ� �ʱ�ȭ
}
Person::Person(string n)
{
	Set_Name(n);						// �л� �̸��� n�� ����
	Set_Birth(Date(1, 1, 1));
}

/*				operator Overloading ( ������ �����ε� )		
		1. ��� ������ ( << )						*/
ostream& operator<<(ostream& ostr, const Person& p )
{
	// print format : name : Name, birth_of_date: (Date)
	// Date Ŭ������ ������ �����ε��� ���� ���

	ostr << "name : " << left << setw(10) << right << p.Name() << ", " 
		<< "date_of_birth : " << p.Birth();

	return ostr;
}
