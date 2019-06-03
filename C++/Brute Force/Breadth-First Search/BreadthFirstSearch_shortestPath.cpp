#include "algorithm-visualizer.h"
#include <iostream>
#include <vector>
#include <queue>

GraphTracer tracer("GraphTracer");
LogTracer logger("LogTracer");
Randomize::Graph<int> graph(5, 1);
int G[5][5];
int MAX_VALUE = 0x7fffffff;
Randomize::Integer integer(0, 4);
int s = integer.create();

void InitBreadthFirstSearch_shortestPath()
{
	tracer.directed(false);
	tracer.weighted();
	Layout::setRoot(VerticalLayout({ tracer,logger }));
	tracer.log(logger);
	graph.directed(false);
	graph.weighted();
	int* temp = new int[25];
	//tracer.set(G);에서 G는 2차원 배열이어야 하는데 fill함수는 일차원 배열만 받아서 써야 하므로 번거로웠다
	//->추후 수정해야할 부분
	graph.fill(temp);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			G[i][j] = temp[i * 5 + j];
		}
	}
	delete temp;
	tracer.set(G);
	Tracer::delay();
}

int BFS(int e)
{
	std::vector<int> W;
	std::queue<int> Q;
	int i;
	for (i = 0; i < 5; i++) {
		W.push_back(MAX_VALUE);
		tracer.updateNode(i, MAX_VALUE);
	}
	W[s] = 0;
	Q.push(s);
	std::vector<int> v(5);
	tracer.visit(s, NULL,0);
	Tracer::delay();
	while (Q.size() > 0)
	{
		int node = Q.front(); Q.pop();
		for (i = 0; i < sizeof(G[node]) / sizeof(int); i++)
		{
			if (G[node][i]) { // if the edge from current node to the i-th node exists
				if (W[i] > W[node] + G[node][i]) { // if current path is shorter than the previously shortest path
					W[i] = W[node] + G[node][i]; // update the length of the shortest path
					Q.push(i); // add child node to queue
					tracer.visit(i, node, W[i]);
					Tracer::delay();
				}
			}
		}
	}
	return W[e];
}

int main()
{
	InitBreadthFirstSearch_shortestPath();
	int e;
	do {
		e = integer.create();
	} while (e == s);
	logger.println("finding the shortest path from " + std::to_string(s) + " to " + std::to_string(e));
	int minWeight = BFS(s);
	if (minWeight == MAX_VALUE) {
		logger.println("there is no path from " + std::to_string(s) + " to " + std::to_string(e));
	}
	else {
		logger.println("the shortest path from " + std::to_string(s) + " to " + std::to_string(e) + " is "
			+ std::to_string(minWeight));
	}
}