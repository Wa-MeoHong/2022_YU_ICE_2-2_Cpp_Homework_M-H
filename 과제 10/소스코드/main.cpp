/*
  ���ϸ� : "HW10_21912193_�Ŵ�ȫ"
  ���α׷��� ���� �� �⺻ ���:
	- Binary Search Tree�� �����ϰ�, BST�� ������ �����ϱ�����, ���뷱���� �����ϴ� �˰���
  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 11�� 15��)
  ���� Update : Version 1.0.1, 2022�� 11�� 18��(�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������	  ������			����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
	�Ŵ�ȫ		 2022/11/15		v1.0.0		  �����ۼ�
	�Ŵ�ȫ		 2022/11/17		v1.1.0		  �ڵ�ϼ�
	�Ŵ�ȫ		 2022/11/18		v1.1.1		  rotate_RL ����
===========================================================================================================
*/

#include "T_BST.h"
#include "T_Array.h"
#include "T_Entry.h"
#include "Date.h"
#include "Student.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

#define INPUT "students.txt"
#define OUTPUT "output.txt"

Student* fGetStudentRecords(string f_name, int* num_students)		// �����Է��� �ް��ϴ� �Լ�
{
	ifstream fin(f_name);
	Student* pSts = NULL;
	string name, date_str;
	int st_id = 0, year = 0, month = 0, day = 0;
	double gpa = 0.0;

	if (fin.fail())
	{
		cout << "Error! does not open students.txt!\n";
		exit(-1);
	}

	fin >> *num_students;
	pSts = new Student[*num_students];				// �迭 �����Ҵ�
	
	cout << "Number of Students (from file) = " << *num_students << endl;

	for (int i = 0; i < *num_students; i++)
	{
		fin >> st_id >> name >> date_str >> gpa;	// �й�, �̸�, ������� ���ڿ�, ���� ������ �޾ƿ�
		
		for (int i = 0; i < date_str.size(); i++)
		{
			if (date_str[i] == '-')
				date_str[i] = ' ';
		}
		stringstream date_ss;
		date_ss.str(date_str);					// �и��� ���ڿ��� stringstream��ü�� �ְ�
		date_ss >> year >> month >> day;		// �������� �и��ϸ鼭 ���� �־���

		// �޾ƿ� �����͸� ���� Student��ü ����
		pSts[i] = Student(st_id, name, Date(year, month, day), gpa);

	}

	fin.close();
	return pSts;			// ������ �ݰ� ��ȯ


}

int main(void)
{
	ofstream fout(OUTPUT);
	int num_students = 0;
	Student* students = fGetStudentRecords(INPUT, &num_students);

	if (fout.fail())
	{
		cout << "Error! does not open output.txt!\n";
		exit(-1);
	}

	fout << "Input students[] array : " << endl;
	for (int i = 0; i < num_students; i++)
	{
		fout << students[i] << endl;					// ���Ϸκ��� ������ Student��ü�� ���(1�پ�)
	}
	fout << endl;

	/* 1. Balanced ����Ž��Ʈ�� ���� ( Key�� �л��� �̸� ) */
	fout << endl << "Balanced Binary Search Tree (BBST) with key Student_Name" << endl;
	T_Entry<string, Student*> entry_name_pST;
	T_BST<string, Student*> BBST_keyname("BBST_keyname");
	T_BSTN<string, Student*>* pRoot = NULL, ** ppBBST_Root = NULL;
	ppBBST_Root = BBST_keyname.RootAddr();

	// ����Ž��Ʈ���� ���� �������. (���뷱�̵� ���� ����)
	for (int i = 0; i < num_students; i++)
	{
		entry_name_pST.SetKey(students[i].Name());
		entry_name_pST.SetVal(&students[i]);
		BBST_keyname.insertAndReBal(entry_name_pST);			// insert�� ���뷱���� ���ÿ� ó��
	}
	// ���� ����Ž��Ʈ���� �����
	fout << "\nEntries in " << BBST_keyname.Name() << " (in order to Student_Name) : " << endl;
	BBST_keyname.print_with_Depth(fout);


	/* 2. Balanced ����Ž��Ʈ�� ���� ( Key�� �й� ) */
	fout << endl << "Balanced Binary Search Tree (BBST) with key student_StID " << endl;
	T_Entry<int, Student*> entry_StID_pST;
	T_BST<int, Student*> BBST_keyStID("BBST_keyStID");
	T_BSTN<int, Student*>* pBBST_keyStID = NULL, ** ppRoot_BBST_keyStID= NULL;
	ppRoot_BBST_keyStID = BBST_keyStID.RootAddr();

	// ����Ž��Ʈ���� ���� �������. (���뷱�̵� ���� ����)
	for (int i = 0; i < num_students; i++)
	{
		entry_StID_pST.SetKey(students[i].StID());
		entry_StID_pST.SetVal(&students[i]);
		BBST_keyStID.insertAndReBal(entry_StID_pST);			// insert�� ���뷱���� ���ÿ� ó��
	}
	// ���� ����Ž��Ʈ���� �����
	fout << "\nEntries in " << BBST_keyStID.Name() << " (in order to Book Title) : " << endl;
	BBST_keyStID.print_with_Depth(fout);

	/* 3. Balanced ����Ž��Ʈ�� ���� ( Key�� �л��� ������� ) */
	fout << endl << "Balanced Binary Search Tree (BBST) with key Birth-date" << endl;
	T_Entry<Date, Student*> entry_BirthDate_pST;		// �л� ��Ʈ��
	T_BST<Date, Student*> BBST_keyBirthDate("BBST_keyBirthDate");
	T_BSTN<Date, Student*>*pBBST_keyBirth = NULL, ** ppRoot_BBST_keyBirthDate = NULL;
	ppRoot_BBST_keyBirthDate = BBST_keyBirthDate.RootAddr();

	for (int i = 0; i < num_students; i++)
	{
		// ����Ž��Ʈ���� ���� �������. (���뷱�̵� ���� ����)
		entry_BirthDate_pST.SetKey(students[i].BirthDate());
		entry_BirthDate_pST.SetVal(&students[i]);
		BBST_keyBirthDate.insertAndReBal(entry_BirthDate_pST);
	}
	// ���� ����Ž��Ʈ���� �����
	fout << "\nEntries in " << BBST_keyBirthDate.Name() << " (in order to Student BirthDate) : " << endl;
	BBST_keyBirthDate.print_with_Depth(fout);


	// Testing Search on Binary Search Tree
	Date StDoB = students[0].BirthDate();
	Date d1(1995, 1, 1), d2(1999, 12, 31);				// 1995.01.01 ~ 1999.12.31 ������ ��¥�ȿ���
	Student* pSt;
	T_Array<Student*> array_pST(1, string("Array_Student"));
	pBBST_keyBirth = BBST_keyBirthDate.searchBSTN(StDoB);			// �� ���� �ش�Ǵ� ��带 ã�´�. 
	BBST_keyBirthDate.travelsal_inOrder(pBBST_keyBirth, array_pST);	// ��ȸ�ϸ鼭 ���� ������ ���
	cout << "\nStudents of birth date during " << d1 << " ~ " << d2 << ": " << endl;
	for (int i = 0; i < array_pST.size(); i++)
	{
		// ���� ��¥ d1, d2������ ��������̶�� ����Ѵ�.
		pSt = array_pST[i];
		if ((pSt->BirthDate() >= d1) && (pSt->BirthDate() <= d2))
			cout << *pSt << endl;
	}

	/* 4. Remove root entry */
	fout << "\nRemoving the root entry in sequence . . ." << endl;
	for (int i = 0; i < num_students; i++)
	{
		pRoot = BBST_keyname.Root();				// ��Ʈ���(�ֻ��� ���) ������
		entry_name_pST = pRoot->Entry();			// ��Ʈ����� ��Ʈ��( ��)�� ������
		fout << "\nremove " << entry_name_pST << endl;		
		BBST_keyname.eraseBSTN(&pRoot);				// ��Ʈ��� ����
		BBST_keyname.print_with_Depth(fout);		// ���
	}

	// �� �߱� ������ ���� ���� ����
	fout << "\nClearing BBST_STs . . . " << endl;
	BBST_keyStID.clear();
	BBST_keyBirthDate.clear();
	fout << "All BBST_STs cleared !! " << endl;

	fout.close();
	if (students != NULL)
		delete[] students;

	return  0;

}