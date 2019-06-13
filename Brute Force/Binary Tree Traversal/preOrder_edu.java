import org.algorithm_visualizer.*;

public class Main 
{
    // G[i][j] 는 i 노드에서 j 노드로의 edge가 존재하는지 유무
	// 즉, G의 인접행렬
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

    // T행렬은 그래프 G의 각 노드들의 연관관계를 정의한 배열
    // ex) T[i] = {j, k} : i-노드는 J 왼쪽 자손과, k 오른쪽 자손을 갖는다.
    //     -1 일 때는 자손이 없음을 의미
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
	
    Main() 
    {
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

	void preOrder(int root, int parent) 
	{
		if (root == -1) 
		{
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
		preOrder( T[/*(?)*/][/*(?)*/], /*(?)*/);
        
         //오른쪽 자손 노드로 이동{
		logger.println("   Going right from " + Integer.toString(root));
		Tracer.delay();
	    //}
		preOrder( T[/*(?)*/][/*(?)*/], /*(?)*/);
	}

	public static void main(String[] args) {
		new Main();
	}
}