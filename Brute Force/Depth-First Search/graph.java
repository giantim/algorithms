import org.algorithm_visualizer.*;
import java.util.*;

class NodeData
{
	//각각의 노드는 이전 탐색한 노드의 정보와 현재 노드의 정보를 갖고 있음
	int node;
	int prev;
	public NodeData(int node, int prev)
	{
		this.node = node;
		this.prev = prev;
	}
}

public class Main {
	//visualizer{
	static private GraphTracer graphTracer;
	static private Array1DTracer visitedTracer;
	static private LogTracer logger;
	static private Randomize.Graph G;
	//}
	static private Object[][] graph;
	static private String[] visited;
	static private NodeData temp;
	static private int number_Of_Node = 8;
	Main() {
		//visualizer{
		graphTracer = new GraphTracer().directed(false).weighted();
		logger = new LogTracer();
		visitedTracer = new Array1DTracer();
		G = new Randomize.Graph(number_Of_Node, .3);
		Layout.setRoot(new VerticalLayout(new Commander[] {graphTracer,visitedTracer, logger}));
		graphTracer.log(logger);
		G.directed(false).weighted(true);
		graph = G.create();
		graphTracer.set(graph);
		Tracer.delay();
		//}

		DFSExplore();
		
		boolean check = true;
		
 		for (int i = 0; i < visited.length; i++){
 			if(visited[i] != "T")
 				check = false;
 		}
 		
		if (check){
			logger.println("The Graph is CONNECTED");
		}else{
			logger.println("The Graph is NOT CONNECTED");
		}
	}

	void DFSExplore(){
		Stack<NodeData> stack = new Stack<NodeData>() ;
		stack.push( new NodeData(0,-1) );
		visited = new String[number_Of_Node];
		
		for (int i = 0; i < visited.length; i++)
			visited[i] = "F";
		
		visitedTracer.set(visited);

		while (stack.size() > 0){
			temp = stack.pop();
			int node = temp.node;
			int prev = temp.prev;
			
			if (visited [node ] == "F"){
				//visualizer{
				Tracer.delay();
				//}
				visited[ node ] = "T";
				//visualizer{
				visitedTracer.patch( node, visited[node]);
				//}

				if (prev != -1 && (int)graph[node][prev] != 0){
					//visualizer{
					graphTracer.visit(node, prev);
					Tracer.delay();
					//}
				}else{
				    //visualizer{
					graphTracer.visit(node);
					Tracer.delay();
					//}
				}

				for (int i = 0; i < graph.length; i++){
					if ((int)graph[node][i] != 0){
						stack.push(new NodeData(i, node));
					}
				}
			}
		}
	}

	public static void main(String[] args) {
		new Main();
	}
}