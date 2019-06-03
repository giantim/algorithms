import org.algorithm_visualizer.*;
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

		graph = G.directed(false).weighted(true).create();
		tracer.set(graph);
		Tracer.delay();

		for (int i = 0; i < graph.length; i++) 
		{ // start from every node
			logger.println("start from " + i);
			D = new int[graph.length];
			for (int j = 0; j < graph.length; j++) 
				D[i] = 0;
			
			DFS(i, 0, 0);
		}
	}

	void DFS(int node, int parent, int weight) { // node = current node, parent = previous node
		tracer.visit(node, parent, weight);
		Tracer.delay();
		D[node] = 1; // label current node as discovered
		for (int i = 0; i < graph[node].length; i++) {
			if ((int)graph[node][i] != 0) { // if the edge from current node to the i-th node exists
				if (D[i] == 0) { // if the i-th node is not labeled as discovered
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






