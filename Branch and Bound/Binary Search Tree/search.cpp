#include <iostream>
#include "algorithm-visualizer.h"

int G[11][11] = {	
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

//visualizer{
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
//}

void bst(int item, int node, int parent = NULL)
{
	tracer.visit(node, parent);
	//visualizer{
	Tracer::delay();
	//}
	if (item == node) { 
		//visualizer{
		logger.println(" Match Found ");
		//}
	}
	else if (item < node) { 
		if (T[node][0] == -1) {
			//visualizer{
			logger.println(" Not Found ");
			//}
		}
		else {
			bst(item, T[node][0], node);
		}
	}
	else { 
		if (T[node][1] == -1) {
			//visualizer{
			logger.println(" Not Found ");
			//}
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
	bst(key, 5); 
}