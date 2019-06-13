import org.algorithm_visualizer.*;
import java.util.Arrays;

public class Main {
	// visualizer {
	private static ChartTracer chart = new ChartTracer();
	private static LogTracer logger = new LogTracer("Console");
	private static Integer[] D = (Integer[]) new Randomize.Array1D(ARRAY_SIZE,
			new Randomize.Integer(ARRAY_MINVALUE, ARRAY_MAXVALUE)).sorted().create();
	private static Array1DTracer tracer = new Array1DTracer("Array1DTracer");
	// }
	private static int ARRAY_SIZE =       /*시각화 하고자 하는 배열의 크기 입력*/
	private static int ARRAY_MINVALUE =   /*배열의 최솟값 입력*/
	private static int ARRAY_MAXVALUE =   /*배열의 최댓값 입력*/
    Main() {
		// visualizer {
		Layout.setRoot(new VerticalLayout(new Commander[] { chart, tracer, logger }));
		logger.printf("original array = %s\n", Arrays.toString(D));
		tracer.set(D);
		tracer.chart(chart);
		Tracer.delay();
		// }
		// Array에서 찾고자 할 Key Value 생성{
		int element = new Randomize.Integer(0, D.length - 1).create();
		logger.println("Using iterative binary search to find " + element);
		// }
		BinarySearch(D, element);
	}
	// array : ARRAY_MINVALUE ~ ARRAY_MAXVALUE 사이 난수가 저장되어 있는 ARRAY_SIZE의 크기의 배열
	// element : ARRAY_MINVALUE ~ ARRAY_MAXVALUE 사이 랜덤으로 생성된 Key 값
	void BinarySearch(Integer[] array, int element) { 
        int minIndex = 0;
        int maxIndex = array.length - 1;
        int testElement;
    
        while (/*(알맞은 조건)*/) 
        {
            int middleIndex = /*(middleIndex를 알맞게 설정)*/
            testElement = array[middleIndex]; //배열의 중간값
            //visualizer setting {
            tracer.select(minIndex, maxIndex);
            Tracer.delay();
            tracer.patch(middleIndex);
            logger.println("Searching at index: " + middleIndex);
            Tracer.delay();
            tracer.depatch(middleIndex);
            tracer.deselect(minIndex, maxIndex);
            //}
            if (/*(알맞은 조건)*/) {
                /*(minIndex,maxIndex 둘중 하나)*/ = middleIndex + 1;
                // Key 값이 middleIndex보다 우측에 있을 때{
                logger.println("Going right.");
                //}
            } else if (/*(알맞은 조건)*/) {
                /*(minIndex,maxIndex 둘중 하나)*/ = middleIndex - 1;
                // Key 값이 middleIndex보다 좌측에 있을 때{
                logger.println("Going left.");
               //}
            } else {
                // Key 값을 찾았을 때{
                logger.println(element +" is found at position " + middleIndex);
                tracer.select(middleIndex);
                //}
                return;
            }
        }
        //Key 값을 찾지 못하였을 때{
        logger.println(element+" is not found!");
        //}
        return;
    }

	public static void main(String[] args) {
		new Main();
	}
}