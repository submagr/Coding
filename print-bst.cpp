#include<stdio.h>
#include<typeinfo>
#include<stdlib.h>
using namespace std;

class treeNode {
	public:
		int val;
		int size;
		class treeNode* left;
		class treeNode* right;
		treeNode(){
			val = 0;
			left = NULL;
			right = NULL;
			size = 0;
		}
};

class tree{
	public:
		treeNode* root;
		tree(){
			root=NULL;
		}
		void balancedInsert(int val){
			treeNode* newNode = new treeNode();
			newNode->val=val;
			newNode->size++;
			treeNode* currNode = root;
			treeNode* prevNode = root;
			int sizeLeft;
			int sizeRight;
			while(currNode!=NULL){
				prevNode=currNode;
				if(currNode->left!=NULL)
					sizeLeft=currNode->left->size;
				else
					sizeLeft=0;
				sizeRight=currNode->size-sizeLeft-1;
				currNode->size++;
				if(sizeLeft<=sizeRight)
					currNode=currNode->left;
				else
					currNode=currNode->right;
			}
			if(prevNode==NULL)
				root=newNode;
			else{
				if(sizeLeft<=sizeRight)
					prevNode->left=newNode;
				else
					prevNode->right=newNode;
				
			}
		}
		void print(treeNode* root){
			if(root==NULL)
				return;
			print(root->left);
			printf("%d ",root->val);
			print(root->right);
			return;
		}
};

int main(){
	int n;
	scanf("%d",&n);
	tree* t = new tree();
	while(n--){
		int val;
		scanf("%d",&val);
		t->balancedInsert(val);
	}
	t->print(t->root);
	return 0;
}
