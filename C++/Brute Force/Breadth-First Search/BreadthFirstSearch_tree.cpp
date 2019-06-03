#include "algorithm-visualizer.h"
#include <iostream>
#include <queue>

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

GraphTracer tracer("GraphTracer");
LogTracer   logger("LogTracer");


void InitBreadthFirstSearch_tree()
{
	tracer.log(logger);
	Layout::setRoot(VerticalLayout({ tracer,logger }));
	tracer.set(G);
	tracer.layoutTree(0);
	Tracer::delay();
}

void BFS(int s)
{
	std::queue<int> Q;
	Q.push(s);
	tracer.visit(s);
	Tracer::delay();
	while (Q.size() > 0) {
		int node = Q.front(); 
		Q.pop();
		for (int i = 0; i < 11; i++) {
			if (G[node][i]) {
				Q.push(i);
				tracer.visit(i, node);
				Tracer::delay();
			}
		}
	}
}

int main()
{
	InitBreadthFirstSearch_tree();
	BFS(0);
}