#include <iostream>

using namespace std;

struct Edge
{
	int wt, src, dest;
};

struct Graph
{
	int V, E;
	struct Edge* edge;
};

struct Graph* createGraph(int V, int E){

	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
};

void BellmanFordAlgorithm(struct Graph* graph, int src){
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	for(int i=0; i<V; i++){
		dist[i] = INT_MAX;
	}
	dist[src]=0;

	for(int i=1; i<=V-1; i++){
		for(int j=0; j<E; j++){
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int wt = graph->edge[j].wt;

			if (dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
				dist[v] = dist[u] + wt;
			}
		}
	}

	for(int i=0; i<E; i++){
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int wt = graph->edge[i].wt;

		if (dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
			cout <<"[*] Graph contains a negative weight cycle" << endl;
		}
	}

	//print here
	return;
}

int main(){
	int V;
	int E;
	struct Graph* graph = createGraph(V, E);

	BellmanFordAlgorithm(graph, 0);
	return 0;
}