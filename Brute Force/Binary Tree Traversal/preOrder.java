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
    //visualizer{
	GraphTracer treeTracer = new GraphTracer("Traversal Pre-order");
	Array1DTracer arrayTracer = new Array1DTracer("Print Pre-order");
	LogTracer logger = new LogTracer("Log");
    //}
	int index = 0;

    Main() {
        // 5번 노드를 root로 하여, inOrder 함수 실행{
		Layout.setRoot(new VerticalLayout(new Commander[] { treeTracer, arrayTracer, logger }));
		treeTracer.set(G);
		treeTracer.layoutTree(5);
		String[] obj = new String[T.length];
		for (int i = 0; i < T.length; i++)
			obj[i] = "-";
		arrayTracer.set(obj);
		Tracer.delay();
		//}
		preOrder(5, 0);
		logger.println("Finished");
	}

	void preOrder(int root, int parent) {
		if (root == -1) {
		    //더이상  Backtracking할 노드가 존재하지 않을 때{
			logger.println("No more nodes. Backtracking.");
			Tracer.delay();
		    //}
			return;
		}
        //현재 노드 출력{
		logger.println("Reached " + Integer.toString(root));
		treeTracer.visit(root, parent);
		Tracer.delay();

		logger.println("Printing " + Integer.toString(root));
		treeTracer.leave(root);
        
		arrayTracer.patch(index++, root);
		Tracer.delay();
        //}
        
         //왼쪽 자손 노드로 이동{
		logger.println("   Going left from " + Integer.toString(root));
		Tracer.delay();
	    //}
		preOrder(T[root][0], root);
        
         //오른쪽 자손 노드로 이동{
		logger.println("   Going right from " + Integer.toString(root));
		Tracer.delay();
	    //}
		preOrder(T[root][1], root);
	}

	public static void main(String[] args) {
		new Main();
	}
}