import org.algorithm_visualizer.*;

public class Main {
    //visualizer {
	GraphTracer tracer = new GraphTracer().directed(false).weighted();
	Array1DTracer tracerS = new Array1DTracer();
	LogTracer logger = new LogTracer();
	Object[][] G = new Randomize.Graph(5, 1).directed(false).weighted().create();
	//}
	public static Integer MAX_VALUE = Integer.MAX_VALUE;
	public static Integer[] S = new Integer[5]; // S[end] returns the distance from start node to end node
	
	Main() {
	    //visualizer {
		Layout.setRoot(new VerticalLayout(new Commander[] {tracer, tracerS, logger}));
		tracer.log(logger);
		tracer.set(G);
		//}
		for (int i = 0; i < G.length; i++) 
		    S[i] = MAX_VALUE;
		//visualizer {
		tracerS.set(S);
		Tracer.delay();
		//}
		//start node : s = 0~ G.length 사이 랜덤값 {
		Integer s = new Randomize.Integer(0, G.length - 1).create();
		//}
		Integer e; // e = end node
		do {
		    //end node : e = 0~ G.length 사이 랜덤값 {
		  e = new Randomize.Integer(0, G.length - 1).create();
		  //}
		} while (s == e);
		//visualizer {
		logger.println("finding the shortest path from " + Integer.toString(s) + " to " + Integer.toString(e));
		Tracer.delay();
		//}
		Dijkstra(s, e);
	}
	
	void Dijkstra(Integer start, Integer end) {
	  int minIndex = 0;
	  int minDistance;
	  boolean[] D = new boolean[5]; // D[i] indicates whether the i-th node is discovered or not
	  for (int i = 0; i < G.length; i++) D[i] = false;
	  S[start] = (int)0; // Starting node is at distance 0 from itself
	  //visualizer {
	  tracerS.depatch(start, S[start]);
	  Tracer.delay();
	  tracerS.depatch(start);
	  tracerS.select(start);
	  //}
	  int k = G.length;
	  boolean temp = (k-- != 0);
	  while (temp) {
	    // Finding a node with the shortest distance from S[minIndex]
	    minDistance = MAX_VALUE;
	    for (int i = 0; i < G.length; i++) {
	      if (S[i] < minDistance && !D[i]) {
	        minDistance = S[i];
	        minIndex = i;
	      }
	    }
	    if (minDistance == MAX_VALUE) break; // If there is no edge from current node, jump out of loop
	    D[minIndex] = true;
	    //visualizer {
	    tracerS.select(minIndex);
	    tracer.visit(minIndex);
	    Tracer.delay();
	    //}
	    // For every unvisited neighbour of current node, we check
	    // whether the path to it is shorter if going over the current node
	    for (int i = 0; i < G.length; i++) {
	    	if (G[minIndex][i] != null && S[i] > S[minIndex] + (Integer)G[minIndex][i])
	    	{
	    		S[i] = S[minIndex] + (Integer)G[minIndex][i];
	    		//visualizer {
		        tracerS.patch(i, S[i]);
		        tracer.visit(i, minIndex, S[i]);
		        Tracer.delay();
		        tracerS.depatch(i);
		        tracer.leave(i, minIndex);
		        Tracer.delay();
		        //}
	    	}
	    }
	    //visualizer {
	    tracer.leave(minIndex);
	    Tracer.delay();
	    //}
	  }
	  if (S[end] == MAX_VALUE) {
	    logger.println("there is no path from " + Integer.toString(start) +  " to " +  Integer.toString(end));
	  } else {
	    logger.println("the shortest path from " + Integer.toString(start) + " to " + Integer.toString(end) + " is " +  Integer.toString(S[end]));
	  }
	}

    public static void main(String[] args) {
        new Main();
    }
}
