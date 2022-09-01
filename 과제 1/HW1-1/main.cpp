/*
  ���ϸ� : "HW1-1_21912193_�Ŵ�ȫ"
  ���α׷��� ���� �� �⺻ ���:
	- ���Ϸκ��� �����͸� �Է� �ް�, ������ ����� ���Ϸ� ����ϴ� ���α׷�

  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 8�� 29��)
  ���� Update : Version 1.0.0, 2022�� 8�� 29�� (�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������		   ������		 ����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
   �Ŵ�ȫ		 2022/08/29		v1.0.0		  �����ۼ�

===========================================================================================================
*/

#include <iostream>
#include <fstream>
#include <iomanip>

#define INPUT "Input_data.txt"								// INPUT (Input_data.txt) ��ũ��
#define OUTPUT "Output.txt"									// OUTPUT (Output.txt) ��ũ��
#define MAX(x, y) ((x) > (y)) ? (x) : (y)					// �ִ밪 ã�� ��ũ���Լ�
#define MIN(x, y) ((x) < (y)) ? (x) : (y)					// �ּҰ� ã�� ��ũ���Լ�

using namespace std;

int fileInputData(ifstream& fin, int* &data_array, int* max_num_data);		// input ���Ͽ��� �о����
void StaticData(ofstream& fout, int* data_array, int num_data);				// �о�� �����͸� ���� ����ϱ�

int main()
{
	ifstream fin;											// �о�� ���Ͽ� ifstream ����
	ofstream fout;											// ��¿� ���Ͽ� ofstream ����

	int* data_array = NULL;									// ���Ͼȿ� �ִ� ������ ������ ���� �����Ҵ���
	int max_num_data;										// �����ͳ����� MAX��
	int num_data;											// �о�� �������� ����

	/*			>> ����� ���� ���� <<
		1. �Է¿�, ��¿� ������ ����.
		2. ���� ���Ͽ��� �b�� �����޼��� ����� ����.
	*/
	fin.open(INPUT);
	if (fin.fail())
	{
		cout << "Error! Doesn't Open File!" << endl;
		exit;
	}

	fout.open(OUTPUT);
	if (fout.fail())
	{
		cout << "Error! Doesn't Open File!" << endl;
		exit;
	}

	/*				>> �����͸� �а� ��� <<
		1. ���� �����͸� �о�� �������� ������ ��ȯ ����
		2. �о�� �����͸� ������ ��� ��, �ִ�, �ּ�, ���, �л�, ǥ�������� ���
	*/
	num_data = fileInputData(fin, data_array, &max_num_data);
	cout << "Input Data Complete..!" << endl;
	StaticData(fout, data_array, num_data);
	cout << "Calculate Data Complete..!" << endl;

	/*					>> ������ <<
		1. data_array�� �����Ҵ��� �Ͽ����Ƿ� �������ش�.
		2. ���� ���ϵ��� ��� �ݾ��ش�.
	*/
	free(data_array);
	fin.close();
	fout.close();
}

int fileInputData(ifstream& fin, int* &data_array, int* max_num_data)		// input ���Ͽ��� �о���� (�迭�� ��ȯ�ϹǷ� &(����������)�� Ȱ����)
{
	int count = 0;										// �о���� �������� ����
	int temp = 0;										// �����͸� �б����ؼ� �ʿ��� �ӽú���

	/*				>> ���Ͼȿ� �ִ� ������ ���� ���� <<
		1. ������ �о�;� Ŀ���� �̵��ϹǷ� �ӽú��� temp�� �̿��� �а� ī��Ʈ��
		2. �������� �ٽ� �о���ϹǷ� Ŀ���� �� ó������ ������.
	*/

	while (!fin.eof())									// ������ ����������
	{
		fin >> temp;									// ���Ͽ��� �����͸� �о��
		count++;										// �о�� �������� ���� üũ
	}
	fin.seekg(ios::beg);								// �������� �ٽ� ó������ Ŀ���� �̵�

	/*				>> ���Ͼȿ� �ִ� ������ ���� �б� <<
		1. �о�� �������� ������ ���� data_array�� �����Ҵ� ���ش�.
		2. ó������ �����͸� �о �ϳ��ϳ� �������ش�.
		3. �� ��, �ִ밪�� ã������ max_num_data�� �ʱⰪ�� ���� ���� ��, �ִ밪�� ã�´�.
		4. �о�� �������� ������ ��ȯ�Ѵ�.
	*/
	data_array = (int*)calloc(sizeof(int), count);
	if (data_array == NULL)
	{
		cout << "Error! Doesn't calloc data_array!" << endl;
		exit;
	}


	for (int i = 0; i < count; i++)
		fin >> data_array[i];

	*max_num_data = data_array[0];						// max_num_data�� �ʱ�ȭ

	for (int j = 1; j < count; j++)							// �ִ밪 ã��
	{
		*max_num_data = MAX(data_array[j], * max_num_data);	// MAX��ũ�θ� �̿��� ã�´�. (���ǿ����� Ȱ��)
	}

	return count;										// ������ ���� ��ȯ
}

void StaticData(ofstream& fout, int* data_array, int num_data)		// ������ ���� �Լ�
{
	int min = data_array[0], max = data_array[0], sum = 0;			// min, max, sum ����
	double powSUM = 0, avg = 0, var = 0, std_dev = 0;				// double�� ����, powSUM(������ ��), avg, var, std_dev(ǥ������)

	// ���� ���
	fout << "Total " << num_data << " input from input data file." << endl;
	fout << "Total " << num_data << " integer data : (";

	// ������ ���
	for (int i = 0; i < num_data; i++)
	{
		fout << data_array[i] << ", ";								// ������ ���
		min = MIN(data_array[i], min);								// min �� ã�� (���ǿ����� �̿�)
		max = MAX(data_array[i], max);								// max �� ã�� (���ǿ����� �̿�)
		sum += data_array[i];										// sum ���ϱ� (�ջ���)
		powSUM += pow(data_array[i], 2);							// powSUM ���ϱ� (������ ��)
	}
	fout << ")" <<  endl;

	// ���, �л�, ǥ������ ���ϱ� 
	avg = (double)sum / (double)num_data;							// ��� = �� / ����
	var = (powSUM / (double)num_data) - pow(avg, 2);				// �л� = ������ ��� - ����� ����
	std_dev = sqrt(var);											// ǥ������ = ��л�
	
	// ������ ���
	fout << "min(" << min << "), max(" << max << "), avg(" << avg << "), var(" << var
		<< "), std_dev (" << std_dev << ")" << endl;
}

