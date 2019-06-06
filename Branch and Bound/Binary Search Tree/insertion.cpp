#include <iostream>
#include "algorithm-visualizer.h"

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

int elements[] = { 5, 8, 10, 3, 1, 6, 9, 7, 2, 0, 4 }; // item to be inserted
GraphTracer graphTracer(" BST - Elements marked red indicates the current status of tree ");
Array1DTracer elemTracer(" Elements ");
LogTracer logger (" Log ");

void bstInsert(TreeNode* root, int value, int parent) {
	graphTracer.visit(root->element, parent);
	Tracer::delay();
	if (root->element > value) {
		if (root->leftChild == NULL) {
			graphTracer.addNode(value);
			graphTracer.addEdge(root->element, value);
			graphTracer.select(value, root->element);
			Tracer::delay();
			graphTracer.deselect(value, root->element);
			logger.println(std::to_string(value) + " Inserted");

			TreeNode* temp = new TreeNode(value);
			root->leftChild = temp;
		}
		else {
			Tracer::delay();
			bstInsert(root->leftChild, value, root->element);
		}
	}
	else if (root->element < value) {
		if (root->rightChild == NULL) {
			graphTracer.addNode(value);
			graphTracer.addEdge(root->element, value);
			graphTracer.select(value, root->element);
			Tracer::delay();
			graphTracer.deselect(value, root->element);
			logger.println(std::to_string(value) + " Inserted");

			TreeNode* temp = new TreeNode(value);
			root->rightChild = temp;
		}
		else {
			Tracer::delay();
			bstInsert(root->rightChild, value, root->element);
		}
	}
	graphTracer.leave(root->element, parent);
	Tracer::delay();
}

void initBst() {
	Layout::setRoot(VerticalLayout({ graphTracer, elemTracer, logger }));
	elemTracer.set(elements);
	graphTracer.log(logger);
	Tracer::delay();

	int Root = elements[0];

	TreeNode* T = new TreeNode(Root);

	graphTracer.addNode(Root);
	graphTracer.layoutTree(Root, true);

	logger.println(std::to_string(Root) + " Inserted as root of tree");
	for (int i = 0; i < (sizeof(elements) / sizeof(*elements)); i++) {
		elemTracer.select(i);
		Tracer::delay();
		bstInsert(T, elements[i], NULL);
		elemTracer.deselect(i);
		Tracer::delay();
	}
}

int main() {
	initBst();
}