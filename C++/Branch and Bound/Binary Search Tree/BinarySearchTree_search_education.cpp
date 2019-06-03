#include <iostream>
#include "algorithm-visualizer.h"

int G[11][11] = {	//G[i][j] �� i ��忡�� j ������ edge�� �����ϴ��� �����̴�
					//��, G�� �������
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
	//G�� �������踦 ������ ������
	//��� i�� �������� : [i][0] - ���� �ڼ�
	//                   [i][1] - ������ �ڼ�(-1�� �ڼ��� ������ �ǹ�)
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
	//item	: ã���� �ϴ� ���
	//node	: ���� ���
	//parent: ���� ����� �θ� ���
	//visualize {
	tracer.visit(node, parent);
	Tracer::delay();
	//}
	if (item == node) {		// key �߰�
		//visualize {
		logger.println(" Match Found ");
		//}
	}
	else if (item < node) { // key �� ���� ��庸�� ���� ��
		if (T[node][/*(�˸��� index�Է�)*/] == /*(����� ���� �������� ����)*/) {
			//visualize {
			logger.println(" Not Found ");
			//}
		}
		else {
			bst(/*(���޵� ���ڸ� �Է�)*/, T[node][0], node);
		}
	}
	else { // key greater than value of current node
		if (T[node][/*(�˸��� index�Է�)*/] == /*(����� ���� �������� ����)*/) {
			//visualize{
			logger.println(" Not Found ");
			//}
		}
		else {
			bst(/*(���޵� ���ڸ� �Է�)*/, T[node][1], node);
		}
	}
}

int main()
{
	key = integer.create();			//key�� ����
	//visualize {
	InitBinarySearchTree_search();
	logger.println("Finding number " + std::to_string(key));
	//}
	bst(key, 5); // node with key 5 is the root
}