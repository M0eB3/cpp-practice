#include <iostream>

using namespace std;
using std::cout;
using std::endl;


class Node
{
	friend class LinkedList;

public:
	Node( void ) : m_pNext( NULL )
	{}

	Node( int nValue ) : m_nValue( nValue ), m_pNext( NULL )
	{}

	Node( int nValue, Node* pNext ) : m_nValue( nValue ), m_pNext( pNext )
	{}

	int GetValue( void )
	{
		return m_nValue;
	}

	Node* GetNext( void )
	{
		return m_pNext;
	}

private:
	int   m_nValue;
	Node* m_pNext;
};


class LinkedList
{
public:
	LinkedList( void )
	{
		m_pHead = NULL;
		m_pTail = NULL;
	}

	LinkedList( int nValue )
	{
		m_pHead = new Node( nValue );
		m_pTail = m_pHead;
	}

	~LinkedList( void )
	{}

	void TravereAndPrint( )
	{
		if ( m_pHead == NULL )
		{
			cout << "Empty List" << endl;
			return;
		}

		Node* pCurrNode;

		while ( pCurrNode != NULL )
		{
			cout << pCurrNode->m_nValue << endl;
			pCurrNode = pCurrNode->m_pNext;
		}

		cout << endl;
	}

private:
	Node* m_pHead;
	Node* m_pTail;
};


int main( )
{
	LinkedList testList;

	cout << "Creating Empty Linked List" << endl;
	cout << "List Values : " << endl;

	return 0;
}
