// C++ program to insert a node in AVL tree
#include<bits/stdc++.h>
using namespace std;

// An AVL tree node
class Node{
	public:
	int key;
	Node *left;
	Node *right;
	int height;
};
int max(int a,int b);
Node *newNode(int key){
	Node *node=new Node();
	node->key=key;
	node->left=NULL;
	node->right=NULL;
	node->height=1;
	return (node);
}

int height(Node *N){
	if(N==NULL){
		return 0;
	}
	return N->height;
}
int max(int a,int b){

	return (a>b)?a:b;
}

Node *leftRotate(Node *y){
	Node *x=y->right;
	Node *T2=x->left;

	x->left=y;
	y->right=T2;

	x->height=max(height(x->left),height(x->right))+1;
	y->height=max(height(y->left),height(y->right))+1;

	return x;
}
Node *rightRotate(Node *x){
	Node *y=x->left;
	Node *T2=y->right;

	y->right=x;
	x->left=T2;
	x->height=max(height(x->left),height(x->right))+1;
	y->height=max(height(y->left),height(y->right))+1;

	return y;
}

int getBalance(Node *N){
	if(N==NULL){
		return 0;
	}
	return height(N->left)-height(N->right);
}

Node *insert(Node *node,int key){
	if(node==NULL){
		return newNode(key);
	}
	if(key>node->key){
		node->right=insert(node->right,key);
	}
	else if(key<node->key){
		node->left=insert(node->left,key);
	}
	else{
		return node;
	}
	node->height=1+max(height(node->left),height
	(node->right));
	int balance= getBalance(node);

	if(balance>1 && key<node->left->key){
	 return rightRotate(node);
	}
	if(balance<-1 && key>node->right->key){
		return leftRotate(node);
	}
	if(balance>1 && key>node->left->key){
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}
	if(balance<-1 && key<node->right->key){
		node->right=rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}
// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void preOrder(Node *root)
{
	if(root != NULL)
	{
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

// Driver Code
int main()
{
	Node *root = NULL;
	
	/* Constructing tree given in
	the above figure */
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);
	
	/* The constructed AVL Tree would be
				30
			/ \
			20 40
			/ \ \
		10 25 50
	*/
	cout << "Preorder traversal of the "
			"constructed AVL tree is \n";
	preOrder(root);
	
	return 0;
}

// This code is contributed by
// rathbhupendra
