#include <iostream>
#include "algorithm-visualizer.h"

//사용될 트리 자료구조
class TreeNode {
public:
	int element;
	TreeNode* leftChild;
	TreeNode* rightChild;

	TreeNode(int value) {
		element = value;
		leftChild = rightChild = NULL;
	}
};

//visualizer{
int elements[] = { 5, 8, 10, 3, 1, 6, 9, 7, 2, 0, 4 }; 
GraphTracer graphTracer(" BST - Elements marked red indicates the current status of tree ");
Array1DTracer elemTracer(" Elements ");
LogTracer logger (" Log ");
//}

void bstInsert(TreeNode* root, int value, int parent) {
	//visualizer{
	graphTracer.visit(root->element, parent);
	Tracer::delay();
	//}
	if (root->element /*(알맞은 조건 입력)*/ value) {
		if (root->leftChild /*(알맞은 조건 입력)*/ NULL) {
			//visualizer{
			graphTracer.addNode(value);
			graphTracer.addEdge(root->element, value);
			graphTracer.select(value, root->element);
			Tracer::delay();
			graphTracer.deselect(value, root->element);
			logger.println(std::to_string(value) + " Inserted");
			//}
			TreeNode* temp = new TreeNode(value);
			root->leftChild = /*(알맞은 값 입력)*/
		}
		else {
			//visualizer{
			Tracer::delay();
			//}
			bstInsert(root->leftChild, value, root->element);
		}
	}
	else if (root->element /*(알맞은 조건 입력)*/ value) {
		if (root->rightChild /*(알맞은 조건 입력)*/ NULL) {
			//visualizer{
			graphTracer.addNode(value);
			graphTracer.addEdge(root->element, value);
			graphTracer.select(value, root->element);
			Tracer::delay();
			graphTracer.deselect(value, root->element);
			logger.println(std::to_string(value) + " Inserted");
			//}
			TreeNode* temp = new TreeNode(value);
			root->rightChild = /*(알맞은 값 입력)*/
		}
		else {
			//visualizer{
			Tracer::delay();
			//}
			bstInsert(root->rightChild, value, root->element);
		}
	}
	//visualizer{
	graphTracer.leave(root->element, parent);
	Tracer::delay();
	//}
}

void initBst() {
	//visualizer{
	Layout::setRoot(VerticalLayout({ graphTracer, elemTracer, logger }));
	elemTracer.set(elements);
	graphTracer.log(logger);
	Tracer::delay();
	//}
	int Root = elements[0];

	TreeNode* T = new TreeNode(Root);

	//visualizer{
	graphTracer.addNode(Root);
	graphTracer.layoutTree(Root, true);

	logger.println(std::to_string(Root) + " Inserted as root of tree");
	//}
	for (int i = 0; i < (sizeof(elements) / sizeof(*elements)); i++) {
		//visualizer{
		elemTracer.select(i);
		Tracer::delay();
		//}
		bstInsert(T, elements[i], NULL);
		//visualizer{
		elemTracer.deselect(i);
		Tracer::delay();
		//}
	}
}

int main() {
	initBst();
}