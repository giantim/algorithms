#include "algorithm-visualizer.h"
#include <iostream>
#include <vector>

int G[11][11] = { 
	//G[i][j] 는 i 노드에서 j 노드로의 edge가 존재하는지 유무
	//즉, G의 인접행렬
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
};

int T[11][2] = { 
	//G의 연관관계를 정리한 데이터
	//노드 i의 연관관계 : [i][0] - 왼쪽 자손
	//                   [i][1] - 오른쪽 자손(-1은 자손이 없음을 의미)
	{-1, -1},
	{0, 2},
	{-1, -1},
	{1, 4},
	{-1, -1},
	{3, 8},
	{-1, 7},
	{-1, -1},
	{6, 10},
	{-1, -1},
	{9, -1},
};

//visualizer {
GraphTracer		treeTracer("Traversal In-order");
Array1DTracer	arrayTracer("Print In-order");
LogTracer		logger("Log");
int				_index = 0;
int				count = 0;	//무한 재귀호출 방지

void InitBinaryTreeTraversal()
{
	Layout::setRoot(VerticalLayout({ treeTracer,arrayTracer,logger }));
	treeTracer.set(G);
	treeTracer.layoutTree(5);
	std::vector<std::string> arrayContent(11);
	for (int i = 0; i < 11; i++)
		arrayContent[i] = "-";
	arrayTracer.set(arrayContent);
	Tracer::delay();
}
//}

void InOrder(int root, int parent = 0)
{
	if (root == -1)		//더는 노드가 없을때
	{
		//visualizer {
		logger.println("No more nodes. Backtracking.");
		Tracer::delay();
		//}
		return;
	}

	//visualizer {
	logger.println("Reached" + std::to_string(root));
	treeTracer.visit(root, parent);
	Tracer::delay();
	logger.println("Going left from" + std::to_string(root));
	Tracer::delay();
	count++;
	if (count > 70) return;	//무한 재귀호출 방지
	//}

	InOrder(/*(전달될 인자를 입력)*/, /*(전달될 인자를 입력)*/);

	//visualizer {
	logger.println("Printing" + std::to_string(root));
	treeTracer.leave(root);
	arrayTracer.patch(_index++, root);
	Tracer::delay();
	logger.println("Going right from" + std::to_string(root));
	Tracer::delay();
	//}

	InOrder(/*(전달될 인자를 입력)*/, /*(전달될 인자를 입력)*/);
}


int main()
{
	InitBinaryTreeTraversal();
	InOrder(5); //5를 최초의 루트로 시작
	logger.println("Finished");
}