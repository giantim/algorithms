import org.algorithm_visualizer.*;
import java.util.Arrays;

public class Main 
{
	private static ChartTracer chart = new ChartTracer();
	private static LogTracer logger = new LogTracer("Console");
	private static Integer [] D = (Integer[]) new Randomize.Array1D(15, new Randomize.Integer(1, 20)).sorted().create();
	private static Array1DTracer tracer = new Array1DTracer("Array1DTracer"); 
	
	Main()
	{
		Layout.setRoot(new VerticalLayout(new Commander[]{chart,tracer, logger}));
		logger.printf("original array = %s\n", Arrays.toString(D));
		tracer.set(D);
		tracer.chart(chart);
		Tracer.delay();
		
		//Make Key Value
		int element = D[new Randomize.Integer(0, D.length - 1).create()]; 

		logger.println("Using iterative binary search to find " + element);
		
		
		BinarySearch(D, element,0, D.length-1);
	}

	void BinarySearch(Integer[] array, int element,int minIndex, int maxIndex) { // array = sorted array, element = element to be found
		 if (minIndex > maxIndex){
			    logger.println(element +" is not found!");
			    return;
		 }

			  int middleIndex = (int)Math.floor((minIndex + maxIndex) / 2);
			  int testElement = array[middleIndex];

			  tracer.select(minIndex, maxIndex);
			  Tracer.delay();
			  tracer.patch(middleIndex);
			  logger.println("Searching at index: "+ middleIndex);
			  Tracer.delay();
			  tracer.depatch(middleIndex);
			  tracer.deselect(minIndex, maxIndex);

			  if (testElement < element) {
			    logger.println("Going right.");
			    BinarySearch(array, element, middleIndex + 1, maxIndex);
			    return;
			  }

			  if (testElement > element) {
			    logger.println("Going left.");
			    BinarySearch(array, element, minIndex, middleIndex - 1);
			    return;
			  }

			  if (testElement == element) {
			    logger.println(element+" is found at position " +middleIndex);
			    tracer.select(middleIndex);
			    return;
			  }
			  logger.println(element+" is not found!");
			  return;
	
	}
	public static void main(String[] args) {
		new Main();
	}
}
