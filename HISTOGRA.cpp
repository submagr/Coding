#include<bits/stdc++.h>
using namespace std;

class rect{
public:
	long long height;
	long long width;
	rect();
	rect(long long rectHeight, long long rectWidth){
		height = rectHeight;
		width = rectWidth;
	}
};

long long insertSt(stack<rect> *st, long long h, long long max){
	if((st->top()).height < h){
		rect tempRect(h, 1);
		st->push(tempRect);
	}else{
		long long count=0;
		do{
			rect tempRect = st->top();
			st->pop();
			long long tempArea = tempRect.height*(tempRect.width+count);
			if(max < tempArea)
				max=tempArea;
			count+=tempRect.width;
		}while(!st->empty() && st->top().height >= h);
		rect tempRect(h, count+1);
		st->push(tempRect);
	}
	return max;
}

long long getMaxAreaRectangle(long long n, long long* heights){
	stack<rect> st;
	rect zeroRect(0,0);
	st.push(zeroRect);
	long long max= 0;
	for(long long i=0; i<n; i++){
		max = insertSt(&st, heights[i], max);
	}
	return insertSt(&st, 0, max);
}

int main(){
	while(1){
		long long n;
		scanf("%lld", &n);
		if(n==0)
			break;
		long long heights[n];
		for(long long i=0; i<n; i++){
			scanf("%lld", &heights[i]);
		}
		printf("%lld\n", getMaxAreaRectangle(n, heights));
	}
	return 0;
}
