#include "Position.h"


Position::~Position()
{
	// destruct Position Class
}

// ��� �Լ�
void Position::printPos(ostream& ostr) const
{
	// ��ǥ ��� 
	ostr << px << ", " << py;
}

Position& Position::operator=(const Position& pos)
{
	// x, y ��ǥ ����
	this->set_pX(pos.pX());
	this->set_pY(pos.pY());

	return *this;					// ��ȯ
	// TODO: ���⿡ return ���� �����մϴ�.
}

ostream& operator<<(ostream& ostr, const Position& pos)
{
	// ��ǥ ��� ����
	ostr << "pos("; pos.printPos(ostr);
	ostr << ")";

	return ostr;
	// TODO: ���⿡ return ���� �����մϴ�.
}
