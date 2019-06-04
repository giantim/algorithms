import org.algorithm_visualizer.*;
import java.util.*;

public class Main {
	private static ChartTracer chart = new ChartTracer();
	private static Array1DTracer tracer = new Array1DTracer();
	private static LogTracer logger = new LogTracer("Console");
	private static Object[] D = new Randomize.Array1D(15).create();

	Main()
	{
		Layout.setRoot(new VerticalLayout(new Commander[]{chart, tracer, logger}));
		tracer.set(D);
		tracer.chart(chart);
		Tracer.delay();

		logger.print("original array = ");
		for(int i =0; i < D.length; i++)
			logger.print(D[i]+" ");

		merge(0, D.length);

		for(int i =0; i < D.length; i++)
			logger.print(D[i]+" ");
	}


	void merge(int start, int end) {
		if (Math.abs(end - start) <= 1) return;
		int middle = (int) Math.ceil(((float)start + (float)end) / 2);
		
		merge(start, middle);
		merge(middle, end);
		
		logger.println("divide left [" + start + ", " + (middle -1) + "], " + "right [" + (middle) + ", " +  (end - 1) + "]");
		mergeSort(start, middle, end);
	}

	void mergeSort(int start, int middle, int end) 
	{
		int leftSize = middle - start;
		int rightSize = end - middle;
		int maxSize = Math.max(leftSize, rightSize);
		int size = end - start;

		Queue<Integer> left = new LinkedList<Integer>() ;
		Queue<Integer> right = new LinkedList<Integer>() ;
		
		int i;

		for (i = 0; i < maxSize; i++) {
			if (i < leftSize) {
				left.offer( (Integer)D[start + i] );
				tracer.select(start + i);
				logger.println("insert value into left array [" + i + "] =" + D[start + i]);
				Tracer.delay();
			}
			if (i < rightSize) {
				right.offer( (Integer)D[middle + i] );
				tracer.select(middle + i);
				logger.println("insert value into right array [" + i + "] =" + D[middle + i]);
				Tracer.delay();
			}
		}
		
		i = 0;
		while (i < size) 
		{
			if (left.size() != 0 && right.size()!= 0) 
			{
				if (left.peek() > right.peek()) 
				{
					D[start + i] = right.poll();
					logger.println("rewrite from right array [" + i + "] = " + D[start + i]);
				} 
				else 
				{
					D[start + i] = left.poll();
					logger.println("rewrite from left array [" + i + "] = " + D[start + i]);
				}
			} 
			else if (left.peek() != null)
			{
				D[start + i] = left.poll();
				logger.println("rewrite from left array [" + i + "] = " + D[start + i]);
			} 
			else 
			{
				D[start + i] = right.poll();
				logger.println("rewrite from right array [" + i + "] = " +  D[start + i]);
			}

			tracer.deselect(start + i);
			tracer.patch(start + i, D[start + i]);
			Tracer.delay();
			tracer.depatch(start + i);
			i++;
		}
	};

	public static void main(String[] args) {
		new Main();
	}
}
