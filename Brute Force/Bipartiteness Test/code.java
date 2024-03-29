import org.algorithm_visualizer.*;
import java.util.*;

public class Main {
    //visualizer{
    private static GraphTracer tracer;
	private static Array1DTracer colorsTracer;
	private static LogTracer logger;
    //}
	int G[][] = {
			{0, 1, 0, 1, 1},
			{1, 0, 1, 0, 0},
			{0, 1, 0, 1, 0},
			{1, 0, 1, 0, 0}, // <-- replace latest 0 with 1 to make G not biparted
			{1, 0, 0, 0, 0},
	};
	
	Main() {
	    //visualizer{    
		tracer = new GraphTracer().directed(false);
		logger = new LogTracer();
		tracer.log(logger);
		tracer.set(G);
		colorsTracer = new Array1DTracer("Colors");
		Layout.setRoot(new VerticalLayout(new Commander[] {tracer, logger, colorsTracer}));
		Tracer.delay();
		//}
		BFSCheckBipartiteness(0);
	}
	
	void BFSCheckBipartiteness(int s)
	{
		Queue<Integer> Q = new LinkedList<Integer>() ;
		// Create a new matrix to set colors (0,1)
		int[] colors = new int[G.length]; 
		
		for (int _i = 0; _i < G.length; _i++) 
			colors[_i] = -1;
		//visualizer{
		colorsTracer.set(colors);
        //}
		colors[s] = 1;
		//visualizer{
		colorsTracer.patch(s, 1);
        //}
		Q.offer(s); // add start node to queue

		while (Q.size()> 0) {
			int node =Q.poll(); // dequeue
			//visualizer{
			tracer.visit(node);
			Tracer.delay();
            //}
			for (int i = 0; i < G[node].length; i++) {
				if (G[node][i] == 1)
				{
					if (colors[i] == -1) 
					{
						colors[i] = 1 - colors[node];
						//visualizer{
						colorsTracer.patch(i, 1 - colors[node]);
                        //}
						Q.offer(i);
						//visualizer{
						tracer.visit(i, node);
						Tracer.delay();
						//}
					} 
					else if (colors[i] == colors[node])
					{
						logger.println("Graph is not biparted");
						return;
					}
				}
			}
		}
		logger.println("Graph is biparted");
		return;
	}
		
	public static void main(String[] args) {
		new Main();
	}
}