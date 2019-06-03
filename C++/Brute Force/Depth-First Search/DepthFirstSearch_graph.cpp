#include "algorithm-visualizer.h"
#include <iostream>
#include <string>
#include <vector>
#include <stack>

GraphTracer		graphTracer("GraphTracer");
Array1DTracer	visitedTracer("visited");
LogTracer		logger("LogTracer");
Randomize::Graph<int> graph(8, 0.3);
int G[8][8];

void InitDepthFirstSearch_graph()
{
	graphTracer.directed(false);
	Layout::setRoot(VerticalLayout({ graphTracer,visitedTracer,logger }));
	graphTracer.log(logger);
	graph.directed(false);
	int temp_G[64];
	graph.fill(temp_G);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			G[i][j] = temp_G[i * 8 + j];
		}
	}
	graphTracer.set(G);
	Tracer::delay();
}

std::vector<bool> DFSExplore(int graph[8][8], int source)
{
	std::stack<std::array<int, 2>> stack; stack.push({ source, NULL });
	std::vector<bool> visited;
	int node, prev, i;
	//int temp[2];
	for (int i = 0; i < 8; i++) {
		visited.push_back(false);
	}
	visitedTracer.set(visited);

	while (stack.size() > 0)
	{
		auto temp = stack.top(); stack.pop();
		node = temp[0];
		prev = temp[1];

		if (!visited[node]) {
			visited[node] = true;
			//부자연스럽다....
			std::vector<bool> t; t.push_back(visited[node]);
			visitedTracer.patch(node, t);

			if (prev != NULL && graph[node][prev]) {
				graphTracer.visit(node, prev);
				Tracer::delay();
			}
			else
			{
				graphTracer.visit(node);
				Tracer::delay();
			}

			for (int i = 0; i < 8; i++) {
				if (graph[node][i]) {
					stack.push({ i,node });
				}
			}
		}
	}
	return visited;
}

int main()
{
	InitDepthFirstSearch_graph();
	std::vector<bool> visited = DFSExplore(G, 0);
	bool check = true;
	for (int i = 0; i < visited.size(); i++) check &= visited[i];
	if (check) {
		logger.println("The Graph is CONECTED");
	}
	else
	{
		logger.println("The Graph is NOT CONNECTED");
	}
}