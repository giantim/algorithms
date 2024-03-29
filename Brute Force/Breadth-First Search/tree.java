import org.algorithm_visualizer.*;
import java.util.*;

public class Main {
	//visualizer{
	public static GraphTracer tracer = new GraphTracer();
    public static LogTracer logger = new LogTracer();
    //}
    int G[][] = {
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

    Main() {
        //visualizer{
		tracer.log(logger);
		Layout.setRoot(new VerticalLayout(new Commander[] { tracer, logger }));
		tracer.set(G);
		tracer.layoutTree(0);
        Tracer.delay();
        //}
		BFS(0);
	}

	void BFS(Integer s) { // s = start node
        Queue<Integer> Q = new LinkedList<Integer>();
        Q.offer(s); // add start node to queue
        //visualizer{
        tracer.visit(s);
        Tracer.delay();
        //}
        while (Q.size() > 0) {
          int node = Q.poll(); // dequeue
          for (int i = 0; i < G[node].length; i++) {
            if ((int)G[node][i] != 0) { // if current node has the i-th node as a child
              Q.offer(i); // add child node to queue
              //visualizer{
              tracer.visit(i, node);
              Tracer.delay();
              //}
            }
          }
        }
      }
	
	public static void main(String[] args) {
		new Main();
	}
}