#include "Student.h"

/*				constructor ( ������ )
		1. default constructor ( ����Ʈ ������ )
		2. ��� ���ڸ� �޴� constructor
		3. Copy constructor							*/
Student::Student()
{
	set_ID(0);
	set_GPA(0.0);
	set_AVT(Time(0, 0, 0));
}
Student::Student(int id, string n, Date bd, Time avt, double GPA)
	: Person(n)
{
	Set_Birth(bd);	set_ID(id);
	set_GPA(GPA);	set_AVT(avt);
}
Student::Student(const Student& st)
	: Person(st.Name())
{
	Set_Birth(st.Birth());	set_ID(st.ST_id());
	set_GPA(st.GPA());	set_AVT(st.arrivalTime);
}

/*				operator Overloading ( ������ �����ε� )
		1. ���� ������ ( = )
		2. �� ������ ( <, <=, >, >=, == )
		3. ��� ������ ( << )							*/

Student& Student::operator=(const Student& st)
{
	// ����, �̸�, �й�, ����, �����ð� ����
	this->Set_Birth(st.Birth());
	this->Set_Name(st.Name());
	this->set_ID(st.ST_id());
	this->set_GPA(st.GPA());
	this->set_AVT(st.arrivalTime);

	return *this;
	// TODO: ���⿡ return ���� �����մϴ�.
}
// ��� �����ð��� �������� ���Ѵ�.
bool Student::operator<(const Student& st)
{
	// ���� �����ð��� �� �����ٸ� True �ƴϸ� False
	if (this->arrivalTime < st.arrivalTime)
		return true;
	return false;
}
bool Student::operator<=(const Student& st)
{
	// ���� �����ð��� �� �����ų� ���ٸ� True �ƴϸ� False
	if (this->arrivalTime <= st.arrivalTime)
		return true;
	return false;
}
bool Student::operator>(const Student& st)
{
	// ���� �����ð��� �� ������ True �ƴϸ� False
	if (this->arrivalTime > st.arrivalTime)
		return true;
	return false;
}
bool Student::operator>=(const Student& st)
{
	// ���� �����ð��� �� �ʰų� ���ٸ� True �ƴϸ� False
	if (this->arrivalTime >= st.arrivalTime)
		return true;
	return false;
}
bool Student::operator==(const Student& st)
{
	// ���� �����ð��� ���ٸ� True �ƴϸ� False
	if (this->arrivalTime == st.arrivalTime)
		return true;
	return false;
}

ostream& operator<<(ostream& ostr, const Student& st)
{
	//print format = Student [ st_id : id, name : name, date_of_birth : (YYYY.MM.DD), arrival: (hh:mm:ss), gpa: GPA]
	// �й�, �̸�, ����, �����ð�, ���� ������ ���
	ostr << "Student [ "
		<< "st_id: " << st.ST_id() << ", "
		<< Person(st) << ", "
		<< "arrival: " << st.arrivalTime << ", ";

	ostr.setf(ios::showpoint); ostr.setf(ios::fixed);						// ���� �Ҽ��� 2�ڸ������� ���
	ostr.precision(2);
	ostr << "gpa: " << st.GPA() << "]";
	ostr.unsetf(ios::adjustfield);
	
	return ostr;
	// TODO: ���⿡ return ���� �����մϴ�.
}
