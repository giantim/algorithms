#include "algorithm-visualizer.h"
#include <iostream>
#include <vector>
#include <queue>

//visualizer{
const int				GRAPHSIZE = 7;
GraphTracer				tracer("GraphTracer");
LogTracer				logger("LogTracer");
Randomize::Graph<int>	graph(GRAPHSIZE, 1);
int						G[GRAPHSIZE][GRAPHSIZE];
int						MAX_VALUE = 0x7fffffff;
Randomize::Integer		integer(0, GRAPHSIZE-1);
int						s = integer.create();
int						e;
void InitBreadthFirstSearch_shortestPath()
{
	tracer.directed(false);
	tracer.weighted();
	Layout::setRoot(VerticalLayout({ tracer,logger }));
	tracer.log(logger);
	graph.directed(false);
	graph.weighted();
	int* temp = new int[GRAPHSIZE*GRAPHSIZE];
	//tracer.set(G);에서 G는 2차원 배열이어야 하는데 fill함수는 일차원 배열만 받아서 써야 하므로 번거로웠다
	//->추후 수정해야할 부분
	graph.fill(temp);
	for (int i = 0; i < GRAPHSIZE; i++)
	{
		for (int j = 0; j < GRAPHSIZE; j++)
		{
			G[i][j] = temp[i * GRAPHSIZE + j];
		}
	}
	delete temp;
	tracer.set(G);
	Tracer::delay();
}
//} visualizer

int BFS()
{
	std::vector<int> W;
	std::queue<int> Q;
	int i;
	for (i = 0; i < GRAPHSIZE; i++) {
		W.push_back(MAX_VALUE);
		//visualizer{
		tracer.updateNode(i, MAX_VALUE);
		//}
	}
	W[s] = 0;
	Q.push(s);
	//visualizer{
	tracer.visit(s, NULL, 0);
	Tracer::delay();
	//}
	while (Q.size() > 0)
	{
		int node = Q.front(); Q.pop();
		for (i = 0; i < GRAPHSIZE; i++)
		{
			if (G[node][i]) {						// 현재 노드와 i번째 노드 사이의 edge가 존재하면
				if (W[i] > W[node] + G[node][i]) {	// 현재 path가 이전 path보다 짧다면
					W[i] = W[node] + G[node][i];	// 현재 path로 업데이트
					Q.push(i);						// 자손 노드를 큐에 삽입

					//visualizer{
					tracer.visit(i, node, W[i]);
					Tracer::delay();
					//}
				}
			}
		}
	}
	return W[e];
}

int main()
{
	InitBreadthFirstSearch_shortestPath();
	do {
		e = integer.create();
	} while (e == s);
	//visualizer{
	logger.println("finding the shortest path from " + std::to_string(s) + " to " + std::to_string(e));
	//}
	int minWeight = BFS();
	if (minWeight == MAX_VALUE) {
		//visualizer{
		logger.println("there is no path from " + std::to_string(s) + " to " + std::to_string(e));
		//}
	}
	else {
		//visualizer{
		logger.println("the shortest path from " + std::to_string(s) + " to " + std::to_string(e) + " is "
			+ std::to_string(minWeight));
		//}
	}
}