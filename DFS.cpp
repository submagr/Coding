#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V; // Vertices
	list<int> *adj; // Adjacency List
public:
	Graph(int V);
	void addEdge(int v, int w); // Bidirectional Edges
	void DFS(int s, bool *visited);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::DFS(int s, bool *visited){
	printf("%d\n", s);
	visited[s] = true;
	list<int>::iterator i;
	for(i = adj[s].begin(); i != adj[s].end(); i++){
		if(!visited[*i]){
			DFS(*i, visited);
		}
	}
}

int main(){
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(4, 5);
	g.addEdge(3, 5);
	bool visited[5];
	g.DFS(0, visited);
	return 0;
}
