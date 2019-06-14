#include "algorithm-visualizer.h"
#include <iostream>
#include <vector>

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
	{-1,-1},
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
int _index = 0;

GraphTracer			treeTracer("Traversal Pre-order");
Array1DTracer		arrayTracer("Print Pre-order");
LogTracer			logger("Log");

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

void preOrder(int root, int parent =0)
{
	if (root == -1) {
        //visualizer{
		logger.println("No more nodes. Backtracking.");
		Tracer::delay();
        //}
		return;
	}

    //visualizer{
	logger.println("Reached " + std::to_string(root));
	treeTracer.visit(root, parent);
	Tracer::delay();

	logger.println("Printing "+std::to_string( root ));
	treeTracer.leave(root);
	arrayTracer.patch(_index++, root);
	Tracer::delay();

	logger.println("Going left from " + std::to_string(root));
	Tracer::delay();
    //}
	preOrder(T[root][0], root);

    //visualizer{
	logger.println("Going right from " + std::to_string(root));
	Tracer::delay();
    //}
	preOrder(T[root][1], root);
}


int main()
{
	InitBinaryTreeTraversal();
	preOrder(5); 
	logger.println("Finished");
}