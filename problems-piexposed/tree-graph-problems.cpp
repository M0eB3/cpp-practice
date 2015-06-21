
#include <iostream>
using namespace std;

#include <queue>
#include <stack>
#include<math.h>

class Node
{
public:
	Node( ) : nValue( -1 ), pLeft( NULL ), pRight( NULL )
	{ }

	void SetValue( int value ) { nValue = value; };
	void SetLeft( Node* left ) { pLeft = left; };
	void SetRight( Node* right ) { pRight = right; };

	int Value() { return nValue; };
	Node* Left() { return pLeft; };
	Node* Right() { return pRight; };

private:
	int nValue;
	Node* pLeft;
	Node* pRight;
};


class Tree
{
public:
	Tree();
	~Tree();

	Node* Root() { return root; }
	void AddNode( int key );
	void InOrder( Node* node );
	void PreOrder( Node* node );
	void PostOrder( Node* node );
	void PreOrder_NoRecursion( Node* node );
	void Mirror( Node* node );
	void Mirror_InPlace( Node* node );

	int Height( Node* node );

private:
	Node* root;

	void AddNode( int nValue, Node* leaf );
	void FreeNode( Node* leaf );
};

Tree::Tree() : root( NULL ) {}

Tree::~Tree()
{
	FreeNode( root );
}

void Tree::FreeNode( Node* leaf )
{
	if ( leaf != NULL )
	{
		FreeNode( leaf->Left( ) );
		FreeNode( leaf->Right( ) );
		delete leaf;
	}
}

void Tree::AddNode( int value )
{
	if ( root == NULL )
	{
		Node* newNode = new Node();
		newNode->SetValue( value );
		root = newNode;
	}
	else
	{
		AddNode( value, root );
	}
}

void Tree::AddNode( int value, Node* leaf )
{
	if ( value <= leaf->Value() )
	{
		if ( leaf->Left() != NULL )
		{
			AddNode( value, leaf->Left() );
		}
		else
		{
			Node* newNode = new Node();
			newNode->SetValue( value );
			leaf->SetLeft( newNode );
		}
	}
	else
	{
		if ( leaf->Right( ) != NULL )
		{
			AddNode( value, leaf->Right( ) );
		}
		else
		{
			Node* newNode = new Node( );
			newNode->SetValue( value );
			leaf->SetRight( newNode );
		}
	}
}


void Tree::InOrder( Node* node )
{
	if ( node != NULL )
	{
		Tree::InOrder( node->Left() );
		cout << node->Value() << " ";
		Tree::InOrder( node->Right() );
	}
}

void Tree::PreOrder( Node* node )
{
	if ( node != NULL )
	{
		cout << node->Value( ) << " ";
		Tree::InOrder( node->Left( ) );
		Tree::InOrder( node->Right( ) );
	}
}

void Tree::PreOrder_NoRecursion( Node* node )
{
	if ( node == NULL )
		return;

	std::stack<Node*> nStack;
	nStack.push( node );

	while ( nStack.size() > 0 )
	{
		Node* currNode = nStack.top();
		cout << currNode->Value() << " ";
		nStack.pop();

		if ( currNode->Right() )
			nStack.push( currNode->Right() );
		if ( currNode->Left() )
			nStack.push( currNode->Left() );
	}
}


void Tree::PostOrder( Node* node )
{
	if ( node != NULL )
	{
		Tree::InOrder( node->Left( ) );
		Tree::InOrder( node->Right( ) );
		cout << node->Value( ) << " ";		
	}
}

int Tree::Height( Node* node )
{
	int height = 0;

	if ( node != NULL )
	{
		height += Height( node->Left() );
		height += Height( node->Right() );
		height++;
	}

	return height;
}


void Tree::Mirror( Node* node )
{


}


void Tree::Mirror_InPlace( Node* node )
{
	if ( node != NULL ) 
	{
		Node* tmp = node->Left();
		node->SetLeft( node->Right() );
		node->SetRight( tmp );

		Mirror_InPlace( node->Left( ) );
		Mirror_InPlace( node->Right( ) );
	}
}


void Lowest_Common_Ancestor()
{


}

void Binary_Tree_To_Heap()
{

}

void Unbalanced_Binary_Search_Tree()
{

}

float Round( float value, int precision )
{
    
    // 123.456  -> 123.46
    // 129.9 -> 130.0
    

    // 123456  -> 6
    // 12346
    // 123.46


    int nVal = value * pow( 10, precision + 1 );  //123456
    int nLastDigit = nVal % 10;

    while ( nVal )

    if ( nLastDigit >= 5 )
    {
        nVal -= nLastDigit + 10;
    }

    float nRounded = nVal / pow( 10, precision + 1 );

    return nRounded;
}

std::string 




int main( void )
{
	Tree* tree = new Tree();
	tree->AddNode( 30 );
	tree->AddNode( 10 );
	tree->AddNode( 20 );
	tree->AddNode( 40 );
	tree->AddNode( 50 );

	cout << "In order traversal" << endl;
	tree->InOrder( tree->Root( ) );
	cout << endl << endl;

	cout << "Pre order traversal" << endl;
	tree->PreOrder( tree->Root( ) );
	cout << endl << endl;

	cout << "Pre order traversal - no recursion" << endl;
	tree->PreOrder_NoRecursion( tree->Root( ) );
	cout << endl << endl;

	cout << "Post order traversal" << endl;
	tree->PostOrder( tree->Root( ) );
	cout << endl << endl;
	
	cout << "Tree Height : " << tree->Height( tree->Root() ) << endl;
	cout << endl << endl;

    cout << Round( 123.456, 2 ) << endl;


	delete tree;

	return 0;
}