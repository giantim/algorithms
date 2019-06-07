import org.algorithm_visualizer.*;
import org.algorithm_visualizer.Randomize.Graph;
import java.util.*;

public class Main {
    //visualizer{
	private static GraphTracer tracer;
	private static LogTracer logger;
	private static Randomize.Graph G;
	//}
	private static Object[][] graph;
	private static int number_Of_Node = 5;
	private static int s;
	private static int e;
	private static int MAX_VALUE = 0x7fffffff;
	private static int minWeight;
	
	Main() {
	    //visualizer{
		tracer = new GraphTracer().directed(false).weighted();
		logger = new LogTracer();
		Layout.setRoot(new VerticalLayout(new Commander[] {tracer, logger}));
		tracer.log(logger);
		//}
		//grapg 생성{
		G = new Randomize.Graph(number_Of_Node, 1);
		G.directed(false).weighted(true);
		graph = G.create();
		tracer.set(graph);
		Tracer.delay();
		//}
		//start node 와 end node 무작위 생성{
		s = new Randomize.Integer(0, number_Of_Node - 1).create();
		do 
		{
		  e = new Randomize.Integer(0, number_Of_Node - 1).create();
		} while (s == e);
		logger.println("finding the shortest path from " +  s + " to " + e);
		//}
		
		minWeight = BFS(s);
		
		if (minWeight == MAX_VALUE){
		  logger.println("there is no path from " +  s + " to " + e);
		} else {
		  logger.println("the shortest path from " + s + " to "  + e + " is " + minWeight);
		}
	}


	int BFS(Integer s)
	{
		int[] W = new int[number_Of_Node];
		Queue<Integer> Q = new LinkedList<Integer>() ;
		
		for (int i = 0; i < number_Of_Node; i++) 
		{
			W[i] = Integer.MAX_VALUE;
			//visualizer{
			tracer.updateNode(i, Integer.MAX_VALUE);
			//}
		}
		
		W[s] = 0;
		Q.offer(s);
		tracer.visit(s, null , 0);
		Tracer.delay();
		while (Q.size() > 0) {
			int node = Q.poll();
			for (int i = 0; i < graph[node].length; i++)
			{
				if ((int)graph[node][i] != 0) 
				{ 
					if (W[i] > (W[node] + (int)graph[node][i]))
					{ 
						W[i] = W[node] + (int)graph[node][i];
						
						Q.offer(i);
						//visualizer{
						tracer.visit(i, node, W[i]);
						Tracer.delay();
						//}
					}
				}
			}
		}
		return W[e];
	}

	public static void main(String[] args) {
		new Main();
	}
}