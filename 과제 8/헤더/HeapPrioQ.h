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

/*					constructor ( 생성자 )				*/
template<typename K>
inline HeapPrioQueue<K>::HeapPrioQueue(int capa, string nm)
	: CompleteBinaryTree<K>(capa, nm), capacity(capa)
{
}

/*					destructor ( 소멸자 )				*/
template<typename K>
inline HeapPrioQueue<K>::~HeapPrioQueue()
{
	cout << "HeapPriority Queue is destructed !" << endl;
}

/*				member function ( 멤버 함수 )
		1. HeapMin() ( Heap Queue의 가장 우선순위가 낮은 값 반환 )
		2. Insert(elem) ( 큐에 */

template<typename K>
inline T_Entry<K>* HeapPrioQueue<K>::HeapMin()
{
	T_Entry<K>* pMinElem;
	if (size() <= 0)
	{
		return NULL;
	}
	// ROOT노드를 복사해서 가져와서 반환함
	pMinElem = (T_Entry<K> *)new T_Entry<K>;
	*pMinElem = this->RootElement();
	return pMinElem;
}

template<typename K>
inline int HeapPrioQueue<K>::insert(T_Entry<K> elem)
{
	int index, ParentIndex;
	T_Entry<K> temp;

	// 만약 가득찼다면 큐에 담지않고 바로 return 한다.
	if (isFull())
	{
		cout << "Error! Queue is Full !!" << endl;
		return size();
	}
	// 큐에 넣고 그 인덱스 값을 반환받음 ( 정렬을 하기 위해 쓰임 ) 
	index = this->add_at_end(elem);

	while (index != CBT_ROOT)
	{
		ParentIndex = this->parentIndex(index);		// 마지막 인덱스의 부모 노드
		if (this->t_GA[index] >= this->t_GA[ParentIndex])		// 만약 인덱스번호가 부모것보다 크다면( 우선순위가 낮다면) 
			break;									// 그대로 놔둔다
		else
		{
			// 아니면 부모노드와 바꾼다.
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

	// 만약 queue의 크기가 0이하라면 Null 반환
	int HPQ_Size = this->size();
	if (HPQ_Size <= 0)
		return NULL;

	pMinElem = (T_Entry<K>*) new T_Entry<K>;
	// ROOT 노드의 것을 꺼내고 삭제함
	*pMinElem = this->RootElement();
	if (HPQ_Size == 1)
	{
		this->removeCBTEnd();
	}

	else
	{
		// 부모노드는 1, 그리고, 맨 마지막의 값으로 덮어씌워진다.
		index_p = CBT_ROOT;
		this->t_GA[CBT_ROOT] = this->t_GA[this->end];
		this->end--;

		while (this->hasLeftChild(index_p))
		{
			// c = 왼쪽 자식, rc = 오른쪽 자식
			index_c = this->leftChildIndex(index_p);
			index_rc = this->rightChildIndex(index_p);
			// 만약 오른쪽 노드가 있고, 오른쪽이 더 우선 순위가 높다면, rc의 값을 사용한다.
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



