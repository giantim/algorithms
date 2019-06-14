import org.algorithm_visualizer.*;
import java.util.Arrays;

public class Main {
    private static int sizeOfArray = /*(배열 크기 입력)*/
    private static int minValue = /*(배열 최소값 입력)*/
    private static int maxValue = /*(배열 최대값 입력)*/
	//visualizer {
	private static ChartTracer tracer = new ChartTracer();
	private static LogTracer logger = new LogTracer("Console");
	private static Integer[] D = (Integer[]) new Randomize.Array1D(arraySize, new Randomize.Integer(minValue, maxValue)).create();
	//}
	Main() {
	    //visualizer {
		Layout.setRoot(new VerticalLayout(new Commander[] { tracer, logger }));
		logger.printf("original array = %s\n", Arrays.toString(D));
		tracer.set(D);
		Tracer.delay();
		//}
		for (int gap = D.length/2; gap != 0; gap = gap / 2) {
			logger.println("Gap of " + gap);
			for (int i = gap; i < D.length; i++) {
				//visualizer {
				tracer.select(i);
				tracer.select(i - gap);
				Tracer.delay();
				//}
				int k = D[i]; 
				logger.println("Holding: " + k);
				int j;
				
				for (j = i; j >= gap && k < D[j - gap]; j -= gap) {
					logger.println(k + " < " + D[j - gap]);
					D[j] = D[/*(?*/];
					//visualizer {
					tracer.patch(j, D[j]);
					Tracer.delay();
					tracer.depatch(j);
					//}
				}
				int old = D[j];
				D[j] = k;
				if (old != k) {
				    //visualizer {
					tracer.patch(j, D[j]);
					Tracer.delay();
					tracer.depatch(j);
					//}
					logger.println("Swapped " + D[j] + " with " + old);
				}
				//visualizer {
				tracer.deselect(i);
				tracer.deselect(i - gap);
				//}
			}
		}
		logger.printf("sorted array = %s\n", Arrays.toString(D));
	}

	public static void main(String[] args) {
		new Main();
	}
}