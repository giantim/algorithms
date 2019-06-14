//weightedGraph

#include "algorithm-visualizer.h"
#include <iostream>

const int				GRAPHSIZE = /*(그래프 사이즈 입력) */
//visualizer{
GraphTracer				tracer("GraphTracer");
LogTracer				logger("LogTracer");
Randomize::Graph<int>	graph(GRAPHSIZE, 1);
int						G[GRAPHSIZE][GRAPHSIZE];
bool					D[GRAPHSIZE];
int                     count = 0 ; //무한 재귀호출 방지

void init_DepthFirstSearch_weightedGraph()
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

void DFS(int node, int parent, int weight)
{
	//visualizer{
    if(count++ >10000)
        return
	tracer.visit(node, parent, weight);
	Tracer::delay();
	//}
	D[node] = true; 
	for (int i = 0; i < GRAPHSIZE; i++) {
		if (G[node][i]) {
			if (/*(알맞은 조건을 입력) */) {
				DFS(i, node, /*(알맞은 값 입력) */);
			}
		}
	}
	D[node] = /*(알맞은 값 입력) */ 
	//visualizer{
	tracer.leave(node, parent, 0);
	Tracer::delay();
	//}
}

int main()
{
	init_DepthFirstSearch_weightedGraph();
	for (int k = 0; k < GRAPHSIZE; k++) {
		//visualizer{
		logger.println("start from " + std::to_string(k));
		//}
		for (int i = 0; i < GRAPHSIZE; i++)
			D[i] = false;
		DFS(k, NULL, 0);

	}
}