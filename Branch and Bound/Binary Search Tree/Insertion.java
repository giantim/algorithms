import org.algorithm_visualizer.*;

public class Main {

	class TreeNode {
		public int element;
		public TreeNode leftChild;
		public TreeNode rightChild;

		public TreeNode(int value) {
			this.element = value;
			leftChild = rightChild = null;
		}
	}

	Integer elements[] = { 5, 8, 10, 3, 1, 6, 9, 7, 2, 0, 4 }; // item to be inserted
	GraphTracer graphTracer = new GraphTracer(" BST - Elements marked red indicates the current status of tree ");
	Array1DTracer elemTracer = new Array1DTracer(" Elements ");
	LogTracer logger = new LogTracer(" Log ");

	void bstInsert(TreeNode root, Integer value, Integer parent) {
		graphTracer.visit(root.element, parent);
		Tracer.delay();
		if (root.element > value) {
			if (root.leftChild == null) {
				graphTracer.addNode(value);
				graphTracer.addEdge(root.element, value);
				graphTracer.select(value, root.element);
				Tracer.delay();
				graphTracer.deselect(value, root.element);
				logger.println(Integer.toString(value) + " Inserted");

				TreeNode temp = new TreeNode(value);
				root.leftChild = temp;
			} else {
				Tracer.delay();
				bstInsert(root.leftChild, value, root.element);
			}
		} else if (root.element < value) {
			if (root.rightChild == null) {
				graphTracer.addNode(value);
				graphTracer.addEdge(root.element, value);
				graphTracer.select(value, root.element);
				Tracer.delay();
				graphTracer.deselect(value, root.element);
				logger.println(Integer.toString(value) + " Inserted");

				TreeNode temp = new TreeNode(value);
				root.rightChild = temp;
			} else {
				Tracer.delay();
				bstInsert(root.rightChild, value, root.element);
			}
		}
		graphTracer.leave(root.element, parent);
		Tracer.delay();
	}

	Main() {
		Layout.setRoot(new VerticalLayout(new Commander[] { graphTracer, elemTracer, logger }));
		elemTracer.set(elements);
		graphTracer.log(logger);
		Tracer.delay();

		int Root = elements[0]; // take first element as root

		TreeNode T = new TreeNode(Root);

		graphTracer.addNode(Root);
		graphTracer.layoutTree(Root, true);

		logger.println(Integer.toString(Root) + " Inserted as root of tree ");
		for (int i = 1; i < elements.length; i++) {
			elemTracer.select(i);
			Tracer.delay();
			bstInsert(T, elements[i], null); // insert ith element
			elemTracer.deselect(i);
			Tracer.delay();
		}
	}

	public static void main(String[] args) {
		new Main();
	}
}
