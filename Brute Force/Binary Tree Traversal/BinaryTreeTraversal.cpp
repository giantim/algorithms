#include "algorithm-visualizer.h"
#include <iostream>
#include <vector>

int G[11][11] = { // G[i][j] indicates whether the path from the i-th node to the j-th node exists or not
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

int index = 0;

GraphTracer treeTracer("Traversal In-order");
Array1DTracer arrayTracer("Print In-order");
LogTracer logger("Log");

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

void InOrder(int root, int parent = 0)
{
	if (root == -1)
	{
		logger.println("No more nodes. Backtracking.");
		Tracer::delay();
		return;
	}

	logger.println("Reached" + std::to_string(root));
	treeTracer.visit(root, parent);
	Tracer::delay();

	logger.println("Going left from" + std::to_string(root));
	Tracer::delay();
	InOrder(T[root][0], root);

	logger.println("Printing" + std::to_string(root));
	treeTracer.leave(root);
	arrayTracer.patch(index++, root);
	Tracer::delay();

	logger.println("Going right from" + std::to_string(root));
	Tracer::delay();
	InOrder(T[root][1], root);
}


int main()
{
	InitBinaryTreeTraversal();
	InOrder(5); // node with key 5 is the root
	logger.println("Finished");
}