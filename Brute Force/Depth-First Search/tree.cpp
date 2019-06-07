#include "algorithm-visualizer.h"
#include <iostream>
#include <string>

GraphTracer tracer("GraphTracer");
LogTracer logger("LogTracer");

int G[11][11] = { // G[i][j] indicates whether the path from the i-th node to the j-th node exists or not
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
void DFS(int node, int parent = NULL)
{
	tracer.visit(node, parent);
	Tracer::delay();
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