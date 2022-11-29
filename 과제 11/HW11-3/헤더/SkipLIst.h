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
	// class QuadNode		(SkipList에 필요한 QuadNode 클래스)
	class QuadNode
	{
	private:
		K _key;				// 노드 키
		E _elem;			// 노드 값
	protected:
		QuadNode* up;			// 위 (level)
		QuadNode* down;			// 아래 (level)
		QuadNode* prev;			// 다음 노드 (다른 키를 가진)
		QuadNode* next;			// 이전 노드 (다른 키를 가진)
		int level;				// 레벨(높이)가 몇인지
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

		friend class Position;			// Position Class도 쓴다.
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
		K& key() { return pQN->key(); }							// Position Node의 키값 반환
		E& elem() { return pQN->elem(); }						// Position Node의 Element 반환
		Position below() { return Position(pQN->down); }		// 바로 아래에 있는 QuadNode 객체 반환
		Position above() { return Position(pQN->up); }			// 바로 위에 있는 QuadNode 객체 반환
		Position after() { return Position(pQN->next); }		// 바로 다음에 있는 QuadNode 객체 반환
		Position before() { return Position(pQN->prev); }		// 바로 이전에 있는 QuadNode 객체 반환

		// setter
		void Setbelow(Position p) { pQN->down = p.pQN; }		// 바로 밑에 올 노드 재설정
		void Setabove(Position p) { pQN->up = p.pQN; }			// 바로 위에 올 노드 재설정
		void Setafter(Position p) { pQN->next = p.pQN; }		// 바로 다음에 올 노드 재설정
		void Setbefore(Position p) { pQN->prev = p.pQN; }		// 바로 이전에 올 노드 재설정

		// operator overloading 
		bool operator==(const Position q) { return pQN == q.pQN; }		// pQN의 주소값과, q.pQN의 주소값이 일치하는가
		bool operator!=(const Position q) { return pQN != q.pQN; }		// pQN의 주소값과, q.pQN의 주소값이 일치하지 않는가
		E& operator*() { return pQN->elem(); }					// 포인터에 있는 값을 반환
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

	// start 초기값 설정
	this->start.Setafter(end);
	this->start.Setbefore(Position(NULL));
	this->start.Setabove(Position(NULL));
	this->start.Setbelow(Position(NULL));
	// end 초기값 설정
	this->end.Setafter(start);
	this->end.Setbefore(Position(NULL));
	this->end.Setabove(Position(NULL));
	this->end.Setbelow(Position(NULL));

	// srand((unsigned int)time(NULL));
}

/*				SkipList member function			
		1. SkipListSearch() : SkipList안에서 노드 Search 
		2. SkipListInsert() : SkipList에 Insert ( 위/ 아래, 양옆 등 )
		3. insertAfterAboce() : SkipList의 노드의 다음 위에 넣기
		4. SkipListNodeDelete() : SkipList의 노드하나를 제거
		5. SkipListRemove() : SkipList 삭제
		6. PrintSkipList() : SkipList 출력				*/

template<typename K, typename E>
inline typename SkipList<K, E>::Position SkipList<K, E>::SkipListSearch(const K& k)
{
	Position pos = this->start;

	while (pos.below() != Position(NULL))
	{
		pos = pos.below();			// 처음 시작 : start.below(). 이유는 start는 단순한 처음 시작 연결용 더미이기 때문

		while (k >= ((pos.after()).key()))
		{
			pos = pos.after();
			if (pos.after() == Position(NULL))
				break;
		} // key값을 Search함( before과 after가 key값이 다르기 때문)
	}

	// 결론 : 찾는 Key의 가장 낮은(below())곳에 있는 Element가 반환 / 혹은 start값 반환
	return pos;
}
template<typename K, typename E>
inline typename SkipList<K, E>::Position SkipList<K, E>::SkipListInsert(ostream& ostr, const K k, const E e)
{
	Position p, q, t;

	p = this->SkipListSearch(k);				// 키값에 해당하는 부분을 찾는다 (Entry가 쌓이는 구조이기 때문에 가장 낮은 곳을 반환)
	q = Position(NULL);							// q 생성

	int i = -1;
	do
	{
		i = i + 1;
		if (i >= this->height)					// 만약 들어있는 노드가 아무것도 없다면
		{	
			this->height = this->height + 1;	
			t = start.after();
			this->start = this->insertAfterAbove(ostr, Position(NULL), this->start, MINUS_INF, E());	// 첫시작에 노드를 추가하여 이어줌
			this->insertAfterAbove(ostr, start, t, PLUS_INF, E());				// end 노드도 만들어서 붙여줌
		}
		q = insertAfterAbove(ostr, p, q, k, e);		// 값을 집어넣음

		while (p.above() == Position(NULL))			// 만약 노드가 이어지지 않았다면
		{
			p = p.before();							// 한칸 뒤로 뺀다 
		}
		p = p.above();								// 그 후, 자신의 바로 위 level에 담긴 값을 반환 받는다.
	} while (rand() % 2 == 0);						// 50퍼센트 확률로 탈출
	++num_elements;
	
	return q;
}
template<typename K, typename E>
inline  typename SkipList<K, E>::Position SkipList<K, E>::insertAfterAbove(ostream& ostr, Position p, Position q, const K k, const E e)
{
	QuadNode* pNewNode = new QuadNode(k, e);					// 새로운 노드 하나 생성
	
	// 노드의 Position 초기값 생성
	Position n(pNewNode);
	n.Setabove(Position(NULL));	n.Setbelow(Position(NULL));
	n.Setafter(Position(NULL));	n.Setbefore(Position(NULL));
	
	if (p == Position(NULL))
	{
		// 만약 리스트에 노드가 하나도 없는 경우라면
		// 1. 넣을 값도 NULL일 경우
		// 2. 넣을 값이 있을 경우
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

	// 리스트에 값이 들어있다면
	else
	{
		// 만약 노드 위치가 0이라면 
		if (q == Position(NULL))
		{
			// 노드를 쌓고, 이전 노드 p와 원래 다음노드와 연결해준다 ( p와 nx사이로 집어넣기 때문 )
			Position nx;
			ostr << "insert a node (" << n.key() << "at level 0 )" << endl;

			nx = p.after();
			p.Setafter(n);	n.Setbefore(p);
			n.Setafter(nx);	nx.Setbefore(n);
			n.Setbelow(Position(NULL));	n.Setabove(Position(NULL));
		}
		else
		{
			// 아니라면 p 다음 노드 엔트리에 값을 끼워넣는다. ( 4개의 방향을 이어줌 ) 
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
	Position pprev, pnext;			// 삭제될 노드의 양 옆

	if (p != Position(NULL))
	{
		pprev = p.before();				// 삭제될 노드의 이전 노드
		pnext = p.after();				// 삭제될 노드의 이후 노드
		// 서로 이어준 후
		if (pprev != Position(NULL))
			pprev.Setafter(pnext);
		if (pnext != Position(NULL))
			pnext.Setbefore(pprev);

		delete p.pQN;				// 삭제 
	}
}
template<typename K, typename E>
inline void SkipList<K, E>::SkipListRemove(ostream& ostr, K k)
{
	Position p, pprev, pnext, p00, px0, p0y, pxy, old_p;
	int h_max = 0, h = 0;

	p = this->SkipListSearch(k);					// 삭제할 키의 위치를 찾음
	if ((p.key() != k) || (p.key() == MINUS_INF))		// 만약 키를 못찾거나 start에 머물러 있을 경우
	{
		ostr << "Key (" << k << ") is not found in SkipList !!" << endl;
		return;
	}
	
	// 만약 p가 NULL이 될때까지 Key의 노드들를 삭제함
	while (p != Position(NULL))
	{
		old_p = p;
		p = p.above();
		this->SkipListNodeDelete(old_p);
	}
	ostr << "Deleted skip list node (Key : " << k << ")" << endl;
	
	// 노드 갱신
	p00 = this->start;
	for (int i = this->height; i > 0; i--)
		p00 = p00.below();
	px0 = p00.after();		// 맨 처음 start노드의 바로 다음 노드
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
	// 만약 h_max가 원래 높이보다 더 낮다면
	if (h_max < this->height) 
	{
		ostr << "Current height is less than the new h_max (" << h_max
			<< ") ==> need adjustment !!" << endl;
	}

	// 높이 차만큼 노드 삭제 
	for (int i = 0; i < (this->height - h_max); i++)
	{
		p0y = this->start;
		pxy = this->start.after();
		this->start = this->start.below();
		this->SkipListNodeDelete(pxy);
		this->SkipListNodeDelete(p0y);
	}
	this->height = h_max;			// 갱신
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
		ostr << "level" << setw(2) << level << " ";			// 레벨 출력
		if (pxy.key() == MINUS_INF)							// 만약 시작 부분이라면
			ostr << "-oo";
		else
			ostr << setw(5) << pxy.key();					// 키를 출력
		
		px0 = p00.after();									// 다음 노드
		for (pxy = p0y.after();; pxy = pxy.after())			// 노드 출력
		{
			while ((px0.key() != pxy.key()))
			{
				ostr << "-----";							// 만약 키를 못찾으면 밑줄을 출력
				px0 = px0.after();
			}
			if (pxy.key() == PLUS_INF)		// 탈출점
				break;	
			else
			{
				ostr << "-" << setw(4) << pxy.key();		// 찾으면 키를 출력
			}
			px0 = px0.after();
		}

		if (pxy.key() == PLUS_INF)							// 끝 부분 출력
			ostr << "+oo";
		else
			ostr << setw(5) << pxy.key();

		ostr << endl;
		p0y = p0y.below();
		pxy = p0y;
	}	// 반복
	ostr << endl;
}



#endif // !SKIPLIST_H
