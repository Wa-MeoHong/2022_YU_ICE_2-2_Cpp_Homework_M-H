#ifndef POSITION_H
#define POSITION_H

#include <iostream>

using namespace std;

class Position
{
	friend ostream& operator<<(ostream& ostr, const Position& pos);

public:
	//constructor, destructor
	Position() : px(0), py(0) {};					// �⺻�� (0, 0)
	Position(int x, int y) : px(x), py(y) {};		// �� ���� ������
	~Position();									// �Ҹ���

	//getter
	int pX() const { return px; }					// x ��ǥ
	int pY() const { return py; }					// y ��ǥ

	//setter
	void set_pX(int x) { px = x; }
	void set_pY(int y) { py = y; }

	//member funcion
	void printPos(ostream& ostr) const ;		// ��� 
	
	//operator overloading
	Position& operator=(const Position& pos);	// ���Կ�����

private:
	int px;
	int py;
};

#endif // !POSITION_H

