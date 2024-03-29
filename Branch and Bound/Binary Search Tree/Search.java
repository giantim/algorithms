import org.algorithm_visualizer.*;

public class Main {
    
	int G[][] = { 
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
    
	int T[][] = { 
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
    //visualizer {
	Integer key = new Randomize.Integer(0, G.length - 1).create(); 
	GraphTracer tracer = new GraphTracer(" Binary Search Tree ");
	LogTracer logger = new LogTracer(" Log ");
	//}
	
    Main() {
	    //visualizer {
		Layout.setRoot(new VerticalLayout(new Commander[]{ tracer, logger }));
		tracer.set(G);
		tracer.layoutTree(5);
		tracer.log(logger);
		Tracer.delay();
		logger.println("Finding number " + Integer.toString(key));
		//}
		bst(key, 5, null); 
	}

	void bst(int item, int node, Integer parent) { 
	  //visualizer {
	  tracer.visit(node, parent);
	  Tracer.delay();
	  //}
	  if (item == node) { 
	    logger.println(" Match Found ");
	  } else if (item < node) { 
	    if (T[node][0] == -1) {
	      logger.println(" Not Found ");
	    } else {
	      bst(item, T[node][0], node);
	    }
	  } else { 
	    if (T[node][1] == -1) {
	      logger.println(" Not Found ");
	    } else {
	      bst(item, T[node][1], node);
	    }
	  }
	}

	public static void main(String[] args) {
		new Main();
	}
}