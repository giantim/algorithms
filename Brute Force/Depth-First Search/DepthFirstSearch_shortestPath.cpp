#include "algorithm-visualizer.h"
#include <iostream>
#include <string>
#include <limits>

GraphTracer tracer("GraphTracer");
LogTracer logger("LogTracer");
Randomize::Graph<int> graph(5, 1);
int G[5][5];

void InitDepthFirstSearch_shortestPath()
{
	Layout::setRoot(VerticalLayout({ tracer,logger }));
	tracer.log(logger);
	tracer.weighted();
	tracer.directed(false);
	graph.directed(false);
	graph.weighted();
	int g[25];
	graph.fill(g);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			G[i][j] = g[i * 4 + j];
	}
	tracer.set(G);
	Tracer::delay();
}

int minWeight;
std::vector<bool> D(5);
int e;

void DFS(int node, int parent, int weight)
{
	if (minWeight < weight)return;
	if (node == e) {
		tracer.visit(node, parent, weight);
		Tracer::delay();
		if (minWeight > weight)
			minWeight = weight;
		tracer.leave(node, parent, minWeight);
		Tracer::delay();
		return;
	}
	D[node] = true;
	tracer.visit(node, parent, weight);
	Tracer::delay();
	for (int i = 0; i < 5; i++) {
		if (G[node][i]) {
			if (!D[i])
				DFS(i, node, weight + G[node][i]);
		}

	}
	D[node] = false;
	tracer.leave(node, parent, 0);
	Tracer::delay();
}

int main()
{
	InitDepthFirstSearch_shortestPath();
	Randomize::Integer integer(0, 4);
	int s = integer.create();
	do {
		e = integer.create();
	} while (s == e);
	int MAX_VALUE = 2147483647;
	minWeight = MAX_VALUE;
	logger.println("finding the shortest path from " + std::to_string(s) + " to " +
		std::to_string(e));
	for (int i = 0; i < 5; i++)D.push_back(false);
	DFS(s, NULL, 0);
	if (minWeight == MAX_VALUE) {
		logger.println("there is no path from " + std::to_string(s) + " to " +
			std::to_string(e));
	}
	else
	{
		logger.println("the shortest path from " + std::to_string(s) + " to " +
			std::to_string(e) + " is " + std::to_string(minWeight));
	}
}