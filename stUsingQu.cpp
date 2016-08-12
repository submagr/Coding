// Implement stack using queue. 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class stackCustom{
	public:
		queue<int> q1;
		queue<int> q2;
		int empty(){
			if(q1.size() == 0)
				return 1;
			else
				return 0;
		}
		void push(int a){
			q2.push(a);
			while(!q1.empty()){
				q2.push(q1.front());
				q1.pop();
			}
			while(!q2.empty()){
				q1.push(q2.front());
				q2.pop();
			}
			return;
		}
		void pop(){
			q1.pop();	
		}
		int front(){
			return q1.front();
		}
};

class stackCustom2{
	public:
		queue<int> q1;
		int empty(){
			if(q1.size() == 0)
				return 1;
			else
				return 0;
		}
		void push(int b){
			int a= q1.size();
			q1.push(b);
			while(a--){
				q1.push(q1.front());
				q1.pop();
			}
			return;
		}
		void pop(){
			q1.pop();	
		}
		int front(){
			return q1.front();
		}
};

int main(){
	stackCustom2 * st = new stackCustom2();
	st->push(1);
	st->push(2);
	st->push(2);
	st->push(3);
	while(!st->empty()){
		printf("%d",st->front());
		st->pop();
	}
	printf("\n");
	return 0;
}
