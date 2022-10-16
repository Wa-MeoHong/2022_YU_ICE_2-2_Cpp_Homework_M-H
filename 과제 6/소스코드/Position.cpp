#include "Position.h"


Position::~Position()
{
	// destruct Position Class
}

// 출력 함수
void Position::printPos(ostream& ostr) const
{
	// 좌표 출력 
	ostr << px << ", " << py;
}

Position& Position::operator=(const Position& pos)
{
	// x, y 좌표 대입
	this->set_pX(pos.pX());
	this->set_pY(pos.pY());

	return *this;					// 반환
	// TODO: 여기에 return 문을 삽입합니다.
}

ostream& operator<<(ostream& ostr, const Position& pos)
{
	// 좌표 출력 형식
	ostr << "pos("; pos.printPos(ostr);
	ostr << ")";

	return ostr;
	// TODO: 여기에 return 문을 삽입합니다.
}
