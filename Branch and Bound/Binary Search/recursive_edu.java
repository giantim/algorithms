import org.algorithm_visualizer.*;
import java.util.Arrays;

public class Main {
    //visualizer {
	private static ChartTracer chart = new ChartTracer();
	private static LogTracer logger = new LogTracer("Console");
	private static Integer[] D = (Integer[]) new Randomize.Array1D(ARRAY_SIZE,
			new Randomize.Integer(ARRAY_MINVALUE, ARRAY_MAXVALUE)).sorted().create();
	private static Array1DTracer tracer = new Array1DTracer("Array1DTracer");

	// }
	private static int ARRAY_SIZE =       /*(시각화 하고자 하는 배열의 크기 입력)*/
	private static int ARRAY_MINVALUE =   /*(배열의 최솟값 입력)*/
	private static int ARRAY_MAXVALUE =   /*(배열의 최댓값 입력)*/
	Main() {
		//visualizer {
		Layout.setRoot(new VerticalLayout(new Commander[] { chart, tracer, logger }));
		logger.printf("original array = %s\n", Arrays.toString(D));
		tracer.set(D);
		tracer.chart(chart);
		Tracer.delay();
		// }
		//Array에서 찾고자 할 Key Value 생성 {
		int element = D[new Randomize.Integer(0, D.length - 1).create()];
		logger.println("Using iterative binary search to find " + element);
		// }
		BinarySearch(D, element, 0, D.length - 1);
	}

	void BinarySearch(Integer[] array, int element,int minIndex, int maxIndex) 
    {
        if (/*(알맞은 조건)*/) {
			    logger.println(element +" is not found!");
			    return;
		}
        int middleIndex = /*(middleIndex를 알맞게 설정)*/
		int testElement = array[middleIndex];
        //visualizer {
			tracer.select(minIndex, maxIndex);
			Tracer.delay();
			tracer.patch(middleIndex);
			logger.println("Searching at index: "+ middleIndex);
			Tracer.delay();
			tracer.depatch(middleIndex);
			tracer.deselect(minIndex, maxIndex);
            //}
        if (/*(알맞은 조건)*/) 
        {
            // Key 값이 middleIndex보다 우측에 있을 때 {
                logger.println("Going right.");
                //}
		    BinarySearch(array, element, /*알맞은 값 입력*/ , maxIndex);
		    return;
		}
        if (/*(알맞은 조건)*/) 
        {
            // Key 값이 middleIndex보다 좌측에 있을 때 {
                logger.println("Going left.");
                //}
		    BinarySearch(array, element, minIndex, /*(알맞은 값 입력)*/);
		    return;
		}
        if (/*(알맞은 조건)*/) 
        {
            // Key 값을 찾았을 때 {
			    logger.println(element+" is found at position " +middleIndex);
                tracer.select(middleIndex);
                //}
		    return;
        }
        // Key 값을 찾지 못하였을 때 {
            logger.println(element+" is not found!");
            //}
		return;
	}

	public static void main(String[] args) {
		new Main();
	}
}