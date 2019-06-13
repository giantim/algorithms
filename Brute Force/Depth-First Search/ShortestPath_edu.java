//import visualizer{
    import org.algorithm_visualizer.*;
    import org.algorithm_visualizer.Randomize.Graph;
    //}
    import java.util.*;
    
    public class Main {
        //visualizer{
        private static GraphTracer tracer;
        private static LogTracer logger;
        private static Randomize.Graph G;
        //}
        private static Object[][] graph; //인접한 노드에 대한 정보를 갖고 있는 배열
        private static int s;
        private static int e;
        private static int[] D;
        private static int MAX_VALUE = 0x7fffffff;
        private static int minWeight = Integer.MAX_VALUE;
        private static int number_Of_Node = /*(그래프의 Node 개수 입력)*/;
    
        Main() {
            //visualizer{
            tracer = new GraphTracer().directed(false).weighted();
            logger = new LogTracer();
            Layout.setRoot(new VerticalLayout(new Commander[] { tracer, logger }));
            tracer.log(logger);
            G = new Randomize.Graph(number_Of_Node, 1);
            G.directed(false).weighted(true);
            graph = G.create();
            tracer.set(graph);
            Tracer.delay();
            //}
            //start node s와 end node e 를 무작위로 결정 {
            s = new Randomize.Integer(0, number_Of_Node - 1).create(); // s = start node
            do {
                e = new Randomize.Integer(0, number_Of_Node - 1).create();
            } while (s == e);		
            
            logger.println("finding the shortest path from " + s + " to " + e);
            //}
            
            // 배열 D : Graph를 search하며 방문 유무에 대한 정보를 저장
            D = new int[number_Of_Node]; 
    
            //배열 D를 0으로 초기화    
            for (int i = 0; i < number_Of_Node; i++)
                D[i] = 0;
    
            DFS(s, s, 0);
    
            if (minWeight == MAX_VALUE)
            {
                logger.println("there is no path from " + s + " to " + " e ");
            } 
            else 
            {
                logger.println("the shortest path from " + s + " to " + e + " is " + minWeight);
            }
        }
    
        //node : 현재 노드, parent : 이전 노드, weight : 가중치
        void DFS(int node, int parent, int weight) 
        {
            if (minWeight < weight)
                return;
    
            if (node == e) 
            {
                //visualizer{
                tracer.visit(node, parent, weight);
                Tracer.delay();
                //}
                if (minWeight > /*(?)*/) 
                {
                    minWeight = /*(?)*/;
                }
                //visualizer{
                tracer.leave(node, parent, minWeight);
                Tracer.delay();
                //}
                return;
            }
            
            //현재 노드를 방문했으므로 초기화
            D[/*(?)*/] = /*(?)*/; 
            
            //visualizer{
            tracer.visit(node, parent, weight);
            Tracer.delay();
            //}
            for (int i = 0; i < graph[node].length; i++) 
            {
                if ((int) graph[node][i] != 0) 
                { 
                    // 현재 노드에서 i - 노드의 경로가 존재한다면  
                    if (D[i] == 0) 
                    { 
                        // recursively call DFS
                        DFS( /*(?)*/, /*(?)*/, /*(?)*/ + (int)/*(?)*/); 
                    }
                }
            }
    
            D[node] = 0;
            //visualizer{
            tracer.leave(node, parent, 0);
            Tracer.delay();
            //}
        }
    
        public static void main(String[] args) {
            new Main();
        }
    }