#ifndef T_ENTRY_H
#define T_ENTRY_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template<typename K>
class T_Entry
{
	// operator Overloading (��� ������)
	friend ostream& operator<< (ostream& ostr, T_Entry<K>& entry)
	{
		// print format ( [key , Value] )
		ostr << setw(2) << entry.Key() ;
		return ostr;
	}

public:
	// constructor
	T_Entry() { _key = 999; }		// default constructor
	T_Entry(K key) { _key = key; }

	// setter
	void SetKey(const K& key) { _key = key; }
	//void SetVal(const V& value) { _value = value; }

	// getter
	K Key() const { return _key; }				// return key
	//V Val() const { return _value; }			// return value

	// operator Overloading ( �񱳿����� �����ε� )
	// >, >=, <, <=, ==, =
	bool operator> (const T_Entry& right) { return (this->Key() > right.Key()); }
	bool operator>= (const T_Entry& right) { return (this->Key() >= right.Key()); }
	bool operator< (const T_Entry& right) { return (this->Key() < right.Key()); }
	bool operator<= (const T_Entry& right) { return (this->Key() <= right.Key()); }
	bool operator== (const T_Entry& right) { return (this->Key() == right.Key()); }
	T_Entry& operator= (T_Entry& right);
	void Print(ostream& ostr);					// print Entry
private:
	K _key;			// Ű
	//V _value;		// ��
};



template<typename K>			// ���Կ����� = 
inline T_Entry<K>& T_Entry<K>::operator=(T_Entry& right)
{
	this->SetKey(right.Key());				// Ű ����
	//this->SetVal(right.Val());				// �� ���� (�̺�Ʈ ����)

	return *this;							// ���� ��ȯ
}

template<typename K>
inline void T_Entry<K>::Print(ostream& ostr)			// ���
{
	// print format : _key
	ostr << setw(2) << this->Key();

	// print format : [Key : _key , Event(~)]
	/*ostr << "[Key: " << setw(2) << this->Key() << ", "
		<< *this->Val() << "]";*/
}


#endif // !T_ENTRY_H


