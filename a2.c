#include <stdio.h>
#include <stdlib.h>

//Treenode.
typedef struct treenode {

	int info;
	struct treenode* left;
	struct treenode* right;

} TREENODE;

//Function to create a new node.
TREENODE *newNode(int key) {
 
	TREENODE *p = (TREENODE*)malloc(sizeof(TREENODE));
	p->info = key;
	p->left = NULL;
	p->right = NULL;
	return p;
}

//Function to build the tree.
TREENODE *createTree(int inorder[], int start, int end) {

	if(start > end) {
		return NULL;
	}

	int i = (start + end)/2;
	
	TREENODE *root = newNode(inorder[i]);

	if(start==end) {
		return root;
	} 

	root->left = createTree(inorder, start, i-1);
	root->right = createTree(inorder, i+1, end);

	return root;

}

// Function to print the inorder.
void InOrder(TREENODE *node) {
	if(node == NULL) {
		return;
	}
	InOrder(node->left);
	printf("%d ", node->info);
	InOrder(node->right);
}

// Function to print the postorder.
void PostOrder(TREENODE *node) {
	if(node == NULL) {
		return;
	}
	PostOrder(node->left);
	PostOrder(node->right);
	printf("%d ", node->info);
}

int main() {

	int size,j;
	scanf("%d", &size);
	int a[size];

	for(j=0; j<size; j++) {

		scanf("%d", &a[j]);
	}

	TREENODE *root = createTree(a,0, size-1);
	
	//Print the inorder sequence inorder to check our code.
	printf("Postorder sequence for this tree is: \n");

	PostOrder(root);

	return 0;

}
