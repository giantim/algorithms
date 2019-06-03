import org.algorithm_visualizer.*;
import java.util.*;

public class Main {
	GraphTracer tracer;
	LogTracer logger;
	Object[][] graph;
	String[] visited;
	
	
	Main() 
	{// G[i][j] indicates whether the path from the i-th node to the j-th node exists or not                                               
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


		tracer = new GraphTracer().directed(true).weighted(false);
		logger = new LogTracer();
		Layout.setRoot(new VerticalLayout(new Commander[] {tracer, logger}));
		tracer.log(logger);
		tracer.set(G);
		tracer.layoutTree(0);
		Tracer.delay();

		DFS(G,0,0);
	}

	void DFS(int[][] G, int node, int parent) { // node = current node, parent = previous node
		tracer.visit(node, parent);
		Tracer.delay();
		for (int i = 0; i < G[node].length; i++) {
			if (G[node][i] != 0) { // if current node has the i-th node as a child
				DFS(G, i, node); // recursively call DFS
			}
		}
	}

	public static void main(String[] args) {
		new Main();
	}
}