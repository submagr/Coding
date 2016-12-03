#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

queue<int> q;

void printQ(){
	int len = q.size();
	while(len--){
		printf("%d ", q.front());
		q.push(q.front());
		q.pop();
	}
	printf("\n");
	return;
}
void binary(int len){
	if(len==0){
		printQ();
		return;
	}
	q.push(0);
	binary(len-1);
	q.pop();
	q.push(1);
	binary(len-1);
	q.pop();
	return;
}

int main(){
	int t,n;
	scanf("%d", &t);
	while(t--){
		scanf("%d",&n);
		binary(n);
	}
	return 0;
}
