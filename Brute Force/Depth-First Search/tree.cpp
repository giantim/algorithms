#include "algorithm-visualizer.h"
#include <iostream>

//visualizer {
GraphTracer		tracer("GraphTracer");
LogTracer		logger("LogTracer");

int G[11][11] = { 
	{0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

void InitDepthFirstSearch_tree()
{
	tracer.log(logger);
	Layout::setRoot(VerticalLayout({ tracer,logger }));
	tracer.set(G);
	tracer.layoutTree(0);
	Tracer::delay();
}
//}

void DFS(int node, int parent = NULL)
{
	//visualizer{
	tracer.visit(node, parent);
	Tracer::delay();
	//}
	for (int i = 0; i < 11; i++) {
		if (G[node][i])
			DFS(i, node);
	}
}

int main()
{
	InitDepthFirstSearch_tree();
	DFS(0);
}