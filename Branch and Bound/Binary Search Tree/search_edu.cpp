#include <iostream>
#include "algorithm-visualizer.h"

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

//visualize {
int key;
Randomize::Integer integer(0, 10);
GraphTracer		   tracer("Binary Search Tree");
LogTracer		   logger("Log");
int				   count = 0;//무한루프 방지

void InitBinarySearchTree_search()
{
	Layout::setRoot(VerticalLayout({ tracer,logger }));
	tracer.set(G);
	tracer.layoutTree(5);
	tracer.log(logger);
	Tracer::delay();
}
// }

void bst(int item, int node, int parent = NULL)
{
	//visualize {
	if (count++ > 11 * 11 * 11) return; //무한 재귀호출 방지
	tracer.visit(node, parent);
	Tracer::delay();
	//}
	if (item == node) {		// key 발견
		//visualize {
		logger.println(" Match Found ");
		//}
	}
	else if (item < node) { // key 가 현재 노드보다 작을 경우
		if (T[node][/*(알맞은 index입력)*/] == /*(노드의 끝에 도달했을 조건)*/) {
			//visualize {
			logger.println(" Not Found ");
			//}
		}
		else {
			bst(/*(전달될 인자를 입력)*/, T[node][0], node);
		}
	}
	else { // key 가 현재 node보다 클 경우
		if (T[node][/*(알맞은 index입력)*/] == /*(노드의 끝에 도달했을 조건)*/) {
			//visualize{
			logger.println(" Not Found ");
			//}
		}
		else {
			bst(/*(전달될 인자를 입력)*/, T[node][1], node);
		}
	}
}

int main()
{
	key = integer.create();			//key값 생성
	//visualize {
	InitBinarySearchTree_search();
	logger.println("Finding number " + std::to_string(key));
	//}
	bst(key, 5); //5를 최초의 루트로 시작
}