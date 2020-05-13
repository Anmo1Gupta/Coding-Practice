// C++ program to demonstrate insertion 
// in a BST recursively. 
#include <bits/stdc++.h> 
using namespace std; 

class BST 
{ 
    public:
    
    
	int data,leftSize,rightSize; 
	BST *left, *right; 

	// Default constructor. 
	BST(); 
	
	// Parameterized constructor. 
	BST(int); 
	
	// Insert function. 
	BST* Insert(BST *, int); 
	
	// Inorder traversal. 
	void Inorder(BST *); 
	
	int size(BST *);
	int getSizeLeft(BST *);
	int getSizeRight(BST *);
	void updateSizeLeft(BST *);
	void updateSizeRight(BST *);
	void updateSizes(BST *, int value);
}; 

// Default Constructor definition. 
BST :: BST() : data(0), leftSize(0), rightSize(0), left(NULL), right(NULL){} 

// Parameterized Constructor definition. 
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
		// Insert the first node, if root is NULL. 
		return new BST(value); 
	} 

	// Insert data. 
	if(value > root->data) 
	{ 
		// Insert right node data, if the 'value' 
		// to be inserted is greater than 'root' node data. 
		
		// Process right nodes. 
		root->right = Insert(root->right, value); 
	} 
	else
	{ 
		// Insert left node data, if the 'value' 
		// to be inserted is greater than 'root' node data. 
		
		// Process left nodes. 
		root->left = Insert(root->left, value); 
	} 
	
	updateSizes(root,value);
	// Return 'root' node, after insertion. 
	return root; 
} 

// Inorder traversal function. 
// This gives data in sorted order. 
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
	root->leftSize = getSizeLeft(root);
} 

void BST :: updateSizeRight(BST* root) 
{ 
    if(!root) 
	{ 
		return; 
	} 
	root->rightSize = getSizeRight(root);
	updateSizeRight(root->left); 
// 	root->rightSize = getSizeRight(root);
	updateSizeRight(root->right); 
// 	root->rightSize = getSizeRight(root);
}

void BST :: updateSizes(BST* root, int value){
   if(value > root->data) 
	{ 
	    updateSizeRight(root->right);
	} 
	else
	{ 
		updateSizeLeft(root->left);
	} 
	if(root->data == value) 
	{ 
		//Do nothing
// 		continue;
	} 
}

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

