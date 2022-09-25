#ifndef MTRXARRAY_H
#define MTRXARRAY_H

#include "Mtrx.h"
#include <iostream>

using namespace std;

class MtrxArray
{
public:
	MtrxArray(int array_size);
	~MtrxArray();
	Mtrx& operator[](int);

private:
	Mtrx* pMtrx;
	int mtrxArraySIZE;
	bool isValidIndex(int index);
};

#endif