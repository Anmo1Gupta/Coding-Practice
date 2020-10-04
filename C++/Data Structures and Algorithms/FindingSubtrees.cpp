// C++ program to check if binary tree is subtree of another binary tree - O(log(n))
#include<bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, 
left child and right child */
class node 
{ 
	public: 
	int data; 
	node* left; 
	node* right; 
}; 

/* A utility function to check 
whether trees with roots as root1 and 
root2 are identical or not */
bool areIdentical(node * root1, node *root2) 
{ 
	/* base cases */
	if (root1 == NULL && root2 == NULL) 
		return true; 

	if (root1 == NULL || root2 == NULL) 
		return false; 

	/* Check if the data of both roots is 
	same and data of left and right 
	subtrees are also same */
	return (root1->data == root2->data && 
			areIdentical(root1->left, root2->left) && 
			areIdentical(root1->right, root2->right) ); 
} 


/* This function returns true if S 
is a subtree of T, otherwise false */
bool isSubtree(node *T, node *S) 
{ 
	/* base cases */
	if (S == NULL) 
		return true; 

	if (T == NULL) 
		return false; 

	/* Check the tree with root as current node */
	if (areIdentical(T, S)) 
		return true; 

	/* If the tree with root as current 
	node doesn't match then try left 
	and right subtrees one by one */
	return isSubtree(T->left, S) || 
		isSubtree(T->right, S); 
} 


/* Helper function that allocates 
a new node with the given data 
and NULL left and right pointers. */
node* newNode(int data) 
{ 
	node* Node = new node(); 
	Node->data = data; 
	Node->left = NULL; 
	Node->right = NULL; 
	return(Node); 
} 

/* Driver code*/
int main() 
{ 
	// TREE 1 
	/* Construct the following tree 
			26 
			/ \ 
		10 3 
		/ \ \ 
	4 6 3 
	\ 
		30 
	*/
	node *T = newNode(26); 
	T->right		 = newNode(3); 
	T->right->right = newNode(3); 
	T->left		 = newNode(10); 
	T->left->left	 = newNode(4); 
	T->left->left->right = newNode(30); 
	T->left->right	 = newNode(6); 

	// TREE 2 
	/* Construct the following tree 
		10 
		/ \ 
	4 6 
	\ 
		30 
	*/
	node *S = newNode(10); 
	S->right	 = newNode(6); 
	S->left	 = newNode(4); 
	S->left->right = newNode(30); 


	if (isSubtree(T, S)) 
		cout << "Tree 2 is subtree of Tree 1"; 
	else
		cout << "Tree 2 is not a subtree of Tree 1"; 

	return 0; 
} 

// With O(n) Complexity
#include <cstring> 
#include <iostream> 
using namespace std; 
#define MAX 100 

// Structure of a tree node 
struct Node { 
	char key; 
	struct Node *left, *right; 
}; 

// A utility function to create a new BST node 
Node* newNode(char item) 
{ 
	Node* temp = new Node; 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to store inorder traversal of tree rooted 
// with root in an array arr[]. Note that i is passed as reference 
void storeInorder(Node* root, char arr[], int& i) 
{ 
	if (root == NULL) { 
		arr[i++] = '$'; 
		return; 
	} 
	storeInorder(root->left, arr, i); 
	arr[i++] = root->key; 
	storeInorder(root->right, arr, i); 
} 

// A utility function to store preorder traversal of tree rooted 
// with root in an array arr[]. Note that i is passed as reference 
void storePreOrder(Node* root, char arr[], int& i) 
{ 
	if (root == NULL) { 
		arr[i++] = '$'; 
		return; 
	} 
	arr[i++] = root->key; 
	storePreOrder(root->left, arr, i); 
	storePreOrder(root->right, arr, i); 
} 

/* This function returns true if S is a subtree of T, otherwise false */
bool isSubtree(Node* T, Node* S) 
{ 
	/* base cases */
	if (S == NULL) 
		return true; 
	if (T == NULL) 
		return false; 

	// Store Inorder traversals of T and S in inT[0..m-1] 
	// and inS[0..n-1] respectively 
	int m = 0, n = 0; 
	char inT[MAX], inS[MAX]; 
	storeInorder(T, inT, m); 
	storeInorder(S, inS, n); 
	inT[m] = '\0', inS[n] = '\0'; 

	// If inS[] is not a substring of preS[], return false 
	if (strstr(inT, inS) == NULL) 
		return false; 

	// Store Preorder traversals of T and S in inT[0..m-1] 
	// and inS[0..n-1] respectively 
	m = 0, n = 0; 
	char preT[MAX], preS[MAX]; 
	storePreOrder(T, preT, m); 
	storePreOrder(S, preS, n); 
	preT[m] = '\0', preS[n] = '\0'; 

	// If inS[] is not a substring of preS[], return false 
	// Else return true 
	return (strstr(preT, preS) != NULL); 
} 

// Driver program to test above function 
int main() 
{ 
	Node* T = newNode('a'); 
	T->left = newNode('b'); 
	T->right = newNode('d'); 
	T->left->left = newNode('c'); 
	T->right->right = newNode('e'); 

	Node* S = newNode('a'); 
	S->left = newNode('b'); 
	S->left->left = newNode('c'); 
	S->right = newNode('d'); 

	if (isSubtree(T, S)) 
		cout << "Yes: S is a subtree of T"; 
	else
		cout << "No: S is NOT a subtree of T"; 

	return 0; 
} 

