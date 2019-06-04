import org.algorithm_visualizer.*;
import java.util.Arrays;

public class Main {
	private static ChartTracer chart = new ChartTracer();
	private static LogTracer logger = new LogTracer("Console");
	private static Integer[] D = (Integer[]) new Randomize.Array1D(15, new Randomize.Integer(1, 20)).sorted().create();
	private static Array1DTracer tracer = new Array1DTracer("Array1DTracer");

	Main() {
		Layout.setRoot(new VerticalLayout(new Commander[] { chart, tracer, logger }));
		logger.printf("original array = %s\n", Arrays.toString(D));
		tracer.set(D);
		tracer.chart(chart);
		Tracer.delay();

		// Make Key Value
		int element = new Randomize.Integer(0, D.length - 1).create();

		logger.println("Using iterative binary search to find " + element);

		BinarySearch(D, element);
	}

	void BinarySearch(Integer[] array, int element) { // array = sorted array, element = element to be found
		int minIndex = 0;
		int maxIndex = array.length - 1;
		int testElement;

		while (minIndex <= maxIndex) {

			int middleIndex = (int) Math.floor((minIndex + maxIndex) / 2);
			testElement = array[middleIndex];

			tracer.select(minIndex, maxIndex);
			Tracer.delay();
			tracer.patch(middleIndex);
			logger.println("Searching at index: " + middleIndex);
			Tracer.delay();
			tracer.depatch(middleIndex);
			tracer.deselect(minIndex, maxIndex);

			if (testElement < element) {
				logger.println("Going right.");
				minIndex = middleIndex + 1;
			} else if (testElement > element) {
				logger.println("Going left.");
				maxIndex = middleIndex - 1;
			} else {
				logger.println(element + " is found at position " + middleIndex);
				tracer.select(middleIndex);

				return;
			}
		}
		logger.println(element + " is not found!");
		return;
	}

	public static void main(String[] args) {
		new Main();
	}
}
