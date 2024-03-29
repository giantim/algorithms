import org.algorithm_visualizer.*;
import java.util.*;

public class Main {
    //visualizer{
	private static GraphTracer tracer;
	private static LogTracer logger;
	private static Randomize.Graph G;
	//}
	private static Object[][] graph;  
	private static int number_Of_Node = 5;
	private static int[] D;

	Main() {
	    
	    //visualizer{
		tracer = new GraphTracer().directed(false).weighted();
		logger = new LogTracer();
		Layout.setRoot(new VerticalLayout(new Commander[] {tracer, logger}));
		tracer.log(logger);
		G = new Randomize.Graph(number_Of_Node, 1);
		graph = G.directed(false).weighted(true).create();
		tracer.set(graph);
		Tracer.delay();
        //}
        
		for (int i = 0; i < graph.length; i++) 
		{ 
			logger.println("start from " + i);
			D = new int[graph.length];
			
			for (int j = 0; j < graph.length; j++) 
				D[i] = 0;
			
			DFS(i, 0, 0);
		}
	}
	
	void DFS(int node, int parent, int weight) {
		//visualizer{
		tracer.visit(node, parent, weight);
		Tracer.delay();
		//}
		D[node] = 1; 
		for (int i = 0; i < graph[node].length; i++) {
			if ((int)graph[node][i] != 0) { 
				if (D[i] == 0) {
					DFS(i, node, weight + (int)graph[node][i]);
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