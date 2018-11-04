#pragma once
#ifndef _REDBLACKTREE_H
#define _REDBLACKTREE_H

#include <iostream>
using namespace std;

#define RED 1
#define BLACK 0

template <class TYPE>
class RedBlackTree {
public:
	/*
	*	Default Constructor
	*/
	RedBlackTree()
	{
		m_pNodeHead = new Node;

		m_pNodeHead->pLeft = 0;
		m_pNodeHead->pRight = 0;
		m_nCount = 0;
	}

	/*
	*	Destructor
	*/
	~RedBlackTree()
	{

	}

	/*
	*	@brief	Tree내의 데이터 수 반환
	*	@pre	m_nCount 값 초기화
	*	@post	None
	*	@return	m_nCount
	*/
	int GetCount() const;

	/*
	*	@brief	Tree가 비어있는지 bool값 반환
	*	@pre	m_nCount값 초기화
	*	@post	None
	*	@return	비어있다면 true, 비어있지않다면 false 반환
	*/
	bool IsEmpty() const;

	/*
	*	@brief	Tree를 비운다.
	*	@pre	None.
	*	@post	Tree내의 모든 데이터 삭제
	*/
	void MakeTreeEmpty();

	/*
	*	@brief	Tree내에 key의 data의 이름을 keyword로 검색
	*	@pre	Tree가 초기화 되어있어야 한다
	*	@post	key에 검색한 데이터 복사
	*	@return	검색에 성공하였다면 true, 실패하였다면 false 반환
	*/
	bool Find(TYPE& key);

	/*
	*	@brief	검색에 사용할 함수
	*	@pre	Tree가 초기화 되어있어야 한다.
	*	@post	검색한 데이터의 주솟값을 가지는 tree 생성
	*	@param	검색할 키워드
	*	@param	검색한 데이터의 결과를 저장할 Tree
	*	@param	현재 검색하고 있는 단계가 어디인지 알려주는 int값
	*/
	int RetrieveWithKeyword(string searchKeyword, RedBlackTree<ResultType<TYPE>>, int &location);

	/*
	*	@brief	Tree에 데이터를 추가한다.
	*	@pre	Tree가 초기화 되어있어야 한다.
	*	@post	새로운 데이터 추가
	*	@param	추가할 데이터
	*	@return	추가에 성공하였다면 true, 실패하였다면 false 반환
	*/
	bool Insert(TYPE& value);

	/*
	*	@brief	Tree에 데이터를 삭제한다
	*	@pre	Tree가 초기화 되어있어야 한다
	*	@post	데이터 삭제
	*	@param	검색에 이용할 키워드를 포함한 데이터
	*	@return	삭제에 성공하였다면 true, 실패하였다면 false 반환
	*/
	bool Remove(TYPE& key);

	/*
	*	@brief	Tree에 데이터를 갱신한다
	*	@pre	Tree가 초기화 되어있어야 한다
	*	@post	데이터 갱신
	*	@param	검색에 이용할 키워드를 포함한 데이터
	*	@return	추가에 성공하였다면 true, 실패하였다면 false 반환
	*/
	bool Replace(TYPE& key);

	/*
	*	@brief	Tree내의 모든 데이터 출력한다
	*	@pre	None
	*	@post	데이터 화면에 출력
	*/
	void DisplayAllRecord();

	/*
	*	@brief	Tree내의 데이터의 이름들을 출력한다
	*	@pre	None
	*	@post	데이터들의 이름 화면에 출력
	*/
	void DisplayAllName();

	/*
	*	@brief	검색결과를 출력하기 위한 함수로, ResultType으로 이루어진 Tree내의 데이터의 이름들을 출력한다
	*	@pre	None
	*	@post	검색한 데이터들의 이름 화면에 출력
	*/
	void DisplayAllResult(ResultDisplayMode mode);

	/*
	*	@brief	이어지는 함수를 실행할지에 대해 사용자에게 한 번더 물어보는 함수
	*	@pre	value가 tree에 포함된 함수여야한다.
	*	@post	함수의 실행
	*	@param	이어지는 함수에 사용될 parameter
	*	@return	사용자가 확인한다면 true, 취소한다면 false 반환
	*/
	bool StartFunction(TYPE value);

	/*
	*	@brief	한 단계 아래의 Tree에 접근하기 위한 함수로, 데이터의 주솟값을 가르키는 포인터를 반환한다.
	*	@pre	Tree가 초기화 되어있어야한다.
	*	@post	None
	*	@param	주솟값이 필요한 데이터의 이름을 가지는 데이터
	*	@return	데이터의 주솟값을 가르키는 포인터
	*/
	TYPE* GetCurDataPointer(TYPE value);


protected:
	struct Node // 트리를 이루는 Node
	{
		TYPE data;
		Node *pLeft;
		Node *pRight;
		bool color;

		Node()
		{
			pLeft = 0;
			pRight = 0;
			color = BLACK;
		}
	};

	/*
	*	@brief	왼쪽으로 회전하거나 오른쪽으로 회전시켜 Red Black Tree의 특성을 가지게 한다.
	*	@pre	Tree가 초기화 되어있어야 한다
	*	@post	
	*	@param	
	*	@return	
	*/
	Node *_Rotate(TYPE& key, Node *pivot);

	/*
	*	@brief	Parameter로 입력된 Node가 Leaf Node인지 판별하는 함수
	*	@pre	Tree가 초기화 되어있어야 한다
	*	@post	None
	*	@return	LeafNode이면 true값을, NULL Node이거나 Leaf Node가 아닐 경우 false 반환
	*/
	bool _IsLeafNode(const Node *p) const;

	/*
	*	@brief	Parameter로 입력된 Node가 두개의 Black Node를 가지는지 판별하는 함수
	*	@pre	Tree가 초기화 되어있어야 한다
	*	@post	None
	*	@return 2Node일 경우 ture, 아닐 경우 false 반환
	*/
	bool _Is2Node(const Node *p) const;

	/*
	*	@brief	leaf 3-4노드를 삭제할 때의 다섯가지 경우의 수 처리
	*	@pre	Tree가 초기화 되어있어야 한다
	*	@post	key값과 일치하는 데이터가 있다면 삭제
	*	@param	삭제를 원하는 keyword가 포함된 TYPE
	*	@param	del의 parent pointer
	*	@param	leaf 근처의 Node pointer
	*/
	bool _DelLeafNode(TYPE& key, Node *delp, Node *del);

	/*
	*	@brief	Red Node가 연속되어 있을 경우 Tree의 구조를 바꿔주는 함수
	*	@pre	Tree가 초기화 되어있어야 한다
	*	@post	회전이 완료되어 Red Node가 연속하는 상황이 바뀐다
	*	@param	삭제할 데이터의 Grand Parent Pointer
	*	@param	삭제할 데이터의 Parent Pointer
	*	@param	삭제할 데이터의 sibling Pointer
	*	@return	Red Node가 연속되어 있을 경우 true, 아닐 경우 false를 반환
	*/
	bool _RedAsParent(Node *delgp, Node *delp, Node *sib);

	/*
	*	@brief	노드를 대체키와 바꾸어 내부노드의 삭제에 이용하는 함수
	*	@pre	Tree가 초기화 되어있어야 한다
	*	@post	Del 노드가 삭제된 상태의 Tree
	*	@param	Del Node의 grand parent node pointer
	*	@param	Del Node의 parent node pointer
	*	@param	Del Node의 sibling node pointer
	*	@return
	*/
	TYPE _SwapKey(Node *del);

	/*
	*	@brief	회전을 통해 color demotion을 통해 노드를 형제로 부터 빌려와야 하는 4가지 경우를 해결할 때 사용하는 함수
	*	@pre	Tree가 초기화 되어있어야 한다
	*	@post	회전이 완료되어 데이터 삭제가 가능하게 된다
	*	@param	회전이 축이 될, del Node의 Grand parent Node pointer
	*	@param	del Node의 parent Node Pointer
	*	@param	del Node
	*	@param	del Node의 Sibling Node Pointer
	*	@return	회전이 일어난 경우 true, 일어나지 않은 경우 false를 반환
	*/
	bool _BorrowKey(Node *delgp, Node *delp, Node *del, Node *sib);

	/*
	*	@brief	Sibling Node가 Black Node, Sibling의 두 자식도 Black Node일 경우 color Demotion으로 노드 병합
	*	@pre	Tree가 초기화 되어있어야 한다
	*	@post	Color Demotion으로 노드 병합
	*	@param	비교할 Node들의 Parant Node를 가르키는 포인터
	*/
	void _BindNode(Node *delp);

	/*
	*	@brief	파라미터로 입력된 Node부터 아래의 Sub Tree를 삭제하는 함수
	*	@pre	Tree가 초기화 되어있어야 한다
	*	@post	시작점 아래의 데이터들 삭제
	*	@param	삭제의 시작점이 되는 Node의 포인터
	*/
	void RemoveSubtree(Node *pNode);

	/*
	*	@brief	파라미터로 입력된 Node Pointer부터 화면에 출력
	*	@pre	None
	*	@post	화면에 데이터 출력
	*	@param	데이터를 출력할 시작점을 가르키는 포인터
	*/
	void _DisplayAllFrom(Node *ptr);

	/*
	*	@brief	Tree의 데이터들의 이름들을 모두 출력하는 함수
	*	@pre	Tree가 초기화 되어있어야 한다
	*	@post	화면에 데이터들의 이름들 출력
	*	@param	데이터를 출력할 시작점을 가르키는 포인터
	*/
	void _DisplayAllName(Node *ptr);

	/*
	*	@brief	검색결과를 출력하기 위한 함수로써, 검색한 결과들의 리스트에 있는 데이터들의 이름들을 모두 출력한다
	*	@pre	Tree가 초기화 되어있어야 한다
	*	@post	화면에 검색결과들 출력
	*	@param	검색결과를 출력할 시작점을 가르키는 포인터
	*/
	void _DisplayAllResult(Node *ptr, ResultDisplayMode mode);

	/*
	*	@brief	Tree의 데이터들 중, 사용자가 원하는 데이터를 검색하여 결과트리에 저장하는 함수
	*	@pre	Tree가 초기화 되어있어야 한다
	*	@post	검색결과들이 ResultType으로 이루어진 Tree에 저장된다
	*	@param	검색할 키워드
	*	@param	검색 결과를 저장할 Tree
	*	@param	검색을 시작할 데이터의 포인터
	*	@param	검색하고 있는 단계가 어디인지 알려주는 int값
	*	@return	검색이 성공하였다면 1, 실패하였다면 0을 반환
	*/
	int _RetrieveWithKeyword(string searchKeyword, RedBlackTree<ResultType<TYPE>> &resultTree, Node* ptr, int &location);

	Node *m_pNodeHead; // Head Node
	int m_nCount; // length of list
};


template<class TYPE>
int RedBlackTree<TYPE>::GetCount() const
{
	return m_nCount;
}

template<class TYPE>
bool RedBlackTree<TYPE>::IsEmpty() const
{
	if (m_nCount == 0)
		return true;
	else
		return false;
}

template<class TYPE>
void RedBlackTree<TYPE>::MakeTreeEmpty()
{
	if (m_pNodeHead->pLeft)
		RemoveSubtree(m_pNodeHead->pLeft);
	m_pNodeHead->pLeft = 0;
}

template<class TYPE>
bool RedBlackTree<TYPE>::Find(TYPE & key)
{
	string findString = key.GetName();
	string dataString;

	Node *s;
	s = m_pNodeHead->pLeft;
	dataString = s->data.GetName();
	while (s && !(dataString.find(findString) != string::npos))
	{
		if (key.CompareByName(s->data) == GREATER)
			s = s->pRight;
		else
			s = s->pLeft;
		dataString = s->data.GetName();
	}

	if(s == 0)
		return false;
	else
	{
		key = s->data;
		return true;
	}
}

template<class TYPE>
int RedBlackTree<TYPE>::RetrieveWithKeyword(string searchKeyword, RedBlackTree<ResultType<TYPE>> resultTree, int &location)
{
	_RetrieveWithKeyword(searchKeyword, resultTree, m_pNodeHead->pLeft, location);
	return 1;
}

template<class TYPE>
bool RedBlackTree<TYPE>::Insert(TYPE & value)
{
	Node *t; // 현재 노드
	Node *p; // t의 parent
	Node *gp; // p의 parent
	Node *ggp; // gp의 parent

	ggp = gp = p = (Node*)m_pNodeHead;
	t = (Node*)m_pNodeHead->pLeft;

	while (t)
	{
		if (value.CompareByName(t->data) == EQUAL) // 중복 발생
			return false;
		if (t->pLeft && t->pRight && t->pLeft->color && t->pRight->color) // t의 left, right가 존재하고, 둘의 color가 RED일때
		{
			// color promotion 발생
			t->color = RED;
			t->pLeft->color = t->pRight->color = BLACK;
			if (p->color) // 부모의 색깔이 RED로 RED node 연속 발생
			{
				// Rotate 필요
				gp->color = RED;
				if ((value.CompareByName(gp->data) == GREATER) != (value.CompareByName(p->data) == GREATER))
					p = _Rotate(value, gp); // double-rotation
				t = _Rotate(value, ggp);
				t->color = BLACK;
			}
			m_pNodeHead->pLeft->color = BLACK; // 뿌리는 BLACK이어야 한다
		}

		// 포인터들 아래로 이동
		ggp = gp;
		gp = p;
		p = t;

		if (value.CompareByName(t->data) == GREATER)
			t = t->pRight;
		else
			t = t->pLeft;
	} // t가 끝에 도달, 새로운 노드가 추가될 준비 완료

	t = new Node; // 새로 추가되는 데이터의 노드
	t->data = value;
	t->pLeft = t->pRight = 0;
	t->color = RED; // 데이터 세팅

	// 데이터 삽입
	if (value.CompareByName(p->data) == GREATER && p != m_pNodeHead)
		p->pRight = t;
	else
		p->pLeft = t;
	m_nCount++;

	// 부모가 빨강이라면 회전 필요
	if (p->color)
	{
		gp->color = RED;
		if ((value.CompareByName(gp->data) == GREATER) != (value.CompareByName(p->data) == GREATER))
			p = _Rotate(value, gp); // double-rotation
		t = _Rotate(value, ggp);
		t->color = BLACK;
	}

	m_pNodeHead->pLeft->color = BLACK; // 뿌리는 BLACK이어야 한다.
	return true;

}

template<class TYPE>
bool RedBlackTree<TYPE>::Remove(TYPE & key)
{
	Node *delgp; // delp의 parent
	Node *delp; // del의 parent
	Node *del; // 
	Node *sib; // 
	TYPE value = key;

	delgp = delp = m_pNodeHead;
	del = m_pNodeHead->pLeft;
	sib = 0;

	while (!_IsLeafNode(del))
	{
		if (!del->color)
		{
			// del이 BLACK이면 Rotation
			if (_RedAsParent(delgp, delp, sib))
			{
				// delgp와 sib의 위치 change, 새로 수정
				delgp = sib;
				if (del->data.CompareByName(delp->data) == GREATER || del->data.CompareByName(delp->data) == EQUAL)
					sib = delp->pLeft;
				else
					sib = delp->pRight;
			}
			if (del != m_pNodeHead->pLeft && _Is2Node(del))
			{
				if (!_BorrowKey(delgp, delp, del, sib))
					_BindNode(delp);
			}
		}
		if (value.CompareByName(del->data) == EQUAL)
			value = _SwapKey(del);
		delgp = delp;
		delp = del;
		if (value.CompareByName(del->data) == GREATER || value.CompareByName(del->data) == EQUAL)
		{
			sib = del->pLeft;
			del = del->pRight;
		}
		else
		{
			sib = del->pRight;
			del = del->pLeft;
		}
	}

	if (!del->color)
	{
		if (_RedAsParent(delgp, delp, sib))
		{
			delgp = sib;
			if (del->data.CompareByName(delp->data) == GREATER || del->data.CompareByName(delp->data) == EQUAL)
				sib = delp->pLeft;
			else
				sib = delp->pRight;
		}
	}
	if (del != m_pNodeHead->pLeft && _Is2Node(del))
	{
		if (!_BorrowKey(delgp, delp, del, sib))
			_BindNode(delp);
	}
	if (_DelLeafNode(value, delp, del))
	{
		m_nCount--;
		return true;
	}
	else
		return false;
}

template<class TYPE>
bool RedBlackTree<TYPE>::Replace(TYPE & key)
{
	TYPE* replaceData = GetCurDataPointer(key);
	if (replaceData != NULL)
	{
		replaceData->SetRecordFromKB();
		return true;
	}
	else
		return false;
}

template<class TYPE>
void RedBlackTree<TYPE>::DisplayAllRecord()
{
	_DisplayAllFrom(m_pNodeHead->pLeft);
}

template<class TYPE>
void RedBlackTree<TYPE>::DisplayAllName()
{
	_DisplayAllName(m_pNodeHead->pLeft);
}

template<class TYPE>
void RedBlackTree<TYPE>::DisplayAllResult(ResultDisplayMode mode)
{
	_DisplayAllResult(m_pNodeHead->pLeft, mode);
}

template<class TYPE>
bool RedBlackTree<TYPE>::StartFunction(TYPE value)
{
	char answer;
	cout << value.GetName() << "? (y/n) ";
	cin >> answer;
	cin.ignore();

	if ((answer == 'y') || (answer == 'Y'))
		return true;
	else
		return false;
}


template<class TYPE>
typename RedBlackTree<TYPE>::Node * RedBlackTree<TYPE>::_Rotate(TYPE & key, Node * pivot)
{
	Node *child;
	Node *gchild;
	if ((key.CompareByName(pivot->data) == GREATER || key.CompareByName(pivot->data) == EQUAL) && pivot != m_pNodeHead)
		child = (Node*)pivot->pRight;
	else
		child = (Node*)pivot->pLeft;

	if (key.CompareByName(child->data) == GREATER || key.CompareByName(child->data) == EQUAL)
	{
		gchild = (Node*)child->pRight;
		child->pRight = gchild->pLeft;
		gchild->pLeft = (Node*)child;
	}
	else
	{
		gchild = (Node*)child->pLeft;
		child->pLeft = gchild->pRight;
		gchild->pRight = (Node*)child;
	}

	if ((key.CompareByName(pivot->data) == GREATER || key.CompareByName(pivot->data) == EQUAL) && pivot != m_pNodeHead)
		pivot->pRight = gchild;
	else
		pivot->pLeft = gchild;

	return gchild;
}

template<class TYPE>
bool RedBlackTree<TYPE>::_IsLeafNode(const Node * p) const
{
	if (p == 0)
		return false;

	bool pLeftIsREDLeaf = p->pLeft && p->pLeft->color && !(p->pLeft->pLeft) && !(p->pLeft->pRight);
	bool pLeft = (p->pLeft == 0) || pLeftIsREDLeaf;
	bool pRightIsREDLeaf = p->pRight && p->pRight->color && !(p->pRight->pLeft) && !(p->pRight->pRight);
	bool pRight = (p->pRight == 0) || pRightIsREDLeaf;

	if (pLeft && pRight)
		return true;
	else
		return false;
}

template<class TYPE>
bool RedBlackTree<TYPE>::_Is2Node(const Node * p) const
{
	if (p == 0)
		return false;
	if (p->color == RED)
		return false;
	if ((p->pLeft == 0 && p->pRight == 0) || (p->pLeft && p->pRight && !p->pLeft->color && !p->pRight->color))
		return true;
	else
		return false;
}

template<class TYPE>
bool RedBlackTree<TYPE>::_DelLeafNode(TYPE & key, Node * delp, Node * del)
{
	if (key.CompareByName(del->data) == EQUAL && !del->pLeft && !del->pRight)
	{
		// del이 RED leaf나 BLACK leaf인 경우
		delete del;
		if ((key.CompareByName(delp->data) == GREATER) || (key.CompareByName(delp->data) == EQUAL) && delp != m_pNodeHead)
			delp->pRight = 0;
		else
			delp->pLeft = 0;
		return true;
	}
	else if (key.CompareByName(del->data) == EQUAL)
	{
		// del의 자식이 있는 경우.
		Node *ret = 0;
		if (del->pLeft) // 자식이 left에 있는 경우
		{
			del->pLeft->pRight = del->pRight;
			ret = del->pLeft;
			ret->color = BLACK;
			delete del;
		}
		else if (del->pRight) // 자식이 right에 있는 경우
		{
			del->pRight->pLeft = del->pLeft;
			ret = del->pRight;
			ret->color = BLACK;
			delete del;
		}

		if ((ret->data.CompareByName(delp->data) == GREATER) || (ret->data.CompareByName(delp->data) == EQUAL) && delp != m_pNodeHead)
			delp->pRight = ret;
		else
			delp->pLeft = ret;

		return true;
	}
	else if (del->pLeft && key.CompareByName(del->pLeft->data) == EQUAL)
	{
		// key와 일치하는 데이터가 del의 Left child인 경우
		delete del->pLeft;
		del->pLeft = 0;
		return true;
	}
	else if (del->pRight && key.CompareByName(del->pRight->data) == EQUAL)
	{
		// key와 일치하는 데이터가 del의 right child인 경우
		delete del->pRight;
		del->pRight = 0;
		return true;
	}
	else
		return false;
}

template<class TYPE>
bool RedBlackTree<TYPE>::_RedAsParent(Node * delgp, Node * delp, Node * sib)
{
	if (sib == 0 || !sib->color)
		return false;
	
	_Rotate(sib->data, delgp);
	sib->color = BLACK;
	delp->color = RED;
	return true;
}

template<class TYPE>
TYPE RedBlackTree<TYPE>::_SwapKey(Node * del)
{
	Node *cdd;
	cdd = del->pRight;
	while (cdd->pLeft)
		cdd = cdd->pLeft;
	del->data = cdd->data;
	return cdd->data;
}

template<class TYPE>
bool RedBlackTree<TYPE>::_BorrowKey(Node * delgp, Node * delp, Node * del, Node * sib)
{
	Node *sibrc;
	if (_Is2Node(sib))
		return false;
	if (del->data.CompareByName(sib->data) == GREATER)
	{
		if (sib->pLeft && sib->pLeft->color)
			sibrc = sib->pLeft;
		else
			sibrc = sib->pRight;
	}
	else
	{
		if (sib->pRight && sib->pRight->color)
			sibrc = sib->pRight;
		else
			sibrc = sib->pLeft;
	}

	if ((delp->data.CompareByName(sib->data) == GREATER) != (sib->data.CompareByName(sibrc->data) == GREATER))
	{
		// double-rotation
		_Rotate(sibrc->data, delp);
		_Rotate(sibrc->data, delgp);
		sib->color = BLACK;
		sibrc->color = RED;
	}
	else
	{
		// single-rotaion
		_Rotate(sib->data, delgp);
		sib->color = RED;
		sibrc->color = BLACK;
	}
	
	del->color = RED;
	delp->color = BLACK;

	if (m_pNodeHead->pLeft->color)
		m_pNodeHead->pLeft->color = BLACK;
	return true;
}

template<class TYPE>
void RedBlackTree<TYPE>::_BindNode(Node * delp)
{
	delp->color = BLACK;

	delp->pLeft->color = RED;
	delp->pRight->color = RED;
}

template<class TYPE>
void RedBlackTree<TYPE>::RemoveSubtree(Node * pNode)
{
	if (pNode != 0)
	{
		RemoveSubtree(pNode->pLeft);
		RemoveSubtree(pNode->pRight);
		delete pNode;
	}
}

template<class TYPE>
void RedBlackTree<TYPE>::_DisplayAllFrom(Node* ptr)
{
	if (ptr != NULL)
	{
		_DisplayAllFrom(ptr->pLeft);
		ptr->data.DisplayRecordOnScreen();
		cout << endl;
		_DisplayAllFrom(ptr->pRight);
	}
}

template<class TYPE>
void RedBlackTree<TYPE>::_DisplayAllName(Node* ptr)
{
	if (ptr != NULL)
	{
		_DisplayAllName(ptr->pLeft);
		cout << "\t   " << ptr->data.GetName() << endl;
		_DisplayAllName(ptr->pRight);
	}
}

template<class TYPE>
void RedBlackTree<TYPE>::_DisplayAllResult(Node * ptr, ResultDisplayMode mode)
{
	if (mode == PAPER)
	{
		if (ptr != NULL)
		{
			_DisplayAllResult(ptr->pLeft, PAPER);
			ptr->data.DisplayAllResult(PAPER);
			_DisplayAllResult(ptr->pRight, PAPER);
		}
	}
	else
	{
		if (ptr != NULL)
		{
			_DisplayAllResult(ptr->pLeft, AUTHOR);
			ptr->data.DisplayAllResult(AUTHOR);
			_DisplayAllResult(ptr->pRight, AUTHOR);
		}
	}
}

template<class TYPE>
int RedBlackTree<TYPE>::_RetrieveWithKeyword(string searchKeyword, RedBlackTree<ResultType<TYPE>>& resultTree, Node * ptr, int &location)
{
	ResultType<TYPE> addResult;
	TYPE *resultPointer;

	if (ptr != NULL)
	{
		string dataString = ptr->data.GetName();

		_RetrieveWithKeyword(searchKeyword, resultTree, ptr->pLeft, location);
		if (dataString.find(searchKeyword) != string::npos)
		{
			resultPointer = &(ptr->data);
			addResult.SetPointer(resultPointer);
			resultTree.Insert(addResult);
		}
		ptr->data.RetrieveByName(searchKeyword, location);
		_RetrieveWithKeyword(searchKeyword, resultTree, ptr->pRight, location);
	}
	return 1;
}

template<class TYPE>
TYPE * RedBlackTree<TYPE>::GetCurDataPointer(TYPE value)
{
	string findString = value.GetName();
	string dataString;
	TYPE* returnPointer;

	Node *s;
	s = m_pNodeHead->pLeft;
	dataString = s->data.GetName();
	while (s && !(dataString.find(findString) != string::npos))
	{
		if (value.CompareByName(s->data) == GREATER)
			s = s->pRight;
		else
			s = s->pLeft;
		dataString = s->data.GetName();
	}

	if (s == 0)
		return NULL;
	else
	{
		returnPointer = &(s->data);
		return returnPointer;
	}
}

#endif //_REDBLACKTREE_H