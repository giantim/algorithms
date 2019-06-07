#include "algorithm-visualizer.h"
#include <iostream>

//visualizer{
const int				GRAPHSIZE = 5;
GraphTracer				tracer("GraphTracer");
LogTracer				logger("LogTracer");
Randomize::Graph<int>	graph(GRAPHSIZE, 1);
int						G[GRAPHSIZE][GRAPHSIZE];

void InitDepthFirstSearch_shortestPath()
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

int minWeight;					
std::vector<bool> D(GRAPHSIZE);	
int s;							
int e;							

void DFS(int node, int parent, int weight)
{
	if (minWeight < weight)	return;	
	
	if (node == e) {
		//visualizer{
		tracer.visit(node, parent, weight);
		Tracer::delay();
		//}
		if (minWeight > weight)
			minWeight = weight;
		//visualizer{
		tracer.leave(node, parent, minWeight);
		Tracer::delay();
		//}
		return;
	}
	D[node] = true;
	//visualizer{
	tracer.visit(node, parent, weight);
	Tracer::delay();
	//}
	for (int i = 0; i < GRAPHSIZE; i++) {
		if (G[node][i]) {
			if (!D[i])
				DFS(i, node, weight + G[node][i]);
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
	InitDepthFirstSearch_shortestPath();
	Randomize::Integer integer(0, GRAPHSIZE-1);
	s = integer.create();		
	do {
		e = integer.create();
	} while (s == e);
	int MAX_VALUE = 2147483647;	
	minWeight = MAX_VALUE;		
	//visualizer{
	logger.println("finding the shortest path from " + std::to_string(s) + " to " +
		std::to_string(e));
	//}
	for (int i = 0; i < GRAPHSIZE; i++)D.push_back(false);	
	DFS(s, NULL, 0);	
	if (minWeight == MAX_VALUE) {
		//visualizer{
		logger.println("there is no path from " + std::to_string(s) + " to " +
			std::to_string(e));
		//}
	}
	else
	{
		//visualizer{
		logger.println("the shortest path from " + std::to_string(s) + " to " +
			std::to_string(e) + " is " + std::to_string(minWeight));
		//}
	}
}