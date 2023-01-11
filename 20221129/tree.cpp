#include <iostream>
using namespace std;

typedef struct node *treePointer;

struct node{
    char data;
    treePointer leftChild, rightChild;
};

treePointer node1,node2,node3,node4,
            node5,node6,node7,node8,node9;
            
void CreateNode(){
	node1 = new node;
	node2 = new node;
	node3 = new node;
	node4 = new node;
	node5 = new node;
	node6 = new node;
	node7 = new node;
	node8 = new node;
	node9 = new node;
    
    node1->data = '+';
    node2->data = '*';
    node3->data = 'E';
    node4->data = '*';
    node5->data = 'D';
    node6->data = '/';
    node7->data = 'C';
    node8->data = 'A';
    node9->data = 'B';
    
    node1->leftChild = node2;
    node2->leftChild = node4;
    node4->leftChild = node6;
    node6->leftChild = node8;
    node3->leftChild = NULL;
    node5->leftChild = NULL;
    node7->leftChild = NULL;
    node8->leftChild = NULL;
    node9->leftChild = NULL;
    
    node1->rightChild = node3;
    node2->rightChild = node5;
    node4->rightChild = node7;
    node6->rightChild = node9;
    node3->rightChild = NULL;
    node5->rightChild = NULL;
    node7->rightChild = NULL;
    node8->rightChild = NULL;
    node9->rightChild = NULL;   
}

void preorder(treePointer ptr)
{
    cout << ptr->data ;
    
    if(ptr->leftChild != NULL)
        preorder(ptr->leftChild);
        
    if(ptr->rightChild != NULL)
        preorder(ptr->rightChild);
}

void inorder(treePointer ptr)
{

}

void postorder(treePointer ptr)
{

}

int main(void)
{
    CreateNode();
    
    cout << " preorder : " ;
    preorder(node1);
    cout << endl ;

    cout << " inorder : " ;
    inorder(node1);
    cout << endl ;

    cout << " postorder : " ;
    postorder(node1);
    cout << endl ;


}