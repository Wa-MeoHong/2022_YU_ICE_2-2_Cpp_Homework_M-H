#include "Student.h"

/*				constructor ( 생성자 )
		1. default constructor ( 디폴트 생성자 )
		2. 모든 인자를 받는 constructor
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

/*				operator Overloading ( 연산자 오버로드 )
		1. 대입 연산자 ( = )
		2. 비교 연산자 ( <, <=, >, >=, == )
		3. 출력 연산자 ( << )							*/

Student& Student::operator=(const Student& st)
{
	// 생일, 이름, 학번, 성적, 도착시간 대입
	this->Set_Birth(st.Birth());
	this->Set_Name(st.Name());
	this->set_ID(st.ST_id());
	this->set_GPA(st.GPA());
	this->set_AVT(st.arrivalTime);

	return *this;
	// TODO: 여기에 return 문을 삽입합니다.
}
// 모두 도착시각을 기준으로 비교한다.
bool Student::operator<(const Student& st)
{
	// 만약 도착시간이 더 빠르다면 True 아니면 False
	if (this->arrivalTime < st.arrivalTime)
		return true;
	return false;
}
bool Student::operator<=(const Student& st)
{
	// 만약 도착시간이 더 빠르거나 같다면 True 아니면 False
	if (this->arrivalTime <= st.arrivalTime)
		return true;
	return false;
}
bool Student::operator>(const Student& st)
{
	// 만약 도착시간이 더 늦으면 True 아니면 False
	if (this->arrivalTime > st.arrivalTime)
		return true;
	return false;
}
bool Student::operator>=(const Student& st)
{
	// 만약 도착시간이 더 늦거나 같다면 True 아니면 False
	if (this->arrivalTime >= st.arrivalTime)
		return true;
	return false;
}
bool Student::operator==(const Student& st)
{
	// 만약 도착시간이 같다면 True 아니면 False
	if (this->arrivalTime == st.arrivalTime)
		return true;
	return false;
}

ostream& operator<<(ostream& ostr, const Student& st)
{
	//print format = Student [ st_id : id, name : name, date_of_birth : (YYYY.MM.DD), arrival: (hh:mm:ss), gpa: GPA]
	// 학번, 이름, 생일, 도착시간, 학점 순으로 출력
	ostr << "Student [ "
		<< "st_id: " << st.ST_id() << ", "
		<< Person(st) << ", "
		<< "arrival: " << st.arrivalTime << ", ";

	ostr.setf(ios::showpoint); ostr.setf(ios::fixed);						// 고정 소수점 2자리까지만 출력
	ostr.precision(2);
	ostr << "gpa: " << st.GPA() << "]";
	ostr.unsetf(ios::adjustfield);
	
	return ostr;
	// TODO: 여기에 return 문을 삽입합니다.
}
