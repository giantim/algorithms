import org.algorithm_visualizer.*;
import org.algorithm_visualizer.Randomize.Graph;
import java.util.*;

public class Main {
    //visualizer{
	private static GraphTracer tracer;
	private static LogTracer logger;
	private static Randomize.Graph G;
	//}
	private static Object[][] graph;
	private static int number_Of_Node = /*노드 개수 입력*/;
	private static int s;
	private static int e;
	private static int MAX_VALUE = 0x7fffffff;
	private static int minWeight;
	
	Main() {
	    //visualizer{
		tracer = new GraphTracer().directed(false).weighted();
		logger = new LogTracer();
		Layout.setRoot(new VerticalLayout(new Commander[] {tracer, logger}));
		tracer.log(logger);
		//}
		
		//graph[i][j] != 0  : i 노드와 j 노드 는 인접해 있고, 0이 아닌 가중치 값을 가짐
		//            == 0 :  i 노드와 j 노드 는 인접하지 않음
		//graph 생성{ 
		G = new Randomize.Graph(number_Of_Node, 1);
		G.directed(false).weighted(true);
		graph = G.create();
		tracer.set(graph);
		Tracer.delay();
		//}
		
		//start node 와 end node 무작위 생성{
		s = new Randomize.Integer(0, number_Of_Node - 1).create();
		do 
		{
		  e = new Randomize.Integer(0, number_Of_Node - 1).create();
		} while (s == e);
		logger.println("finding the shortest path from " +  s + " to " + e);
		//}
		
		minWeight = BFS(s);
		
		if (minWeight == MAX_VALUE){
		  logger.println("there is no path from " +  s + " to " + e);
		} else {
		  logger.println("the shortest path from " + s + " to "  + e + " is " + minWeight);
		}
	}

	int BFS(Integer s)
	{
		// W[i] : 시작노드에서 i노드 까지 최단 경로 길이를 저장
		int[] W = new int[number_Of_Node];
		//BFS를 위한 Queue 선언
		Queue<Integer> Q = new LinkedList<Integer>() ;
		
		//W[i]를 Integer 최대 값으로 초기화
		for (int i = 0; i < number_Of_Node; i++) 
		{
			W[i] = Integer.MAX_VALUE;
			//visualizer{
			tracer.updateNode(i, Integer.MAX_VALUE);
			//}
		}
		W[s] = 0;
		
		//시작 노드를 Queue에 넣는다
		Q./*(?)*/       
		
		//visualizer{
		tracer.visit(s, null , 0);
		Tracer.delay();
		//}
		while (Q.size() > 0) 
		{
			int node = /*(?)*/; 
			for (int i = 0; i < graph[node].length; i++)
			{
			    //현재 노드로 부터 i 노드 까지의 path가 존재한다면
				if ((int)graph[node][i] != 0) 
				{ 
				    //이전 최단 경로 값보다 현재 경로 값이 작다면
					if (W[i] > (W[node] + (int)/*(?)*/)
					{ 
						W[i] = W[node] + (int)/*(?)*/; // update the length of the shortest path
						
						Q./*(?)*/         // add child node to queue
						//visualizer{
						tracer.visit(i, node, W[i]);
						Tracer.delay();
						//}
					}
				}
			}
		}
		return W[e];
	}

	public static void main(String[] args) {
		new Main();
	}
}