#ifndef BIG_ARRAY_H

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

typedef struct ArrayStatistics {
	int min;					// �ּҰ�
	int max;					// �ִ밪
	double avg;					// ���
	double var;					// �л�
	double std_dev;				// ǥ������
}Statistics;

class BigArray
{
public:
	BigArray(int n);			// constructor (������)
	~BigArray();				// destructor (�Ҹ���)
	int* genBigRandArray(int size, int offset);		// BigRand �迭�� �����ϴ� �Լ�
	int size() { return num_elements; }				// �迭�� ũ�� ��ȯ
	void suffle();									// �迭 ����
	void selection_sort();							// �迭 ��������
	void quick_sort();								// �迭 ������
	void getStatistics(Statistics&);				// �迭 ������ ���
	void fprintStatistics(ostream& fout);			// �迭 ������ ����� ���
	void fprintBigArray(ostream& fout, int num_per_line);		// �迭 ���� ���

private:
	int* big_array = NULL;				// ������ ���� big_array
	int num_elements = 0;				// ������ �迭 ������
};

#endif