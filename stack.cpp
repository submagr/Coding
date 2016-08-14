#include<stdio.h>
using namespace std;

class node{
	public:
		int val;
		node* next;
		node(int a=0){
			val =a;
			next=NULL;
		}
		//TODO: Delete node function
};
class stack_cust{
	public:
		node* top;
		int length;
		stack_cust(){
			top = NULL;
			length = 0;
		}
		void push(int a){
			node* temp = new node(a);
			temp->next = top;
			top = temp;
			length++;
			return;
		}
		void pop(){
			node* temp = top;
			top = top->next;
			delete temp;
			length--;
			return;
		}
		int head(){
			if(top!=NULL)
				return top->val;
			else
				return -1;
		}
};

int main(){
	stack_cust* q = new stack_cust();
	q->push(1);
	q->push(2);
	printf("%d %d",q->length, q->head());
	q->pop();
	printf("%d %d",q->length, q->head());
	q->pop();
	printf("%d %d",q->length, q->head());
	return 0;
}
