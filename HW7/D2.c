
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>



typedef int datatype;


typedef struct tree {
int key;
struct tree *left, *right;
struct tree *parent; //ссылка на родителя
} tree;


tree * findBrother(tree *root, int key)
{
 if(root==NULL) return 0;
 if( root->key == key)
 {
	 tree* parentTemp=root->parent;
	 if (root->parent==NULL) return 0;

	 if ((parentTemp->left!=NULL)&&(parentTemp->right==root))
	 {
		 return parentTemp->left;
	 }
	 else if ((parentTemp->right)!=NULL&&parentTemp->left==root)
	 {
		 return parentTemp->right;
	 }
	 else
	 {
		 return 0;
	 }
	
 }
 else if(root->key > key)return findBrother(root->left,key);
 
 else return findBrother(root->right, key);
}

int main(int argc, char **argv)
{
	
	return 0;
}

