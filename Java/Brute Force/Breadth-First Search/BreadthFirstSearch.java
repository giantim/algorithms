import org.algorithm_visualizer.*;
import org.algorithm_visualizer.Randomize.Graph;
import java.util.*;

public class Main {

	GraphTracer tracer;
	LogTracer logger;
	Randomize.Graph G;
	int number_Of_Node;
	Object[][] graph;
	Integer s;
	int e;
	
	Main() {
		tracer = new GraphTracer().directed(false).weighted();
		logger = new LogTracer();
		Layout.setRoot(new VerticalLayout(new Commander[] {tracer, logger}));
		tracer.log(logger);

		number_Of_Node = 5;
		G = new Randomize.Graph(number_Of_Node, 1);
		
		//G.directed(false); G.weighted(true);
		G.directed(false).weighted(true);
		graph = G.create();
		
		tracer.set(graph);
		Tracer.delay();
		
		s = new Randomize.Integer(0, number_Of_Node - 1).create(); // s = start node
		do 
		{
		  e = new Randomize.Integer(0, number_Of_Node - 1).create();
		} while (s == e);
		
		int MAX_VALUE = 0x7fffffff;
		logger.println("finding the shortest path from " +  s + " to " + e);
		
		
		int minWeight = BFS(s);
		if (minWeight == MAX_VALUE)
		{
		  logger.println("there is no path from " +  s + " to " + e);
		} 
		else 
		{
		  logger.println("the shortest path from " + s + " to "  + e + " is " + minWeight);
		}
		
	}


	int BFS(Integer s)
	{
		// W[i] indicates the length of the shortest path from start node to the i-th node
		int[] W = new int[number_Of_Node];
		Queue<Integer> Q = new LinkedList<Integer>() ;
		for (int i = 0; i < number_Of_Node; i++) 
		{
			W[i] = Integer.MAX_VALUE;
			tracer.updateNode(i, Integer.MAX_VALUE);
		}
		
		W[s] = 0;
		Q.offer(s); // add start node to queue
		tracer.visit(s, null , 0);
		Tracer.delay();
		while (Q.size() > 0) {
			int node = Q.poll(); // dequeue
			for (int i = 0; i < graph[node].length; i++)
			{
				if ((int)graph[node][i] != 0) 
				{ // if the edge from current node to the i-th node exists
					if (W[i] > (W[node] + (int)graph[node][i]))
					{ // if current path is shorter than the previously shortest path
						W[i] = W[node] + (int)graph[node][i]; // update the length of the shortest path
						
						Q.offer(i); // add child node to queue
						tracer.visit(i, node, W[i]);
						Tracer.delay();
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