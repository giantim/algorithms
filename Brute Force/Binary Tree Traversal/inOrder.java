import org.algorithm_visualizer.*;

public class Main {
	int[][] G = { 
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
		};
	int[][] T = { 
			{ -1, -1 },
			{ 0, 2 },
			{ -1, -1 },
			{ 1, 4 },
			{ -1, -1 },
			{ 3, 8 },
			{ -1, 7 },
			{ -1, -1 },
			{ 6, 10 },
			{ -1, -1 },
			{ 9, -1 }, 
		};

    //visualizer {
	private static GraphTracer treeTracer = new GraphTracer("Traversal In-order");
	private static Array1DTracer arrayTracer = new Array1DTracer("Print In-order");
	private static LogTracer logger = new LogTracer("Log");
    //}
	int index = 0;
	
	Main() {
	    //visualizer{
		Layout.setRoot(new VerticalLayout(new Commander[] { treeTracer, arrayTracer, logger }));
		treeTracer.set(G);
		treeTracer.layoutTree(5);
		String[] obj = new String[T.length];
		for (int i = 0; i < T.length; i++)
			obj[i] = "-";
		arrayTracer.set(obj);
		Tracer.delay();
		//}
		inOrder(5, 0);
		logger.println("Finished");
	}
	
	void inOrder(int root, int parent) {
		if (root == -1) {
			logger.println("No more nodes. Backtracking.");
			Tracer.delay();
			return;
		}
	    //visualizer {
			logger.println("Reached " + Integer.toString(root));
			treeTracer.visit(root, parent);
			Tracer.delay();
	        //}
	    //왼쪽 자식 노드로 이동 {
			logger.println("   Going left from " + Integer.toString(root));
			Tracer.delay();
			//}
		inOrder(T[root][0], root);
	       
	    //visualizer {
			logger.println("Printing " + Integer.toString(root));
			treeTracer.leave(root);
			arrayTracer.patch(index++, root);
			Tracer.delay();
	    //}
	    //오른쪽 자식 노드로 이동{
		logger.println("   Going right from " + Integer.toString(root));
		Tracer.delay();
	    //}
		inOrder(T[root][1], root);
	}
	
	public static void main(String[] args) {
		new Main();
	}
}