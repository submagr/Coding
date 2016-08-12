//http://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	int a[n][m];
	int distance[n][m];
	queue<int> q;
	int i,j;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%d", &a[i][j]);
			distance[i][j]=0;
			if(a[i][j]==2){
				q.push(i);
				q.push(j);
			}
		}
	}
	int k;
	int maxk = 0;
	while(!q.empty()){
		i=q.front();		
		q.pop();
		j=q.front();
		q.pop();
		k = distance[i][j] + 1;

		//up
		if(i!=0 and a[i-1][j] ==1){
			q.push(i-1);
			q.push(j);
			a[i-1][j] = 2;
			distance[i-1][j] = k;
			maxk = k;
		}
		//down
		if(i!=n-1 and a[i+1][j] ==1){
			q.push(i+1);
			q.push(j);
			a[i+1][j] = 2;
			distance[i+1][j] = k;
			maxk = k;
		}
		//left
		if(j!=0 and a[i][j-1] ==1){
			q.push(i);
			q.push(j-1);
			a[i][j-1] = 2;
			distance[i][j-1] = k;
			maxk = k;
		}
		//right
		if(j!=m-1 and a[i][j+1] ==1){
			q.push(i);
			q.push(j+1);
			a[i][j+1] = 2;
			distance[i][j+1] = k;
			maxk = k;
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(a[i][j]==1){
				printf("can't be rotten\n");
				return 0;
			}
		}
	}
	printf("rotten in %d\n", maxk);
	return 0;
}
