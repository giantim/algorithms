import org.algorithm_visualizer.*;
import java.util.*;

public class Main {
	
	GraphTracer tracer = new GraphTracer();
	LogTracer logger = new LogTracer();
	
	int G[][] = { // G[i][j] indicates whether the path from the i-th node to the j-th node exists or not
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
	
	void BFS(Integer s) { // s = start node
	  Queue<Integer> Q = new LinkedList<Integer>();
	  Q.offer(s); // add start node to queue
	  tracer.visit(s);
	  Tracer.delay();
	  while (Q.size() > 0) {
	    int node = Q.poll(); // dequeue
	    for (int i = 0; i < G[node].length; i++) {
	      if ((int)G[node][i] != 0) { // if current node has the i-th node as a child
	        Q.offer(i); // add child node to queue
	        tracer.visit(i, node);
	        Tracer.delay();
	      }
	    }
	  }
	}

	Main() {
		tracer.log(logger);
		Layout.setRoot(new VerticalLayout(new Commander[] { tracer, logger }));
		tracer.set(G);
		tracer.layoutTree(0);
		Tracer.delay();
		BFS(0);
	}
	
	public static void main(String[] args) {
		new Main();
	}
}