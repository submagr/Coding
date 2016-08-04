#include<stdio.h>
#include<typeinfo>
#include<stdlib.h>
using namespace std;

class node {
	public:
		int val;
		class node * next;
		node(){
			val = 0;
			next = NULL;
		}
};

class list {
	public:
		node * head=NULL;
		node * insert(int val, node * head){
			node * newNode = new node();
			newNode->val=val;
			newNode->next=NULL;
			node * currNode = head;
			while(currNode != NULL && currNode->next != NULL){
				currNode=currNode->next;
			}
			if(currNode==NULL){
				head=newNode;
			}
			else{
				currNode->next=newNode;
			}
			return head;
		}
		void print(){
			node * currNode = head;
			//printf("%d", head->val);
			while(currNode != NULL){
				printf("%d", currNode->val);
				currNode=currNode->next;
			}
			printf("\n");
		}

		node* reverse(node * initialHead){
			if(initialHead == NULL){
				return NULL;
			}
			node * newHead = reverse(initialHead->next);
			initialHead->next = NULL;
			node * currPos = newHead;
			while(currPos!=NULL && currPos->next!=NULL){
				currPos = currPos->next;
			}
			if(currPos==NULL){
				newHead = initialHead;
			}else{
				currPos->next = initialHead;
			}
			return newHead;
		}
};

int main(){
	int n;
	scanf("%d", &n);
	list ls;
	for(int i=0; i<n; i++){
		int val;
		scanf("%d", &val);
		ls.head = ls.insert(val,ls.head);
	}
	ls.print();
	ls.head = ls.reverse(ls.head);
	ls.print();
	return 0;
}
