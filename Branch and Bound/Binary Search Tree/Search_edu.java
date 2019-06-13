import org.algorithm_visualizer.*;

public class Main {
    
	int G[][] = { 
	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 	// G[i][j] 는 i 노드에서 j 노드로의 edge가 존재하는지 유무
	  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},    // 즉, G의 인접행렬
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
    
	int T[][] = { 	// T행렬은 그래프 G의 각 노드들의 연관관계를 정의한 배열
	  {-1, -1},     // ex) T[i] = {j, k} : i-노드는 J 왼쪽 자손과, k 오른쪽 자손을 갖는다.
	  {0, 2},       // -1 일 때는 자손이 없음을 의미
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
		bst(key, 5, null); //root node를 5로 set
	}
    
	void bst(int item, int node, Integer parent) 
	{ // node = current node , parent = previous node
	  //visualizer {
	  tracer.visit(node, parent);
	  Tracer.delay();
	  //}
	  if (/*(알맞은 조건)*/) { // key 탐색
	    logger.println(" Match Found ");
	  }
	  else if (/*(알맞은 조건)*/) 
	  { //key가 현재 노드값 보다 작을 때
	    if (T[node][/*(?)*/] == -1) 
	    {
	      logger.println(" Not Found ");
	    }
	    else 
	    {
	      bst(item, T[node][/*(?)*/], /*(?)*/);
	    }
	  } 
	  else 
	  { //key가 현재 노드값 보다 클때
	    if (T[node][/*(?)*/] == -1) 
	    {
	      logger.println(" Not Found ");
	    }
	    else 
	    {
	      bst(item, T[node][/*(?)*/], /*(?)*/);
	    }
	  }
	}

	public static void main(String[] args) {
		new Main();
	}
}