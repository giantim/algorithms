#include "algorithm-visualizer.h"
#include <iostream>

//visualizer {
GraphTracer		tracer("GraphTracer");
LogTracer		logger("LogTracer");
int				count = 0;	//무한루프 방지
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

void InitDepthFirstSearch_tree()
{
	tracer.log(logger);
	Layout::setRoot(VerticalLayout({ tracer,logger }));
	tracer.set(G);
	tracer.layoutTree(0);
	Tracer::delay();
}
//}

void DFS(int node, int parent = NULL)
{
	//node	 : 현재 노드
	//parent : 부모 노드

	//visualizer{
	if (count++ > 11 * 11) return;	//무한루프 방지
	tracer.visit(node, parent);
	Tracer::delay();
	//}
	for (int i = 0; i < 11; i++) {
		if (G[/*(알맞은 값 입력)*/][i])
			DFS(/*(알맞은 값 입력)*/, node);
	}
}

int main()
{
	InitDepthFirstSearch_tree();
	DFS(0);
}