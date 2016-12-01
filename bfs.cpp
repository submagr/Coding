#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

typedef struct node{
	int value;
	int distance;
	bool visited;
	struct node *next;
}node;

void bfs(vector < vector<node> > *graph, queue <int>*q, vector <int> *distance, vector<bool> *visited){
	while(!q->empty()){
		int s = q->back();
		q->pop();
		for(int i=0; i<(*graph)[s].size(); i++){
			int neighbor = (*graph)[s][i].value;
			if(!(*visited)[neighbor]){
				(*visited)[neighbor] = true;
				(*distance)[neighbor] = (*distance)[s] + 1;
				q->push(neighbor);
			}
		}
	}
	return;
}
int main(){
	int n, e;
	printf("Number of nodes = ");
	scanf("%d", &n);
	vector< vector<node> > graph(n); // Adjacency List
	printf("Number of edges = ");
	scanf("%d", &e);
	for(int i=0; i<e; i++){
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		node temp;	
		temp.value = n2;
		temp.distance = 0;
		temp.visited = false;
		graph[n1].push_back(temp);
		// Undirected Graph
		temp.value = n1;
		temp.distance = 0;
		temp.visited = false;
		graph[n2].push_back(temp);
	}
	// BFS
	int s;
	printf("Enter start node ")	;
	// Create a visited array
	vector <bool> visited(n, false);
	vector <int> distance(n, -1);
	scanf("%d", &s);
	visited[s] = true;
	distance[s] = 0;
	queue <int>q;
	q.push(s);
	bfs(&graph, &q, &distance, &visited);
	for(int i=0; i<distance.size(); i++){
		printf("%d ", distance[i]);
	}
	printf("\n");
	return 0; 
}
