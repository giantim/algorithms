#include "algorithm-visualizer.h"
#include <iostream>
#include <vector>
#include <queue>

const int				GRAPHSIZE = /*(원하는 그래프 사이즈 입력)*/
//visualizer{
GraphTracer				tracer("GraphTracer");
LogTracer				logger("LogTracer");
Randomize::Graph<int>	graph(GRAPHSIZE, 1);
int						G[GRAPHSIZE][GRAPHSIZE];
int						MAX_VALUE = 0x7fffffff;
Randomize::Integer		integer(0, GRAPHSIZE - 1);
int						s = integer.create();
int						e;
int						count = 0;	//무한루프 방지
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
		W.push_back(MAX_VALUE);		//방문하지 않은 노드들의 포텐셜 path길이를 무한대로 설정
		//visualizer{
		tracer.updateNode(i, MAX_VALUE);
		//}
	}
	W[s] = /*(시작 노드의 포텐셜을 설정)*/
	Q.push(/*(큐에 삽입할 알맞은 노드를 입력)*/);
	//visualizer{
	tracer.visit(s, NULL, 0);
	Tracer::delay();
	//}
	while (/*(알맞은 조건을 입력)*/)
	{
		//visualizer{
		if (count++ > GRAPHSIZE*GRAPHSIZE) break;	//무한루프 방지
		//}
		int node = Q.front(); Q.pop();	//dequeue
		for (i = 0; /*(알맞은 조건을 입력)*/; i++)
		{
			if (G[node][i]) {						// 현재 노드와 i번째 노드 사이의 edge가 존재하면
				if (/*(알맞은 조건을 입력)*/) {		// 현재 path가 이전 path보다 짧다면
					W[i] = /*(알맞은 값 입력)*/		// 현재 path로 업데이트
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