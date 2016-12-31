#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

long gcd(long a, long b){
	if(a>b)	{
		long temp = b;
		b=a;
		a=temp;
	}
	long r;
	do{
		r = b%a;
		b = a;
		a = r;
	}while(r!=0);
	return b;
}

class node{
public:
	int count;
	int index;
	node(int c, int i){
		count = c;
		index = i;
	}
};

class myComp{
public:
	bool operator()(node a, node b){
		if(a.count < b.count)
			return true;
		return false;
	}
};

int main(){
	int t;
	scanf("%d", &t);
	typedef priority_queue <node, vector<node>, myComp> myP;
	while(t--){
		long n;
		long processedN = 0;
		myP qu;
		stack<node> myStack;
		scanf("%ld", &n);
		long s[n];
		long maxCount = 0;
		long counts[n];
		long count=0;
		for(long i=0; i<n; i++){
			long temp;
			scanf("%ld", &temp);
			if(temp!= 1){
				s[processedN] = temp;
				processedN += 1;
			}
		}
		for(long i=processedN-1; i>=0; i--){
			counts[i] = 1;

			// New Optimized Code
			while(qu.size()!=0){
				if(gcd(s[qu.top().index], s[i]) > 1){
					counts[i] = qu.top().count + 1;
					qu.push(node(counts[i], i));
					break;
				}else{
					myStack.push(qu.top());
					qu.pop();
				}
			}
			while(myStack.size() != 0 ){
				qu.push(myStack.top());
				myStack.pop();
			}

			// Old Unoptimized Code
			if(maxCount < counts[i])
				maxCount = counts[i];
			qu.push(node(counts[i], i ));
		}
		if(maxCount == 0)
			maxCount +=1;
		printf("%ld\n", maxCount);
	}
	return 0;
}
