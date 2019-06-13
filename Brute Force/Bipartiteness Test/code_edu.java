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
	};   // 배열 graph의 원소는 0과 -1로 구성되어 있고,
                         // garph[i][j] = 1 : i 노드와 j 노드가 서로 인접해 있다.
                         //             = 0 :                        인접해 있지 않다.
	
	
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
	    //BFS를 위한 Queue 선언
		Queue<Integer> Q = new LinkedList<Integer>() ;
		
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
		//Q 에 시작 노드를 inqueue
		Q./*(?)*/;

		while (Q.size()> 0) 
		{
			int node = Q./*(?)*/; // dequeue
			//visualizer{
			tracer.visit(node);
			Tracer.delay();
            //}
			for (int i = 0; i < G[node].length; i++) 
			{
				if (G[node][i] == 1)
				{
					if (colors[i] == -1) 
					{
						colors[i] = 1 - colors[node];
						//visualizer{
						colorsTracer.patch(i, 1 - colors[node]);
                        //}
						
						Q./*(?)*/;
						
						//visualizer{
						tracer.visit(i, node);
						Tracer.delay();
						//}
					} 
					//그래프가 biparted 하지 않을 때
					else if (/*(알맞은 조건)*/)
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