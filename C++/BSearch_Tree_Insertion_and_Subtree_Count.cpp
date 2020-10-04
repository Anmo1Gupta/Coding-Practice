#include <bits/stdc++.h> 
using namespace std; 

class BST 
{ 
    public:
    
    int data,leftSize,rightSize; 
	BST *left, *right; 
	
	BST(); 
	
	BST(int); 
	
	BST* Insert(BST *, int); 
	
	void Inorder(BST *); 
	
	int size(BST *);
	int getSizeLeft(BST *);
	int getSizeRight(BST *);
	void updateSizeLeft(BST *);
	void updateSizeRight(BST *);
// 	void updateSizes(BST *, int value);
}; 

// Default Constructor
BST :: BST() : data(0), leftSize(0), rightSize(0), left(NULL), right(NULL){} 

// Parameterized Constructor 
BST :: BST(int value) 
{ 
	data = value; 
	leftSize = 0;
	rightSize = 0;
	left = right = NULL; 
} 

// Insert function definition. 
BST* BST :: Insert(BST *root, int value) 
{ 
	if(!root) 
	{ 
		
		return new BST(value); 
	} 

	if(value > root->data) 
	{ 
		root->right = Insert(root->right, value); 
		updateSizeRight(root->right); //Updating the sizes after every insertion.
	} 
	else
	{ 
		root->left = Insert(root->left, value); 
		updateSizeLeft(root->left); //Updating the sizes after every insertion.
	} 
	
	return root; 
} 


void BST :: Inorder(BST *root) 
{ 
	if(!root) 
	{ 
		return; 
	} 
	Inorder(root->left); 
	cout << root->data << endl; 
	Inorder(root->right); 
} 

int BST :: size(BST* node) 
{ 
    if (node == NULL) 
        return 0; 
    else
        return(size(node->left) + 1 + size(node->right)); 
} 

int BST :: getSizeLeft(BST* node) 
{ 
if (node==NULL) 
    return 0; 
else
    return(size(node->left)); 
} 

int BST :: getSizeRight(BST* node) 
{ 
if (node==NULL) 
    return 0; 
else
    return(size(node->right)); 
}

void BST :: updateSizeLeft(BST* root) 
{ 
    if(!root) 
	{ 
		return; 
	} 
	updateSizeLeft(root->left); 
	root->leftSize = getSizeLeft(root);
	updateSizeLeft(root->right); 
} 

void BST :: updateSizeRight(BST* root) 
{ 
    if(!root) 
	{ 
		return; 
	} 
	updateSizeRight(root->left); 
	root->rightSize = getSizeRight(root);
	updateSizeRight(root->right); 
}

// void BST :: updateSizes(BST* root, int value){
//   if(value > root->data) 
// 	{ 
// 	    updateSizeRight(root->right);
// 	} 
// 	else
// 	{ 
// 		updateSizeLeft(root->left);
// 	} 
// 	if(root->data == value) 
// 	{ 
        // root->leftSize = 0;
        // root->rightSize = 0;
// 	} 
// }

int main() 
{ 
	BST b, *root = NULL; 
	root = b.Insert(root, 50); 
	b.Insert(root, 30); 
	b.Insert(root, 20); 
	b.Insert(root, 40); 
	b.Insert(root, 70); 
	b.Insert(root, 60); 
	b.Insert(root, 80); 

	b.Inorder(root); 
	
	cout<<"\nSize of tree = " << b.size(root);
	cout<<"\nSize of left subtree = " << b.getSizeLeft(root);
	cout<<"\nSize of right subtree = " << b.getSizeRight(root);
	
	b.Insert(root, 90); 
	
	cout<<"\n\n";
	b.Inorder(root); 
	
	cout<<"\n\nSize of tree = " << b.size(root);
	cout<<"\nSize of left subtree = " << b.getSizeLeft(root->left);
	cout<<"\nSize of root->right left and right subtree = " << b.getSizeLeft(root->right)<<"  "<<b.getSizeRight(root->right);
	
	cout<<"\n\n";
	
	return 0; 
} 

