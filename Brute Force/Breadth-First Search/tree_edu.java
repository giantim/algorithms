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

  // s = start node
	void BFS(Integer s) 
	{ // BFS를 위한 Queue 선언
        Queue<Integer> Q = new LinkedList<Integer>();
        Q./*(?)*/ 
        //visualizer{
        tracer.visit(s);
        Tracer.delay();
        //}
        while (Q.size() > 0) 
        {
          int node = Q./*(?)*/ //dequeue
          
          for (int i = 0; i < G[node].length; i++) 
          {
            //현재 노드가 i노드를 child로 가진다면
            if ((int)G[/*(?)*/][/*(?)*/] != /*(?)*/)
            { 
              Q./*()*/         // add child node to queue
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