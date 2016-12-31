#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int v, int w);
	void getNeighbours(int a);
	void BFS(int s);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	this->adj[v].push_back(w);
}

void Graph::BFS(int s){
	bool *visited = new bool[V];
	int *distance = new int[V];
	for(int i=0; i<V; i++){
		visited[i] = false;
	}
	queue<int> q;
	visited[s] = true;
	distance[s] = 0;
	q.push(s);
	cout << s << endl;
	while(!q.empty()){
		int w = q.front();
		q.pop();
		// Push all unvisited neighbours in queue
		for(list<int>::iterator it = adj[w].begin(); it != adj[w].end(); it++){
			if(!visited[*it]){
				visited[*it] = true;
				distance[*it] = distance[w] + 1;
				q.push(*it);
				cout << *it << " ";
			}
		}
		printf("\n");
	}
}

int main(){
	int t;
	printf("Enter Number of testcases: ");
	scanf("%d", &t);
	while(t--){
		int V;
		printf("Enter Number of vertices in graph: ");
		scanf("%d", &V);
		Graph g(V);
		int E;
		printf("Enter Number of edges in graph: ");
		scanf("%d", &E);
		printf("Enter %d directed edges one by one:\n", E);
		for(int i=0; i<E; i++){
			int v, w;
			scanf("%d %d", &v, &w);
			g.addEdge(v, w);
		}
		printf("Enter start vertex for BFS: ");
		int s;
		scanf("%d", &s);
		g.BFS(s);
	}
	return 0;
}
