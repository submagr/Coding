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

class stack{
	public:
		node* top;
		int length;
		stack(){
			node* top=NULL;
			int length=0;
		}

		node* push(node* newNode){
			if(top==NULL){
				top=newNode;
				top->next = NULL;
			}
			else{
				newNode->next=top;
				top=newNode;
			}
			length++;
			return top;
		}

		node* pop(){
			if(top==NULL)
				return top;
			node* popped = top;
			top=popped->next;
			popped->next=NULL;
			length--;
			return popped;
		}

		void print(){
			node* temp = top;
			while(temp!=NULL){
				printf("%d ", temp->val);
				temp=temp->next;
			}
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

		void print(node* head){
			node * currNode = head;
			while(currNode != NULL){
				printf("%d ", currNode->val);
				currNode=currNode->next;
			}
			printf("\n");
		}
};

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	list ls;
	for(int i=0; i<n; i++){
		int val;
		scanf("%d", &val);
		ls.head = ls.insert(val,ls.head);
	}
	ls.print(ls.head);

	node* oldPos=ls.head;
	node* newPos=NULL;
	node* newHead;
	stack* st = new stack();
	int count=0;
	while(oldPos!=NULL){
		node* prevPos = oldPos;
		oldPos=oldPos->next;
		st->push(prevPos);
		if(st->length==k || oldPos==NULL){
			while(st->length!=0){
				if(newPos==NULL){
					newPos=st->pop();
					newHead=newPos;
				}
				else{
					newPos->next=st->pop();
					newPos=newPos->next;
				}
			}
		}
	}
	ls.print(newHead);
	return 0;
}
