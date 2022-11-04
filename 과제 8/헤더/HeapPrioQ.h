#ifndef HEAP_PRIO_QUEUE_H
#define HEAP_PRIO_QUEUE_H

#include "CBT.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template<typename K>
class HeapPrioQueue : public CompleteBinaryTree<K>
{
public:
	HeapPrioQueue(int capa, string nm);
	~HeapPrioQueue();

	// getter 
	bool isEmpty() { return this->size() == 0; }
	bool isFull() { return this->size() == this->capacity; }
	int size() { return this->end; }
	T_Entry<K>* HeapMin();

	// member functions
	int insert(T_Entry<K> elem);
	T_Entry<K>* removeHeapMin();
	void fprint(ostream& ostr);
private:
	int capacity;
};

/*					constructor ( ������ )				*/
template<typename K>
inline HeapPrioQueue<K>::HeapPrioQueue(int capa, string nm)
	: CompleteBinaryTree<K>(capa, nm), capacity(capa)
{
}

/*					destructor ( �Ҹ��� )				*/
template<typename K>
inline HeapPrioQueue<K>::~HeapPrioQueue()
{
	cout << "HeapPriority Queue is destructed !" << endl;
}

/*				member function ( ��� �Լ� )
		1. HeapMin() ( Heap Queue�� ���� �켱������ ���� �� ��ȯ )
		2. Insert(elem) ( ť�� */

template<typename K>
inline T_Entry<K>* HeapPrioQueue<K>::HeapMin()
{
	T_Entry<K>* pMinElem;
	if (size() <= 0)
	{
		return NULL;
	}
	// ROOT��带 �����ؼ� �����ͼ� ��ȯ��
	pMinElem = (T_Entry<K> *)new T_Entry<K>;
	*pMinElem = this->RootElement();
	return pMinElem;
}

template<typename K>
inline int HeapPrioQueue<K>::insert(T_Entry<K> elem)
{
	int index, ParentIndex;
	T_Entry<K> temp;

	// ���� ����á�ٸ� ť�� �����ʰ� �ٷ� return �Ѵ�.
	if (isFull())
	{
		cout << "Error! Queue is Full !!" << endl;
		return size();
	}
	// ť�� �ְ� �� �ε��� ���� ��ȯ���� ( ������ �ϱ� ���� ���� ) 
	index = this->add_at_end(elem);

	while (index != CBT_ROOT)
	{
		ParentIndex = this->parentIndex(index);		// ������ �ε����� �θ� ���
		if (this->t_GA[index] >= this->t_GA[ParentIndex])		// ���� �ε�����ȣ�� �θ�ͺ��� ũ�ٸ�( �켱������ ���ٸ�) 
			break;									// �״�� ���д�
		else
		{
			// �ƴϸ� �θ���� �ٲ۴�.
			temp = this->t_GA[index];
			this->t_GA[index] = this->t_GA[ParentIndex];
			this->t_GA[ParentIndex] = temp;
			index = ParentIndex;
		}
	}
	return size();
}

template<typename K>
inline T_Entry<K>* HeapPrioQueue<K>::removeHeapMin()
{
	int index_p, index_c, index_rc;
	T_Entry<K>* pMinElem = NULL;
	T_Entry<K> temp, t_p, t_c;

	// ���� queue�� ũ�Ⱑ 0���϶�� Null ��ȯ
	int HPQ_Size = this->size();
	if (HPQ_Size <= 0)
		return NULL;

	pMinElem = (T_Entry<K>*) new T_Entry<K>;
	// ROOT ����� ���� ������ ������
	*pMinElem = this->RootElement();
	if (HPQ_Size == 1)
	{
		this->removeCBTEnd();
	}

	else
	{
		// �θ���� 1, �׸���, �� �������� ������ ���������.
		index_p = CBT_ROOT;
		this->t_GA[CBT_ROOT] = this->t_GA[this->end];
		this->end--;

		while (this->hasLeftChild(index_p))
		{
			// c = ���� �ڽ�, rc = ������ �ڽ�
			index_c = this->leftChildIndex(index_p);
			index_rc = this->rightChildIndex(index_p);
			// ���� ������ ��尡 �ְ�, �������� �� �켱 ������ ���ٸ�, rc�� ���� ����Ѵ�.
			if (this->hasRightChild(index_p) && (this->t_GA[index_c] > this->t_GA[index_rc]))
				index_c = index_rc;
			t_p = this->t_GA[index_p]; t_c = this->t_GA[index_c];
			if (t_p > t_c)
			{
				//swaping
				temp = t_p;
				this->t_GA[index_p] = this->t_GA[index_c];
				this->t_GA[index_c] = temp;
				index_p = index_c;

			}
			else
				break;
		} // end while
	}

	return pMinElem;
}

template<typename K>
inline void HeapPrioQueue<K>::fprint(ostream& ostr)
{
	if (this->size() <= 0) // if is empty
	{
		ostr << "Error ! Queue is Empty !! " << endl;
		return;
	}
	else
		CompleteBinaryTree<K>::fprintCBT(ostr);
}

#endif // !HEAP_PRIO_QUEUE_H



