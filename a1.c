#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

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

//Stack.
typedef struct stack {

	TREENODE *arr[SIZE];
	int top;

} STACK;

//Function to create an empty stack.
void emptyStack(STACK *s) {

	s->top = -1;
}

//Function to check if stack is empty.
int isEmpty(STACK *s) {

	if(s->top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

//Function to check if stack is full.
int isFull(STACK *s) {

	if(s->top == SIZE - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

//Push into stack.
void push(STACK *s, TREENODE *key) {

	if(isFull(s) == 1) {

		printf("Stack is full");
	}

	else {

		if(key!=NULL) {
			s->top = s->top + 1;
			s->arr[s->top] = key;
		}
	}
}

//Pop from stack.
TREENODE* pop(STACK *s) {

	if (isEmpty(s) == 1) {

		printf("Stack is empty");
		return NULL;
	}

	else {
		TREENODE *temp1 = s->arr[s->top];	
		s->top = s->top - 1;
		return temp1;
	}
}

//Function for zigzag traversal.
void ZigZag(TREENODE *p) {

	int depth = 0;
	if(p==NULL) {

		return;
	}

	//Allocate memory to the two stacks(currentLevel and nextLevel).
	STACK *currentLevel = (STACK *)malloc(sizeof(STACK));
	STACK *nextLevel = (STACK *)malloc(sizeof(STACK));

	//Creates two empty stacks currentLevel and nextLevel.
	emptyStack(currentLevel);
	emptyStack(nextLevel);

	//Push the node into the currentLevel stack.
	push(currentLevel, p);
	
	//If the currentLevel stack i
	while(isEmpty(currentLevel) == 0) {

		TREENODE *k = pop(currentLevel);
		printf("%d ", k->info);
		int i = 0;

		if(depth%2 != 0) {

			push(nextLevel, k->right);
			push(nextLevel, k->left);
		}
		else {

			push(nextLevel, k->left);
			push(nextLevel, k->right);
		}
		//Increment the depth of the tree and swap the currentLevel and nextLevel stacks.
		if(isEmpty(currentLevel) == 1) {

			depth = depth + 1;
			STACK *temp = currentLevel;
			currentLevel = nextLevel;
			nextLevel = temp;
		}
	}

}

int maxDepth(TREENODE *p)  
{ 
   if (p==NULL)  
       return 0; 
   else 
   { 
       /* compute the depth of each subtree */
       int lDepth = maxDepth(p->left); 
       int rDepth = maxDepth(p->right); 
  
       /* use the larger one */
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}
// Function to Print nodes from right to left 
void Print_Level_Right_To_Left(TREENODE *p, int level) 
{ 
    if (p == NULL) 
        return; 
  
    if (level == 1) 
        printf("%d ", p->info); 
  
    else if (level > 1) { 
        Print_Level_Right_To_Left(p->right, level - 1); 
        Print_Level_Right_To_Left(p->left, level - 1); 
    } 
} 
  
// Function to Print nodes from left to right 
void Print_Level_Left_To_Right(TREENODE *p, int level) 
{ 
    if (p == NULL) 
        return; 
  
    if (level == 1) 
        printf("%d ", p->info); 
  
    else if (level > 1) { 
        Print_Level_Left_To_Right(p->left, level - 1); 
        Print_Level_Left_To_Right(p->right, level - 1); 
    } 
} 

void PrintReverseZigZag(TREENODE *p) 
{ 
    // Flag is used to mark the change 
    // in level 
    int flag = 1; 
  
    // Height of tree 
    int height = maxDepth(p); 
  
    for (int i = height; i >= 1; i--) { 
  
        // If flag value is one print nodes 
        // from right to left 
        if (flag == 1) { 
            Print_Level_Right_To_Left(p, i); 
  
            // Mark flag as zero so that next time 
            // tree is traversed from left to right 
            flag = 0; 
        } 
  
        // If flag is zero print nodes 
        // from left to right 
        else if (flag == 0) { 
            Print_Level_Left_To_Right(p, i); 
  
            // Mark flag as one so that next time 
            // nodes are printed from right to left 
            flag = 1; 
        } 
    } 
} 
int main() {

	int size,j;
	scanf("%d", &size);
	int a[size];

	for(j=0; j<size; j++) {

		scanf("%d", &a[j]);
	}

	TREENODE *root = createTree(a,0, size-1);

	//Prints the reverse zigzag sequence inorder to check our code.
	printf("Reverse ZigZag sequence for this tree is: \n");
	
	PrintReverseZigZag(root); 

	return 0;

}
