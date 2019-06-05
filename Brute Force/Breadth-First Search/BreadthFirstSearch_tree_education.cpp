#include "algorithm-visualizer.h"
#include <iostream>
#include <queue>

//visualizer{
int G[11][11] = {
	//G[i][j] 는 i 노드에서 j 노드로의 edge가 존재하는지 유무
	//즉, G의 인접행렬
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
int			count = 0;

void InitBreadthFirstSearch_tree()
{
	tracer.log(logger);
	Layout::setRoot(VerticalLayout({ tracer,logger }));
	tracer.set(G);
	tracer.layoutTree(0);
	Tracer::delay();
}
//}

void BFS(int s)
{
	std::queue<int> Q;
	Q.push(s);
	//visualizer{
	tracer.visit(s);
	Tracer::delay();
	//}
	while (/*(알맞은 조건 입력)*/) {
		//visualizer{
		if (count++ > 130) break;	//무한루프 방지
		//}
		int node = Q.front();	//dequeue
		Q.pop();
		for (int i = 0; i < 11; i++) {
			if (/*(알맞은 조건 입력)*/) {
				Q.push(i);
				//visualizer{
				tracer.visit(i, node);
				Tracer::delay();
				//}
			}
		}
	}
}

int main()
{
	InitBreadthFirstSearch_tree();
	BFS(0);
}