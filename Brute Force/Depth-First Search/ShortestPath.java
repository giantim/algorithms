import org.algorithm_visualizer.*;
import org.algorithm_visualizer.Randomize.Graph;
import java.util.*;

public class Main {
	GraphTracer tracer;
	LogTracer logger;
	Randomize.Graph G;
	Object[][] graph;
	Integer s;
	int number_Of_Node;
	int e;
	int MAX_VALUE;
	int minWeight;
	int[] D;
	
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

		MAX_VALUE = 0x7fffffff;
		minWeight = Integer.MAX_VALUE;

		logger.println("finding the shortest path from "+ s + " to "+ e);

		D = new int[number_Of_Node]; // D[i] indicates whether the i-th node is discovered or not

		for (int i = 0; i < number_Of_Node; i++)
			D[i] = 0;

//		minWeight = DFS(s, -1, 0);
		DFS(s, s, 0);

		if (minWeight == MAX_VALUE) 
		{
			logger.println("there is no path from " +  s + " to " + " e ");
		} 
		else 
		{
			logger.println("the shortest path from " + s + " to " + e+ " is " + minWeight);
		}
	}

	void DFS(int node, int parent, int weight) 
	{     // node = current node, parent = previous node
		if (minWeight < weight) return;
		
		if (node == e) 
		{
			tracer.visit(node, parent, weight);
			Tracer.delay();

			if (minWeight > weight) 
			{
				minWeight = weight;
			}

			tracer.leave(node, parent, minWeight);
			Tracer.delay();
			return;
		}

		D[node] = 1; // label current node as discovered
		
		tracer.visit(node, parent, weight);
		Tracer.delay();
		for (int i = 0; i < graph[node].length; i++) 
		{
			if ((int)graph[node][i] != 0)
			{ // if the path from current node to the i-th node exists
				if (D[i] == 0) 
				{ // if the i-th node is not labeled as discovered
					DFS(i, node, weight + (int)graph[node][i]); // recursively call DFS
				}
			}
		}

		D[node] = 0; // label current node as undiscovered
		tracer.leave(node, parent, 0);
		Tracer.delay();
	}

	public static void main(String[] args) {
		new Main();
	}
}