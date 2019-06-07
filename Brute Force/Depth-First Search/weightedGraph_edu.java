import org.algorithm_visualizer.*;
import java.util.*;

public class Main {
    //visualizer{
	private static GraphTracer tracer;
	private static LogTracer logger;
	private static Randomize.Graph G;
	//}
	private static Object[][] graph;  
	private static int[] D;
	private static int number_Of_Node = /*?*/;

	Main() {
	    
	    // graph를 생성하는 함수를 이용하여 그래프를 무작위로 구성{
		tracer = new GraphTracer().directed(false).weighted();
		logger = new LogTracer();
		Layout.setRoot(new VerticalLayout(new Commander[] {tracer, logger}));
		tracer.log(logger);
		G = new Randomize.Graph(number_Of_Node, 1);
		graph = G.directed(false).weighted(true).create();
		tracer.set(graph);
		Tracer.delay();
        //}
        // 배열 graph의 원소는 0과 -1로 구성되어 있고,
        // garph[i][j] != 1 : i 노드와 j 노드가 서로 인접해 있다.
        //             == 0 :                        인접해 있지 않다.
        
		for (int i = 0; i < graph.length; i++) 
		{ 
			logger.println("start from " + i);
			D = new int[graph.length];
			
			for (int j = 0; j < graph.length; j++) 
				D[i] = 0;
			
			DFS(i, 0, 0);
		}
	}
	
	void DFS(int node, int parent, int weight) 
	{
		//visualizer{
		tracer.visit(node, parent, weight);
		Tracer.delay();
		//}
		
		//D[node] 는 node를 방문했는지에 대한 값을 저장
		D[node] = 1; 
		for (int i = 0; i < graph[node].length; i++) 
		{
			if ((int)graph[node][i] != 0)
			{ 
				if (D[i] == 0) 
				{
				    //재귀 호출
					DFS(/*?*/, /*?*/, /*?*/ + (int)/*?*/);
				}
			}
		}
		D[node] = 0;
		//visualizer{
		tracer.leave(node, parent, 0);
		Tracer.delay();
		//}
	}

	public static void main(String[] args) {
		new Main();
	}
}