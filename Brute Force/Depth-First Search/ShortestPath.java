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
        private static Object[][] graph;
        private static int s;
        private static int e;
        private static int[] D;
        private static int MAX_VALUE = 0x7fffffff;
        private static int minWeight = Integer.MAX_VALUE;
        private static int number_Of_Node = 5;
    
        Main() 
        {
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
            
            D = new int[number_Of_Node]; 
    
            for (int i = 0; i < number_Of_Node; i++)
                D[i] = 0;
    
            DFS(s, s, 0);
    
            if (minWeight == MAX_VALUE) {
                logger.println("there is no path from " + s + " to " + " e ");
            } else {
                logger.println("the shortest path from " + s + " to " + e + " is " + minWeight);
            }
        }
    
        void DFS(int node, int parent, int weight) {
            if (minWeight < weight)
                return;
    
            if (node == e) {
                //visualizer{
                tracer.visit(node, parent, weight);
                Tracer.delay();
                //}
                
                if (minWeight > weight) {
                    minWeight = weight;
                }
                
                //visualizer{
                tracer.leave(node, parent, minWeight);
                Tracer.delay();
                //}
                return;
            }
    
            D[node] = 1; 
            
            //visualizer{
            tracer.visit(node, parent, weight);
            Tracer.delay();
            //}
            for (int i = 0; i < graph[node].length; i++) {
                if ((int) graph[node][i] != 0) {
                    if (D[i] == 0) {
                        DFS(i, node, weight + (int) graph[node][i]);
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