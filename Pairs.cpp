#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int a[n];
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	int r = 0, l = 0;
	int count = 0;
	while(r < n){
		int temp = a[r] - a[l];
		if(temp == k){
			count+=1;
			r+=1;
		}else if(temp < k){
			r+=1;
		}else{
			l+=1;
		}
	}
	printf("%d\n", count);
	return 0;
}
