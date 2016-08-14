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
class queue_cust{
	public:
		node* front;
		node* back;
		int length;
		queue_cust(){
			front = NULL;
			back = NULL;
			length = 0;
		}
		void push(int a){
			if(front!=NULL){
				back->next = new node(a);
				back = back->next;
			}else{
				front = new node(a);
				back = front;
			}
			length++;
			return ;
		}
		void pop(){
			if(front!=NULL){
				node* temp = front;		
				front = front->next;
				delete temp;
				length--;
			}
		}
		int head(){
			if(front!=NULL)
				return front->val;
			else
				return -1;
		}
};

int main(){
	queue_cust* q = new queue_cust();
	q->push(1);
	q->push(2);
	printf("%d %d\n",q->length, q->head());
	q->pop();
	printf("%d %d\n",q->length, q->head());
	q->pop();
	printf("%d %d\n",q->length, q->head());
	return 0;
}
