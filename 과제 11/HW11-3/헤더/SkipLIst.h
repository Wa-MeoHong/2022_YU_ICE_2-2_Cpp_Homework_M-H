#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <limits>
#include <stdlib.h>

#define PROBABILITY_OF_ABOVE_LEVEL 2
#define PLUS_INF INT_MAX
#define MINUS_INF INT_MIN

using namespace std;

template<typename K, typename E>
class SkipList
{
protected:
	// class QuadNode		(SkipList�� �ʿ��� QuadNode Ŭ����)
	class QuadNode
	{
	private:
		K _key;				// ��� Ű
		E _elem;			// ��� ��
	protected:
		QuadNode* up;			// �� (level)
		QuadNode* down;			// �Ʒ� (level)
		QuadNode* prev;			// ���� ��� (�ٸ� Ű�� ����)
		QuadNode* next;			// ���� ��� (�ٸ� Ű�� ����)
		int level;				// ����(����)�� ������
	public:
		// QuadNode constructor
		QuadNode(K key =K(), E elem = E()) : _key(key), _elem(elem)
		{
			up = down = prev = next = NULL;
			level = -1;
		}
		QuadNode() {};				// default constructor

		// getter
		K& key() { return _key; }
		E& elem() { return _elem; }
		
		// setter
		void Setkey(K& k) { _key = k; }
		void SetElem(E& e) { _elem = e; }

		friend class Position;			// Position Class�� ����.
	}; // end of QuadNode class

public:
	class Position 
	{
	protected:
		QuadNode* pQN;		// member object
	public:
		// position constructor
		Position(QuadNode* pSLN) : pQN(pSLN) {}		// Position class constructor
		Position() {}								// Position class Default constructor

		// getter
		K& key() { return pQN->key(); }							// Position Node�� Ű�� ��ȯ
		E& elem() { return pQN->elem(); }						// Position Node�� Element ��ȯ
		Position below() { return Position(pQN->down); }		// �ٷ� �Ʒ��� �ִ� QuadNode ��ü ��ȯ
		Position above() { return Position(pQN->up); }			// �ٷ� ���� �ִ� QuadNode ��ü ��ȯ
		Position after() { return Position(pQN->next); }		// �ٷ� ������ �ִ� QuadNode ��ü ��ȯ
		Position before() { return Position(pQN->prev); }		// �ٷ� ������ �ִ� QuadNode ��ü ��ȯ

		// setter
		void Setbelow(Position p) { pQN->down = p.pQN; }		// �ٷ� �ؿ� �� ��� �缳��
		void Setabove(Position p) { pQN->up = p.pQN; }			// �ٷ� ���� �� ��� �缳��
		void Setafter(Position p) { pQN->next = p.pQN; }		// �ٷ� ������ �� ��� �缳��
		void Setbefore(Position p) { pQN->prev = p.pQN; }		// �ٷ� ������ �� ��� �缳��

		// operator overloading 
		bool operator==(const Position q) { return pQN == q.pQN; }		// pQN�� �ּҰ���, q.pQN�� �ּҰ��� ��ġ�ϴ°�
		bool operator!=(const Position q) { return pQN != q.pQN; }		// pQN�� �ּҰ���, q.pQN�� �ּҰ��� ��ġ���� �ʴ°�
		E& operator*() { return pQN->elem(); }					// �����Ϳ� �ִ� ���� ��ȯ
		Position operator= (const Position p)
		{
			this->pQN = p.pQN;
			return *this;
		}
		friend class SkipList;					// SkipList Class
	};		// end of Position class

private:
	Position start;
	Position end;
	int height;
	int num_elements;

public:
	// constructor 
	SkipList();

	// member functions
	Position SkipListSearch(const K& k);
	Position SkipListInsert(ostream& ostr, const K k, const E e);
	Position insertAfterAbove(ostream& ostr, Position p, Position q, const K k, const E e);
	void SkipListNodeDelete(Position p);
	void SkipListRemove(ostream& ostr, K k);
	void PrintSkipList(ostream& ostr);
};

/*				SkipList Constructor				*/
template<typename K, typename E>
inline SkipList<K, E>::SkipList()
{
	this->height = 0;
	QuadNode *pQNodeStart = new QuadNode(MINUS_INF, NULL);
	QuadNode *pQNodeEnd = new QuadNode(PLUS_INF, NULL);
	this->start = Position(pQNodeStart);
	this->end = Position(pQNodeEnd);

	// start �ʱⰪ ����
	this->start.Setafter(end);
	this->start.Setbefore(Position(NULL));
	this->start.Setabove(Position(NULL));
	this->start.Setbelow(Position(NULL));
	// end �ʱⰪ ����
	this->end.Setafter(start);
	this->end.Setbefore(Position(NULL));
	this->end.Setabove(Position(NULL));
	this->end.Setbelow(Position(NULL));

	// srand((unsigned int)time(NULL));
}

/*				SkipList member function			
		1. SkipListSearch() : SkipList�ȿ��� ��� Search 
		2. SkipListInsert() : SkipList�� Insert ( ��/ �Ʒ�, �翷 �� )
		3. insertAfterAboce() : SkipList�� ����� ���� ���� �ֱ�
		4. SkipListNodeDelete() : SkipList�� ����ϳ��� ����
		5. SkipListRemove() : SkipList ����
		6. PrintSkipList() : SkipList ���				*/

template<typename K, typename E>
inline typename SkipList<K, E>::Position SkipList<K, E>::SkipListSearch(const K& k)
{
	Position pos = this->start;

	while (pos.below() != Position(NULL))
	{
		pos = pos.below();			// ó�� ���� : start.below(). ������ start�� �ܼ��� ó�� ���� ����� �����̱� ����

		while (k >= ((pos.after()).key()))
		{
			pos = pos.after();
			if (pos.after() == Position(NULL))
				break;
		} // key���� Search��( before�� after�� key���� �ٸ��� ����)
	}

	// ��� : ã�� Key�� ���� ����(below())���� �ִ� Element�� ��ȯ / Ȥ�� start�� ��ȯ
	return pos;
}
template<typename K, typename E>
inline typename SkipList<K, E>::Position SkipList<K, E>::SkipListInsert(ostream& ostr, const K k, const E e)
{
	Position p, q, t;

	p = this->SkipListSearch(k);				// Ű���� �ش��ϴ� �κ��� ã�´� (Entry�� ���̴� �����̱� ������ ���� ���� ���� ��ȯ)
	q = Position(NULL);							// q ����

	int i = -1;
	do
	{
		i = i + 1;
		if (i >= this->height)					// ���� ����ִ� ��尡 �ƹ��͵� ���ٸ�
		{	
			this->height = this->height + 1;	
			t = start.after();
			this->start = this->insertAfterAbove(ostr, Position(NULL), this->start, MINUS_INF, E());	// ù���ۿ� ��带 �߰��Ͽ� �̾���
			this->insertAfterAbove(ostr, start, t, PLUS_INF, E());				// end ��嵵 ���� �ٿ���
		}
		q = insertAfterAbove(ostr, p, q, k, e);		// ���� �������

		while (p.above() == Position(NULL))			// ���� ��尡 �̾����� �ʾҴٸ�
		{
			p = p.before();							// ��ĭ �ڷ� ���� 
		}
		p = p.above();								// �� ��, �ڽ��� �ٷ� �� level�� ��� ���� ��ȯ �޴´�.
	} while (rand() % 2 == 0);						// 50�ۼ�Ʈ Ȯ���� Ż��
	++num_elements;
	
	return q;
}
template<typename K, typename E>
inline  typename SkipList<K, E>::Position SkipList<K, E>::insertAfterAbove(ostream& ostr, Position p, Position q, const K k, const E e)
{
	QuadNode* pNewNode = new QuadNode(k, e);					// ���ο� ��� �ϳ� ����
	
	// ����� Position �ʱⰪ ����
	Position n(pNewNode);
	n.Setabove(Position(NULL));	n.Setbelow(Position(NULL));
	n.Setafter(Position(NULL));	n.Setbefore(Position(NULL));
	
	if (p == Position(NULL))
	{
		// ���� ����Ʈ�� ��尡 �ϳ��� ���� �����
		// 1. ���� ���� NULL�� ���
		// 2. ���� ���� ���� ���
		if (q == Position(NULL))
		{
			ostr << "Trying to insert at (NULL, NULL) position" << endl;
			return Position(NULL);
		}
		else
		{
			q.Setabove(n);	n.Setbelow(q);
			n.Setabove(NULL); n.Setafter(NULL);
		}
	}

	// ����Ʈ�� ���� ����ִٸ�
	else
	{
		// ���� ��� ��ġ�� 0�̶�� 
		if (q == Position(NULL))
		{
			// ��带 �װ�, ���� ��� p�� ���� �������� �������ش� ( p�� nx���̷� ����ֱ� ���� )
			Position nx;
			ostr << "insert a node (" << n.key() << "at level 0 )" << endl;

			nx = p.after();
			p.Setafter(n);	n.Setbefore(p);
			n.Setafter(nx);	nx.Setbefore(n);
			n.Setbelow(Position(NULL));	n.Setabove(Position(NULL));
		}
		else
		{
			// �ƴ϶�� p ���� ��� ��Ʈ���� ���� �����ִ´�. ( 4���� ������ �̾��� ) 
			Position nx, ny;
			nx = p.after();
			n.Setafter(nx);
			if (nx != Position(NULL))
				nx.Setbefore(n);
			p.Setafter(n);	n.Setbefore(p);

			ny = q.above();
			q.Setabove(n);	n.Setbelow(q);
			n.Setabove(ny);
			if (ny != Position(NULL))
				ny.Setbelow(n);
		}
	}

	return n;
}
template<typename K, typename E>
inline void SkipList<K, E>::SkipListNodeDelete(Position p)
{
	Position pprev, pnext;			// ������ ����� �� ��

	if (p != Position(NULL))
	{
		pprev = p.before();				// ������ ����� ���� ���
		pnext = p.after();				// ������ ����� ���� ���
		// ���� �̾��� ��
		if (pprev != Position(NULL))
			pprev.Setafter(pnext);
		if (pnext != Position(NULL))
			pnext.Setbefore(pprev);

		delete p.pQN;				// ���� 
	}
}
template<typename K, typename E>
inline void SkipList<K, E>::SkipListRemove(ostream& ostr, K k)
{
	Position p, pprev, pnext, p00, px0, p0y, pxy, old_p;
	int h_max = 0, h = 0;

	p = this->SkipListSearch(k);					// ������ Ű�� ��ġ�� ã��
	if ((p.key() != k) || (p.key() == MINUS_INF))		// ���� Ű�� ��ã�ų� start�� �ӹ��� ���� ���
	{
		ostr << "Key (" << k << ") is not found in SkipList !!" << endl;
		return;
	}
	
	// ���� p�� NULL�� �ɶ����� Key�� ���鸦 ������
	while (p != Position(NULL))
	{
		old_p = p;
		p = p.above();
		this->SkipListNodeDelete(old_p);
	}
	ostr << "Deleted skip list node (Key : " << k << ")" << endl;
	
	// ��� ����
	p00 = this->start;
	for (int i = this->height; i > 0; i--)
		p00 = p00.below();
	px0 = p00.after();		// �� ó�� start����� �ٷ� ���� ���
	pxy = this->start;
	while (px0.key() != PLUS_INF)
	{
		pxy = px0;
		h = 0; 
		while (pxy != Position(NULL))
		{
			++h;
			pxy = pxy.above();
		}
		if (h_max < h)
			h_max = h;
		px0 = px0.after();
	}
	// ���� h_max�� ���� ���̺��� �� ���ٸ�
	if (h_max < this->height) 
	{
		ostr << "Current height is less than the new h_max (" << h_max
			<< ") ==> need adjustment !!" << endl;
	}

	// ���� ����ŭ ��� ���� 
	for (int i = 0; i < (this->height - h_max); i++)
	{
		p0y = this->start;
		pxy = this->start.after();
		this->start = this->start.below();
		this->SkipListNodeDelete(pxy);
		this->SkipListNodeDelete(p0y);
	}
	this->height = h_max;			// ����
}
template<typename K, typename E>
inline void SkipList<K, E>::PrintSkipList(ostream& ostr)
{
	Position p, p00, px0, p0y, pxy, q, q0, qx;
	int level;

	ostr << "Print SkipList Inside :  current height (" << this->height << ")" << endl;

	p00 = this->start;
	level = this->height;

	for (int i = this->height; i > 0; i--)
		p00 = p00.below();
	p0y = this->start;
	pxy = this->start;
	for (level = this->height; level >= 0; level--)
	{
		ostr << "level" << setw(2) << level << " ";			// ���� ���
		if (pxy.key() == MINUS_INF)							// ���� ���� �κ��̶��
			ostr << "-oo";
		else
			ostr << setw(5) << pxy.key();					// Ű�� ���
		
		px0 = p00.after();									// ���� ���
		for (pxy = p0y.after();; pxy = pxy.after())			// ��� ���
		{
			while ((px0.key() != pxy.key()))
			{
				ostr << "-----";							// ���� Ű�� ��ã���� ������ ���
				px0 = px0.after();
			}
			if (pxy.key() == PLUS_INF)		// Ż����
				break;	
			else
			{
				ostr << "-" << setw(4) << pxy.key();		// ã���� Ű�� ���
			}
			px0 = px0.after();
		}

		if (pxy.key() == PLUS_INF)							// �� �κ� ���
			ostr << "+oo";
		else
			ostr << setw(5) << pxy.key();

		ostr << endl;
		p0y = p0y.below();
		pxy = p0y;
	}	// �ݺ�
	ostr << endl;
}



#endif // !SKIPLIST_H
