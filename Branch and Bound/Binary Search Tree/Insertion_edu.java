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

	Integer elements[] = {/*(배열 원소 입력)*/}; // item to be inserted
	//visualizer {
	GraphTracer graphTracer = new GraphTracer(" BST - Elements marked red indicates the current status of tree ");
	Array1DTracer elemTracer = new Array1DTracer(" Elements ");
	LogTracer logger = new LogTracer(" Log ");
    //}
    
    Main() {
	    //visualizer {
		Layout.setRoot(new VerticalLayout(new Commander[] { graphTracer, elemTracer, logger }));
		elemTracer.set(elements);
		graphTracer.log(logger);
		Tracer.delay();
        //}
		int Root = elements[0]; // take first element as root

		TreeNode T = new TreeNode(Root);
        //visualizer {
		graphTracer.addNode(Root);
		graphTracer.layoutTree(Root, true);
        //}
		logger.println(Integer.toString(Root) + " Inserted as root of tree ");
		for (int i = 1; i < elements.length; i++) {
		    //visualizer {
			elemTracer.select(i);
			Tracer.delay();
			//}
			bstInsert(T, elements[i], null); // insert ith element
			//visualizer {
			elemTracer.deselect(i);
			Tracer.delay();
			//}
		}
	}
    
	void bstInsert(TreeNode root, Integer value, Integer parent) {
		//visualizer{
		graphTracer.visit(root.element, parent);
		Tracer.delay();
		//}
		if (/*(알맞은 조건)*/) {
			if (root.leftChild == null) {
			    //visualizer {
				graphTracer.addNode(value);
				graphTracer.addEdge(root.element, value);
				graphTracer.select(value, root.element);
				Tracer.delay();
				graphTracer.deselect(value, root.element);
				logger.println(Integer.toString(value) + " Inserted");
                //}
				TreeNode temp = new TreeNode(value);
				root./*(?)*/ = temp;
			} else {
			    //visualizer {
				Tracer.delay();
				//}
				bstInsert(root./*(?)*/, value, root.element);
			}
		} else if (/*(알맞은 조건)*/) {
			if (root.rightChild == null) {
			    //visualizer {
				graphTracer.addNode(value);
				graphTracer.addEdge(root.element, value);
				graphTracer.select(value, root.element);
				Tracer.delay();
				graphTracer.deselect(value, root.element);
				logger.println(Integer.toString(value) + " Inserted");
                //}
				TreeNode temp = new TreeNode(value);
				root./*(?)*/ = temp;
			} else {
			    //visualizer {
				Tracer.delay();
				//}
				bstInsert(root./*(?)*/, value, root.element);
			}
		}
		//visualizer{
		graphTracer.leave(root.element, parent);
		Tracer.delay();
		//}
	}

	public static void main(String[] args) {
		new Main();
	}
}