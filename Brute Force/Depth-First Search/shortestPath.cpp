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

int minWeight;					//알고리즘 진행에 따른 현재 최단거리를 저장 및 업데이트할 변수
std::vector<bool> D(GRAPHSIZE);	//해당 노드가 방문되었는지 저장할 컨테이너
int s;							//시작점
int e;							//도착점

void DFS(int node, int parent, int weight)
{
	//node	 : 현재 노드
	//parent : 부모 노드
	//weight : 현재 탐색하는 경로의 누적 weight
	if (minWeight < weight)	return;	
	//현재 탐색하는 경로의 누적 weight가 minWeight보다 더 크면 더 탐색할 가치가 없음	
	
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
	s = integer.create();		//0~4 사이의 난수 생성
	do {
		e = integer.create();
	} while (s == e);
	int MAX_VALUE = 2147483647;	//MAX_VALUE: int 형 정수의 최대값
	minWeight = MAX_VALUE;		//최초 minWeight는 무한대로 설정
	//visualizer{
	logger.println("finding the shortest path from " + std::to_string(s) + " to " +
		std::to_string(e));
	//}
	for (int i = 0; i < GRAPHSIZE; i++)D.push_back(false);	//초기는 모든 노드를 미방문 상태로
	DFS(s, NULL, 0);	//현재 노드에서 탐색 시작
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