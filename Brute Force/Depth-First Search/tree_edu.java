import org.algorithm_visualizer.*;
import java.util.*;

public class Main {
    
    //visualizer{
	private static GraphTracer tracer;
	private static LogTracer logger;
	//}
	private static Object[][] graph;
	private static String[] visited;
	
	
	Main() 
	{   
	    // G[i][j] 는 i 노드에서 j 노드로의 edge가 존재하는지 유무
	    // 즉, G의 인접행렬
		int[][] G =	{ 
				{0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		};
		
        //visualizer{
		tracer = new GraphTracer().directed(true).weighted(false);
		logger = new LogTracer();
		Layout.setRoot(new VerticalLayout(new Commander[] {tracer, logger}));
		tracer.log(logger);
		tracer.set(G);
		tracer.layoutTree(0);
		Tracer.delay();
        //}
		DFS(G,0,0);
	}

	void DFS(int[][] G, int node, int parent) 
	{ 
		//visualizer{
		tracer.visit(node, parent);
		Tracer.delay();
		//}
		for (int i = 0; i < G[node].length; i++)
		{
			if (G[node][i] != 0)
			{ 
                //재귀 호출
				DFS(/*?*/, /*?*/, /*?*/); 
			}
		}
	}

	public static void main(String[] args) {
		new Main();
	}
}