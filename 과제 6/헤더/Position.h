#ifndef POSITION_H
#define POSITION_H

#include <iostream>

using namespace std;

class Position
{
	friend ostream& operator<<(ostream& ostr, const Position& pos);

public:
	//constructor, destructor
	Position() : px(0), py(0) {};					// 기본은 (0, 0)
	Position(int x, int y) : px(x), py(y) {};		// 값 대입 생성자
	~Position();									// 소멸자

	//getter
	int pX() const { return px; }					// x 좌표
	int pY() const { return py; }					// y 좌표

	//setter
	void set_pX(int x) { px = x; }
	void set_pY(int y) { py = y; }

	//member funcion
	void printPos(ostream& ostr) const ;		// 출력 
	
	//operator overloading
	Position& operator=(const Position& pos);	// 대입연산자

private:
	int px;
	int py;
};

#endif // !POSITION_H

