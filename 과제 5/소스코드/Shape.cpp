#include "Shape.h"
#include "Color.h"

/*				constructor ( 생성자 )				
		1. default constructor ( 디폴트 생성자 )
		2. name만 인수를 받는 constructor
		3. 모든 인자를 받는 constructor				*/
Shape::Shape()
{
	pos_x = 0;
	pos_y = 0;							// 좌표는 원점 (0, 0)
	angle = 0.0;						// 각도 0.0도로 초기화
	name = "";							// 이름도 없음
	color = RGB_BLACK;					// 디폴트 초기값은 검은색으로 설정
}
Shape::Shape(string name)
{
	pos_x = 0;
	pos_y = 0;							// 좌표는 원점 (0, 0)
	angle = 0.0;						// 각도 0.0도로 초기화
	NameSet(name);						// 이름도 없음
	color = RGB_BLACK;					// 디폴트 초기값은 검은색으로 설정
}
Shape::Shape(int px, int py, double angle, COLORREF color, string name)
	: color(color), angle(angle)		// 미리 각도와 색깔은 설정
{
	set_Pos_X(px);						// 함수를 통한 설정
	set_Pos_Y(py);
	NameSet(name);
}

/*				destructor ( 소멸자 )			*/
Shape::~Shape()
{
	cout << "Shape class terminated!" << endl;
	// pos_x = 0;
	// pos_y = 0;
	// angle = 0.0;
	// name = "";
	// color = 
}

/*				member functions ( 멤버 함수들 )				
		1. draw() (미구현, 쓰는데가 없다..)
		2. print(ostream&) const ( 출력 함수 )				*/
void Shape::draw()
{
	// draw shape
}
void Shape::print(ostream& out) const
{
	// 출력 순서 : 좌표 - 각도 - 색깔 (각도는 고정소수점 2자리까지 )
	out << "pos (" << setw(3) << this->Pos_X() << ", " << setw(3) << this->Pos_Y() << "), ";
	out.setf(ios::showpoint); out.setf(ios::fixed);						// 고정 소수점 2자리까지만 출력
	out.precision(2);
	out << "angle (" << this->angle << "), ";	out.unsetf(ios::adjustfield);
	out << "color ("; printRGB(out, this->color) << ")";
}

/*				operator Overloading ( 연산자 오버로드 )				
		1. 대입 연산자 ( = )
		2. 출력 연산자 ( << )										*/
Shape& Shape::operator=(const Shape& s)
{
	this->set_Pos_X(s.Pos_X());				// 좌표 대입 ( x, y )
	this->set_Pos_Y(s.Pos_Y());
	this->NameSet(s.Name());				// 이름 대입
	this->angle = s.angle;					// 각도 대입
	this->color = s.color;					// 색깔 대입

	return *this;							// 자기자신 반환
	// TODO: 여기에 return 문을 삽입합니다.
}
ostream& operator<<(ostream& out, const Shape s)			// 연산자 오버로딩 출력
{
	out << setw(15) << s.Name() << ": ";	s.print(out);			// 출력
	return out; 
	// TODO: 여기에 return 문을 삽입합니다.
}