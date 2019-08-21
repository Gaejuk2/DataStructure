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
	*	@brief	Tree���� ������ �� ��ȯ
	*	@pre	m_nCount �� �ʱ�ȭ
	*	@post	None
	*	@return	m_nCount
	*/
	int GetCount() const;

	/*
	*	@brief	Tree�� ����ִ��� bool�� ��ȯ
	*	@pre	m_nCount�� �ʱ�ȭ
	*	@post	None
	*	@return	����ִٸ� true, ��������ʴٸ� false ��ȯ
	*/
	bool IsEmpty() const;

	/*
	*	@brief	Tree�� ����.
	*	@pre	None.
	*	@post	Tree���� ��� ������ ����
	*/
	void MakeTreeEmpty();

	/*
	*	@brief	Tree���� key�� data�� �̸��� keyword�� �˻�
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־�� �Ѵ�
	*	@post	key�� �˻��� ������ ����
	*	@return	�˻��� �����Ͽ��ٸ� true, �����Ͽ��ٸ� false ��ȯ
	*/
	bool Find(TYPE& key);

	/*
	*	@brief	�˻��� ����� �Լ�
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־�� �Ѵ�.
	*	@post	�˻��� �������� �ּڰ��� ������ tree ����
	*	@param	�˻��� Ű����
	*	@param	�˻��� �������� ����� ������ Tree
	*	@param	���� �˻��ϰ� �ִ� �ܰ谡 ������� �˷��ִ� int��
	*/
	int RetrieveWithKeyword(string searchKeyword, RedBlackTree<ResultType<TYPE>>, int &location);

	/*
	*	@brief	Tree�� �����͸� �߰��Ѵ�.
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־�� �Ѵ�.
	*	@post	���ο� ������ �߰�
	*	@param	�߰��� ������
	*	@return	�߰��� �����Ͽ��ٸ� true, �����Ͽ��ٸ� false ��ȯ
	*/
	bool Insert(TYPE& value);

	/*
	*	@brief	Tree�� �����͸� �����Ѵ�
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־�� �Ѵ�
	*	@post	������ ����
	*	@param	�˻��� �̿��� Ű���带 ������ ������
	*	@return	������ �����Ͽ��ٸ� true, �����Ͽ��ٸ� false ��ȯ
	*/
	bool Remove(TYPE& key);

	/*
	*	@brief	Tree�� �����͸� �����Ѵ�
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־�� �Ѵ�
	*	@post	������ ����
	*	@param	�˻��� �̿��� Ű���带 ������ ������
	*	@return	�߰��� �����Ͽ��ٸ� true, �����Ͽ��ٸ� false ��ȯ
	*/
	bool Replace(TYPE& key);

	/*
	*	@brief	Tree���� ��� ������ ����Ѵ�
	*	@pre	None
	*	@post	������ ȭ�鿡 ���
	*/
	void DisplayAllRecord();

	/*
	*	@brief	Tree���� �������� �̸����� ����Ѵ�
	*	@pre	None
	*	@post	�����͵��� �̸� ȭ�鿡 ���
	*/
	void DisplayAllName();

	/*
	*	@brief	�˻������ ����ϱ� ���� �Լ���, ResultType���� �̷���� Tree���� �������� �̸����� ����Ѵ�
	*	@pre	None
	*	@post	�˻��� �����͵��� �̸� ȭ�鿡 ���
	*/
	void DisplayAllResult(ResultDisplayMode mode);

	/*
	*	@brief	�̾����� �Լ��� ���������� ���� ����ڿ��� �� ���� ����� �Լ�
	*	@pre	value�� tree�� ���Ե� �Լ������Ѵ�.
	*	@post	�Լ��� ����
	*	@param	�̾����� �Լ��� ���� parameter
	*	@return	����ڰ� Ȯ���Ѵٸ� true, ����Ѵٸ� false ��ȯ
	*/
	bool StartFunction(TYPE value);

	/*
	*	@brief	�� �ܰ� �Ʒ��� Tree�� �����ϱ� ���� �Լ���, �������� �ּڰ��� ����Ű�� �����͸� ��ȯ�Ѵ�.
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	None
	*	@param	�ּڰ��� �ʿ��� �������� �̸��� ������ ������
	*	@return	�������� �ּڰ��� ����Ű�� ������
	*/
	TYPE* GetCurDataPointer(TYPE value);


protected:
	struct Node // Ʈ���� �̷�� Node
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
	*	@brief	�������� ȸ���ϰų� ���������� ȸ������ Red Black Tree�� Ư���� ������ �Ѵ�.
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־�� �Ѵ�
	*	@post	
	*	@param	
	*	@return	
	*/
	Node *_Rotate(TYPE& key, Node *pivot);

	/*
	*	@brief	Parameter�� �Էµ� Node�� Leaf Node���� �Ǻ��ϴ� �Լ�
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־�� �Ѵ�
	*	@post	None
	*	@return	LeafNode�̸� true����, NULL Node�̰ų� Leaf Node�� �ƴ� ��� false ��ȯ
	*/
	bool _IsLeafNode(const Node *p) const;

	/*
	*	@brief	Parameter�� �Էµ� Node�� �ΰ��� Black Node�� �������� �Ǻ��ϴ� �Լ�
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־�� �Ѵ�
	*	@post	None
	*	@return 2Node�� ��� ture, �ƴ� ��� false ��ȯ
	*/
	bool _Is2Node(const Node *p) const;

	/*
	*	@brief	leaf 3-4��带 ������ ���� �ټ����� ����� �� ó��
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־�� �Ѵ�
	*	@post	key���� ��ġ�ϴ� �����Ͱ� �ִٸ� ����
	*	@param	������ ���ϴ� keyword�� ���Ե� TYPE
	*	@param	del�� parent pointer
	*	@param	leaf ��ó�� Node pointer
	*/
	bool _DelLeafNode(TYPE& key, Node *delp, Node *del);

	/*
	*	@brief	Red Node�� ���ӵǾ� ���� ��� Tree�� ������ �ٲ��ִ� �Լ�
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־�� �Ѵ�
	*	@post	ȸ���� �Ϸ�Ǿ� Red Node�� �����ϴ� ��Ȳ�� �ٲ��
	*	@param	������ �������� Grand Parent Pointer
	*	@param	������ �������� Parent Pointer
	*	@param	������ �������� sibling Pointer
	*	@return	Red Node�� ���ӵǾ� ���� ��� true, �ƴ� ��� false�� ��ȯ
	*/
	bool _RedAsParent(Node *delgp, Node *delp, Node *sib);

	/*
	*	@brief	��带 ��üŰ�� �ٲپ� ���γ���� ������ �̿��ϴ� �Լ�
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־�� �Ѵ�
	*	@post	Del ��尡 ������ ������ Tree
	*	@param	Del Node�� grand parent node pointer
	*	@param	Del Node�� parent node pointer
	*	@param	Del Node�� sibling node pointer
	*	@return
	*/
	TYPE _SwapKey(Node *del);

	/*
	*	@brief	ȸ���� ���� color demotion�� ���� ��带 ������ ���� �����;� �ϴ� 4���� ��츦 �ذ��� �� ����ϴ� �Լ�
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־�� �Ѵ�
	*	@post	ȸ���� �Ϸ�Ǿ� ������ ������ �����ϰ� �ȴ�
	*	@param	ȸ���� ���� ��, del Node�� Grand parent Node pointer
	*	@param	del Node�� parent Node Pointer
	*	@param	del Node
	*	@param	del Node�� Sibling Node Pointer
	*	@return	ȸ���� �Ͼ ��� true, �Ͼ�� ���� ��� false�� ��ȯ
	*/
	bool _BorrowKey(Node *delgp, Node *delp, Node *del, Node *sib);

	/*
	*	@brief	Sibling Node�� Black Node, Sibling�� �� �ڽĵ� Black Node�� ��� color Demotion���� ��� ����
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־�� �Ѵ�
	*	@post	Color Demotion���� ��� ����
	*	@param	���� Node���� Parant Node�� ����Ű�� ������
	*/
	void _BindNode(Node *delp);

	/*
	*	@brief	�Ķ���ͷ� �Էµ� Node���� �Ʒ��� Sub Tree�� �����ϴ� �Լ�
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־�� �Ѵ�
	*	@post	������ �Ʒ��� �����͵� ����
	*	@param	������ �������� �Ǵ� Node�� ������
	*/
	void RemoveSubtree(Node *pNode);

	/*
	*	@brief	�Ķ���ͷ� �Էµ� Node Pointer���� ȭ�鿡 ���
	*	@pre	None
	*	@post	ȭ�鿡 ������ ���
	*	@param	�����͸� ����� �������� ����Ű�� ������
	*/
	void _DisplayAllFrom(Node *ptr);

	/*
	*	@brief	Tree�� �����͵��� �̸����� ��� ����ϴ� �Լ�
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־�� �Ѵ�
	*	@post	ȭ�鿡 �����͵��� �̸��� ���
	*	@param	�����͸� ����� �������� ����Ű�� ������
	*/
	void _DisplayAllName(Node *ptr);

	/*
	*	@brief	�˻������ ����ϱ� ���� �Լ��ν�, �˻��� ������� ����Ʈ�� �ִ� �����͵��� �̸����� ��� ����Ѵ�
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־�� �Ѵ�
	*	@post	ȭ�鿡 �˻������ ���
	*	@param	�˻������ ����� �������� ����Ű�� ������
	*/
	void _DisplayAllResult(Node *ptr, ResultDisplayMode mode);

	/*
	*	@brief	Tree�� �����͵� ��, ����ڰ� ���ϴ� �����͸� �˻��Ͽ� ���Ʈ���� �����ϴ� �Լ�
	*	@pre	Tree�� �ʱ�ȭ �Ǿ��־�� �Ѵ�
	*	@post	�˻�������� ResultType���� �̷���� Tree�� ����ȴ�
	*	@param	�˻��� Ű����
	*	@param	�˻� ����� ������ Tree
	*	@param	�˻��� ������ �������� ������
	*	@param	�˻��ϰ� �ִ� �ܰ谡 ������� �˷��ִ� int��
	*	@return	�˻��� �����Ͽ��ٸ� 1, �����Ͽ��ٸ� 0�� ��ȯ
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
		cout << s->data.GetName() << "\n";
		if (key.CompareByName(s->data) == GREATER){
			if(s->pRight){
				s = s->pRight;
			}
			else{
				s = 0;
				break;
			}
		}
		else{
			if(s->pLeft){
				s = s->pLeft;
			}
			else{
				s = 0;
				break;
			}
		}
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
	Node *t; // ���� ���
	Node *p; // t�� parent
	Node *gp; // p�� parent
	Node *ggp; // gp�� parent

	ggp = gp = p = (Node*)m_pNodeHead;
	t = (Node*)m_pNodeHead->pLeft;

	while (t)
	{
		if (value.CompareByName(t->data) == EQUAL) // �ߺ� �߻�
			return false;
		if (t->pLeft && t->pRight && t->pLeft->color && t->pRight->color) // t�� left, right�� �����ϰ�, ���� color�� RED�϶�
		{
			// color promotion �߻�
			t->color = RED;
			t->pLeft->color = t->pRight->color = BLACK;
			if (p->color) // �θ��� ������ RED�� RED node ���� �߻�
			{
				// Rotate �ʿ�
				gp->color = RED;
				if ((value.CompareByName(gp->data) == GREATER) != (value.CompareByName(p->data) == GREATER))
					p = _Rotate(value, gp); // double-rotation
				t = _Rotate(value, ggp);
				t->color = BLACK;
			}
			m_pNodeHead->pLeft->color = BLACK; // �Ѹ��� BLACK�̾�� �Ѵ�
		}

		// �����͵� �Ʒ��� �̵�
		ggp = gp;
		gp = p;
		p = t;

		if (value.CompareByName(t->data) == GREATER)
			t = t->pRight;
		else
			t = t->pLeft;
	} // t�� ���� ����, ���ο� ��尡 �߰��� �غ� �Ϸ�

	t = new Node; // ���� �߰��Ǵ� �������� ���
	t->data = value;
	t->pLeft = t->pRight = 0;
	t->color = RED; // ������ ����

	// ������ ����
	if (value.CompareByName(p->data) == GREATER && p != m_pNodeHead)
		p->pRight = t;
	else
		p->pLeft = t;
	m_nCount++;

	// �θ� �����̶�� ȸ�� �ʿ�
	if (p->color)
	{
		gp->color = RED;
		if ((value.CompareByName(gp->data) == GREATER) != (value.CompareByName(p->data) == GREATER))
			p = _Rotate(value, gp); // double-rotation
		t = _Rotate(value, ggp);
		t->color = BLACK;
	}

	m_pNodeHead->pLeft->color = BLACK; // �Ѹ��� BLACK�̾�� �Ѵ�.
	return true;

}

template<class TYPE>
bool RedBlackTree<TYPE>::Remove(TYPE & key)
{
	Node *delgp; // delp�� parent
	Node *delp; // del�� parent
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
			// del�� BLACK�̸� Rotation
			if (_RedAsParent(delgp, delp, sib))
			{
				// delgp�� sib�� ��ġ change, ���� ����
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
		// del�� RED leaf�� BLACK leaf�� ���
		delete del;
		if (((key.CompareByName(delp->data) == GREATER) || (key.CompareByName(delp->data) == EQUAL)) && delp != m_pNodeHead)
			delp->pRight = 0;
		else
			delp->pLeft = 0;
		return true;
	}
	else if (key.CompareByName(del->data) == EQUAL)
	{
		// del�� �ڽ��� �ִ� ���.
		Node *ret = 0;
		if (del->pLeft) // �ڽ��� left�� �ִ� ���
		{
			del->pLeft->pRight = del->pRight;
			ret = del->pLeft;
			ret->color = BLACK;
			delete del;
		}
		else if (del->pRight) // �ڽ��� right�� �ִ� ���
		{
			del->pRight->pLeft = del->pLeft;
			ret = del->pRight;
			ret->color = BLACK;
			delete del;
		}

		if (((ret->data.CompareByName(delp->data) == GREATER) || (ret->data.CompareByName(delp->data) == EQUAL)) && delp != m_pNodeHead)
			delp->pRight = ret;
		else
			delp->pLeft = ret;

		return true;
	}
	else if (del->pLeft && key.CompareByName(del->pLeft->data) == EQUAL)
	{
		// key�� ��ġ�ϴ� �����Ͱ� del�� Left child�� ���
		delete del->pLeft;
		del->pLeft = 0;
		return true;
	}
	else if (del->pRight && key.CompareByName(del->pRight->data) == EQUAL)
	{
		// key�� ��ġ�ϴ� �����Ͱ� del�� right child�� ���
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