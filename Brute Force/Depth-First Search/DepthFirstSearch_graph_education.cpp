#include "algorithm-visualizer.h"
#include <iostream>
#include <vector>
#include <stack>

const int				GRAPHSIZE = /*(그래프 사이즈 입력)*/
//visualizer{
GraphTracer				graphTracer("GraphTracer");
Array1DTracer			visitedTracer("visited");
LogTracer				logger("LogTracer");
Randomize::Graph<int>	graph(GRAPHSIZE, 0.3);
int						G[GRAPHSIZE][GRAPHSIZE];
int						count = 0;	//무한루프 방지

void InitDepthFirstSearch_graph()
{
	graphTracer.directed(false);
	Layout::setRoot(VerticalLayout({ graphTracer,visitedTracer,logger }));
	graphTracer.log(logger);
	graph.directed(false);
	int temp_G[GRAPHSIZE*GRAPHSIZE];
	graph.fill(temp_G);
	for (int i = 0; i < GRAPHSIZE; i++) {
		for (int j = 0; j < GRAPHSIZE; j++) {
			G[i][j] = temp_G[i * GRAPHSIZE + j];
		}
	}
	graphTracer.set(G);
	Tracer::delay();
}
//}

std::vector<bool> DFSExplore(int graph[GRAPHSIZE][GRAPHSIZE], int source)
{
	//graph: DFS 방법으로 connected인지 확인할 대상이 되는 그래프
	//탐색에 있어서 출발점이 되는 노드
	std::stack<std::array<int, 2>> stack; stack.push({ source, -1 });		
	//stack에 저장되는 데이터는 {현제노드, 부모노드}임 (-1은 노드가 없음을 의미)
	std::vector<bool> visited;	//방문 유무를 담을 컨테이너
	int node, prev, i;
	for (int i = 0; i < GRAPHSIZE; i++) {
		visited.push_back(false);	//초기에는 모든 노드를 미방문으로 세팅
	}
	//visualizer{
	visitedTracer.set(visited);
	//}
	while (/*(알맞은 조건 입력)*/)
	{
		auto temp = stack.top(); stack.pop();
		node = temp[0];
		prev = temp[1];

		if (!visited[node]) {//현재 노드를 방문상태로 표시
			visited[node] = /*(알맞은 값 입력)*/
			//visualizer{
			visitedTracer.patch(node, true);
			//}

			if (prev != -1 && graph[node][prev]) {
				//visualizer{
				graphTracer.visit(node, prev);
				Tracer::delay();
				//}
			}
			else
			{
				//visualizer{
				graphTracer.visit(node);
				Tracer::delay();
				//}
			}

			for (int i = 0; i < GRAPHSIZE; i++) {
				if (graph[node][i]) {
					stack.push({ i,node });
				}
			}
		}
		//visualizer{
		if (count++ > GRAPHSIZE*GRAPHSIZE) break;	//무한루프 방지
		//}
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
		//visualizer{
		logger.println("The Graph is CONECTED");
		//}
	}
	else
	{
		//visualizer{
		logger.println("The Graph is NOT CONNECTED");
		//}
	}
}