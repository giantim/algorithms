import org.algorithm_visualizer.*;

public class Main {

	int G[][] = { // G[i][j] indicates whether the path from the i-th node to the j-th node exists or not
	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	  {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	  {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
	  {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
	};

	int T[][] = { // mapping to G as a binary tree , [i][0] indicates left child, [i][1] indicates right child
	  {-1, -1},
	  {0, 2},
	  {-1, -1},
	  {1, 4},
	  {-1, -1},
	  {3, 8},
	  {-1, 7},
	  {-1, -1},
	  {6, 10},
	  {-1, -1},
	  {9, -1},
	};

	Integer key = new Randomize.Integer(0, G.length - 1).create(); // item to be searched
	GraphTracer tracer = new GraphTracer(" Binary Search Tree ");
	LogTracer logger = new LogTracer(" Log ");
	

	void bst(int item, int node, Integer parent) { // node = current node , parent = previous node
	  tracer.visit(node, parent);
	  Tracer.delay();
	  if (item == node) { // key found
	    logger.println(" Match Found ");
	  } else if (item < node) { // key less than value of current node
	    if (T[node][0] == -1) {
	      logger.println(" Not Found ");
	    } else {
	      bst(item, T[node][0], node);
	    }
	  } else { // key greater than value of current node
	    if (T[node][1] == -1) {
	      logger.println(" Not Found ");
	    } else {
	      bst(item, T[node][1], node);
	    }
	  }
	}

	Main() {
		Layout.setRoot(new VerticalLayout(new Commander[]{ tracer, logger }));
		tracer.set(G);
		tracer.layoutTree(5);
		tracer.log(logger);
		Tracer.delay();
		logger.println("Finding number " + Integer.toString(key));
		bst(key, 5, null); // node with key 5 is the root
	}
	
	
	public static void main(String[] args) {
		new Main();
	}
}
