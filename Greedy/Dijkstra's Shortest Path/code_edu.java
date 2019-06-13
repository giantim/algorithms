import org.algorithm_visualizer.*;

public class Main {
    //visualizer {
	GraphTracer tracer = new GraphTracer().directed(false).weighted();
	Array1DTracer tracerS = new Array1DTracer();
	LogTracer logger = new LogTracer();
	Object[][] G = new Randomize.Graph(5, 1).directed(false).weighted().create();
	//}
	public static Integer MAX_VALUE = Integer.MAX_VALUE;
	public static Integer[] S = new Integer[5]; // S[end] : 시작 노드에서 끝 노드까지의 거리를 반환
	
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
	  boolean[] D = new boolean[5]; //D[i]는 i 번째 노드가 발견되었는지 여부를 나타냄
	  
	  for (int i = 0; i < G.length; i++) D[i] = false;
	  
	  S[start] = (int)0; //시작노드는 자기와의 거리가 0
	  //visualizer {
	  tracerS.depatch(start, S[start]);
	  Tracer.delay();
	  tracerS.depatch(start);
	  tracerS.select(start);
	  //}
	  int k = G.length;
	  boolean temp = (k-- != 0);
	  
	  while (temp) //S[minIndex]부터 최소거리를 가진 노드찾기
	  {     
	    minDistance = MAX_VALUE;
	    for (int i = 0; i < G.length; i++) 
	    {
	      if (/*(알맞은 조건)*/) 
	      {
	        minDistance = S[/*(?)*/];
	        minIndex = /*(?)*/;
	      }
	    }
	    
	    if (minDistance == MAX_VALUE) //현재 노드의 edge가 없으면 break
	        break; 
	        
	    D[minIndex] = true;
	    //visualizer {
	    tracerS.select(minIndex);
	    tracer.visit(minIndex);
	    Tracer.delay();
	    //}
	    
        //현재 노드의 방문하지 않은 모든 노드에 대해 현재 노드를 지나칠 때 경로가 더 짧은 지 확인
	    for (int i = 0; i < G.length; i++) {
	    	if (G[minIndex][i] != null && S[i] > S[/*(?)*/] + (Integer)G[/*(?)*/][/*(?)*/])
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
