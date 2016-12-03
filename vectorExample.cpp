#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

void printVector( vector<int> *v){
	for(int i=0; i<(*v).size(); i++ ){
		printf("%d ", (*v)[i]);
		(*v)[i] +=1;
	}
	printf("\n");
	return;
}

typedef struct node{
	int val;
	int distance;
	bool visited;
}node;

int main(){
	vector<int> v;
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		v.push_back(i*i);
	}
	printf("%lu\n", v.size());
	printVector(&v);
	printVector(&v);
	v.clear();
	printf("%lu\n", v.size());

	vector< vector<node> > graph(n);
	printf("%lu\n", graph.size());
	printf("%lu\n", graph[0].size());
	printf("%lu %lu %lu %lu\n", sizeof(bool), sizeof(int), sizeof(node), sizeof(graph));
	return 0;
}
