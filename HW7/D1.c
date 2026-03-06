


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

typedef int datatype;

//Необходимо реализовать функцию, которая печатает вид дерева сверху. Функция должна строго соответствовать прототипу:
typedef struct tree {
datatype key;
struct tree *left, *right;
} tree;


void printLeftBoundary(tree *root)
{
	if(root == NULL) return;
	if(root->left) printLeftBoundary(root->left);
	else if(root->right)printLeftBoundary(root->right);

	printf("%d ",root->key);

}

void printRightBoundary(tree *root)
{
	if(root == NULL) return;
	printf("%d ",root->key);
	if(root->right) printRightBoundary(root->right);
//	else if(root->left) printRightBoundary(root->left);
}
void btUpView(tree *root)
{
	if (root == NULL) return;
	if (root->left) {
        printLeftBoundary(root->left);
    }
    printf("%d ", root->key); 
    if (root->right)
	{
		printRightBoundary(root->right);
	}
}

int main(int argc, char **argv)
{
	
	return 0;
}

