#include "algorithm-visualizer.h"
#include <iostream>
#include <vector>

GraphTracer				tracer("GraphTracer");
Array1DTracer			tracerS("Array1DTracer");
LogTracer				logger("LogTracer");
Randomize::Graph<int>	graph(5, 1);
int G[5][5];
int _G[25];
int MAX_VALUE = 2147483647;
int S[5];

void InitDijkstraShortestPath()
{
	Layout::setRoot(VerticalLayout({ tracer,tracerS ,logger }));
	tracer.directed(false);
	tracer.weighted();
	tracer.log(logger);
	graph.directed(false);
	graph.weighted();
	graph.fill(_G);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			G[i][j] = _G[i * 5 + j];
		}
	}
	tracer.set(G);
	for (int i = 0; i < 5; i++)
		S[i] = MAX_VALUE;
	tracerS.set(S);
	Tracer::delay();
}

void Dijkstra(int start, int end) {
	int minIndex;
	int minDistance;
	std::vector<int> D;
	for (int i = 0; i < 5; i++) D.push_back(false);
	S[start] = 0; 
	tracerS.patch(start, S[start]);
	Tracer::delay();
	tracerS.depatch(start);
	tracerS.select(start);
	int k = 5;
	while (k--) {
		minDistance = MAX_VALUE;
		for (int i = 0; i < 5; i++) {
			if (S[i] < minDistance && !D[i]) {
				minDistance = S[i];
				minIndex = i;
			}
		}
		if (minDistance == MAX_VALUE) break; 
		D[minIndex] = true;
		tracerS.select(minIndex);
		tracer.visit(minIndex);
		Tracer::delay();
		for (int i = 0; i < 5; i++) {
			if (G[minIndex][i] && S[i] > S[minIndex] + G[minIndex][i]) {
				S[i] = S[minIndex] + G[minIndex][i];
				tracerS.patch(i, S[i]);
				tracer.visit(i, minIndex, S[i]);
				Tracer::delay();
				tracerS.depatch(i);
				tracer.leave(i, minIndex);
				Tracer::delay();
			}
		}
		tracer.leave(minIndex);
		Tracer::delay();
	}
	if (S[end] == MAX_VALUE) {
		logger.println("there is no path from " + std::to_string(start) + " to " 
			+std::to_string(end));
	}
	else {
		logger.println("the shortest path from " + std::to_string(start) + " to "+
			std::to_string(end) + " is " + std::to_string(S[end]));
	}
}

int main()
{
	InitDijkstraShortestPath();
	Randomize::Integer randInteger(0, 4);
	int s = randInteger.create();
	int e;
	do {
		e = randInteger.create();
	} while (s == e);
	logger.println("finding the shortest path from "+ std::to_string(s) + " to " 
		+std::to_string(e));
	Tracer::delay();
	Dijkstra(s, e);
}