import org.algorithm_visualizer.*;
import java.util.*;

public class Main {
    //visualizer{
	private static ChartTracer chart = new ChartTracer();
	private static Array1DTracer tracer = new Array1DTracer();
	private static LogTracer logger = new LogTracer("Console");
	//}
	private static int sizeOfArray = /*배열 크기 입력*/
	private static Object[] D = new Randomize.Array1D(sizeOfArray).create();

	Main()
	{
	    //visualizer{
		Layout.setRoot(new VerticalLayout(new Commander[]{chart, tracer, logger}));
		tracer.set(D);
		tracer.chart(chart);
		Tracer.delay();

		logger.print("original array = ");
		for(int i =0; i < D.length; i++)
			logger.print(D[i]+" ");
        //}
		merge(0, D.length);
		for(int i =0; i < D.length; i++)
			logger.print(D[i]+" ");
	}

	void merge(int start, int end) {
		if (Math.abs(end - start) <= 1) return;
		int middle = (int) Math.ceil(((float)start + (float)end) / 2);
		
		//알맞은 값을 입력
		merge(/*?*/, /*?*/);
		merge(/*?*/, /*?*/);
		//visualizer{
		logger.println("divide left [" + start + ", " + (middle -1) + "], " + "right [" + (middle) + ", " +  (end - 1) + "]");
		//}
		mergeSort(start, middle, end);
	}

	void mergeSort(int start, int middle, int end) 
	{
		int leftSize = middle - start;
		int rightSize = end - middle;
		int maxSize = Math.max(leftSize, rightSize);
		int size = end - start;
		
        //Queue를 이용한 정렬을 위해 left right Queue 선언
		Queue<Integer> left = new LinkedList<Integer>() ;
		Queue<Integer> right = new LinkedList<Integer>() ;
		
		int i;

		for (i = 0; i < maxSize; i++) {
			if (i < leftSize) {
				left.offer( (Integer)D[/*?*/] ); //올바른 enqueue를 위한 값 입력
				//visualizer{
				tracer.select(start + i);
				logger.println("insert value into left array [" + i + "] =" + D[start + i]);
				Tracer.delay();
				//}
			}
			if (i < rightSize) {
				right.offer( (Integer)D[/*?*/] ); //올바른 enqueue를 위한 값 입력
				//visualizer{
				tracer.select(middle + i);
				logger.println("insert value into right array [" + i + "] =" + D[middle + i]);
				Tracer.delay();
				//}
			}
		}
		
		i = 0;
		while (i < size) 
		{
			if (left.size() != 0 && right.size()!= 0) 
			{
			    //left가 더 클 때
				if (left./*?*/ > right./*?*/) 
				{
					D[start + i] = right./*?*/
					logger.println("rewrite from right array [" + i + "] = " + D[start + i]);
				} 
				else 
				{
					D[start + i] = left./*?*/
					logger.println("rewrite from left array [" + i + "] = " + D[start + i]);
				}
			} 
			//left Queue 가 null 일 때
			else if (left/*?*/ != null)
			{
				D[start + i] = left/*?*/;
				logger.println("rewrite from left array [" + i + "] = " + D[start + i]);
			} 
			//right Queue 가 null 일 때
			else 
			{
				D[start + i] = right/*?*/;
				logger.println("rewrite from right array [" + i + "] = " +  D[start + i]);
			}
            //visualizer{
			tracer.deselect(start + i);
			tracer.patch(start + i, D[start + i]);
			Tracer.delay();
			tracer.depatch(start + i);
			//}
			i++;
		}
	};

	public static void main(String[] args) {
		new Main();
	}
}