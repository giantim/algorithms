//weightedGraph

#include "algorithm-visualizer.h"
#include <iostream>

//visualizer{
const int				GRAPHSIZE = 5;
GraphTracer				tracer("GraphTracer");
LogTracer				logger("LogTracer");
Randomize::Graph<int>	graph(GRAPHSIZE, 1);
int						G[GRAPHSIZE][GRAPHSIZE];
bool					D[GRAPHSIZE];

void init_DepthFirstSearch_weightedGraph()
{
	Layout::setRoot(VerticalLayout({ tracer,logger }));
	tracer.log(logger);
	tracer.weighted();
	tracer.directed(false);
	graph.directed(false);
	graph.weighted();
	int g[GRAPHSIZE*GRAPHSIZE];
	graph.fill(g);
	for (int i = 0; i < GRAPHSIZE; i++) {
		for (int j = 0; j < GRAPHSIZE; j++)
			G[i][j] = g[i *GRAPHSIZE + j];
	}
	tracer.set(G);
	Tracer::delay();
}
//}

void DFS(int node, int parent, int weight)
{
	//visualizer{
	tracer.visit(node, parent, weight);
	Tracer::delay();
	//}
	D[node] = true; 
	for (int i = 0; i < GRAPHSIZE; i++) {
		if (G[node][i]) {
			if (!D[i]) {
				DFS(i, node, weight + G[node][i]);
			}
		}
	}
	D[node] = false; 
	//visualizer{
	tracer.leave(node, parent, 0);
	Tracer::delay();
	//}
}

int main()
{
	init_DepthFirstSearch_weightedGraph();
	for (int k = 0; k < GRAPHSIZE; k++) {
		//visualizer{
		logger.println("start from " + std::to_string(k));
		//}
		for (int i = 0; i < GRAPHSIZE; i++)
			D[i] = false;
		DFS(k, NULL, 0);

	}
}