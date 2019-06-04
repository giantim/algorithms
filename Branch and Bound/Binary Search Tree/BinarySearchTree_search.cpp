#include <iostream>
#include "algorithm-visualizer.h"

int G[11][11] = {// G[i][j] indicates whether the path from the i-th node to the j-th node exists or not
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

int T[11][2] = { // mapping to G as a binary tree , [i][0] indicates left child, [i][1] indicates right child
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

int key;
Randomize::Integer integer(0, 10);
GraphTracer		   tracer("Binary Search Tree");
LogTracer		   logger("Log");

void InitBinarySearchTree_search()
{
	key = integer.create();
	Layout::setRoot(VerticalLayout({ tracer,logger }));
	tracer.set(G);
	tracer.layoutTree(5);
	tracer.log(logger);
	Tracer::delay();
}

void bst(int item, int node, int parent = NULL)
{
	//item	: 찾고자 하는 노드
	//node	: 현재 노드
	//parent: 현재 노드의 부모 노드
	tracer.visit(node, parent);
	Tracer::delay();
	if (item == node) { // key found
		logger.println(" Match Found ");
	}
	else if (item < node) { // key less than value of current node
		if (T[node][0] == -1) {
			logger.println(" Not Found ");
		}
		else {
			bst(item, T[node][0], node);
		}
	}
	else { // key greater than value of current node
		if (T[node][1] == -1) {
			logger.println(" Not Found ");
		}
		else {
			bst(item, T[node][1], node);
		}
	}
}

int main()
{
	InitBinarySearchTree_search();
	logger.println("Finding number "+ std::to_string(key));
	bst(key, 5); // node with key 5 is the root
}