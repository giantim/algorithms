import org.algorithm_visualizer.*;
import java.util.Arrays;

class Main {
    private static int sizeOfArray = /*(배열 크기 입력)*/
    private static int minValue = 0; /*(배열 최소값 입력)*/
    private static int maxValue = 9; /*(배열 최대값 입력)*/ 
    //visualizer {
	private static Array1DTracer arrayTracer = new Array1DTracer("Array");
	private static Array1DTracer countsTracer = new Array1DTracer("Counts");
	private static Array1DTracer sortedArrayTracer = new Array1DTracer("Sorted Array");
	private static Integer[] array = (Integer[]) new Randomize.Array1D(arraySize,
			new Randomize.Integer(minValue, maxValue)).create();
	//}
	private static int[] counts;
	private static int[] sortedArray;
  //private static int[] array;

	Main() {
	    //visualizer {
	    Layout.setRoot(new VerticalLayout(new Commander[] {arrayTracer,countsTracer,sortedArrayTracer }));
	    //}
		// array의 최댓값을 찾아, 최댓값의 크기를 이용하여 원소 개수를 저장할 count 배열 생성
		int max = array[0];
		for(int i =1; i < array.length; i++)
			if(array[i] > max) max = array[i];
		
		counts = new int[max+1];
		Arrays.fill(counts, 0);
		// visualize {
		arrayTracer.set(array);
		countsTracer.set(counts);
		Tracer.delay();
		// }

		// 각 수를 count 에저장
		for (int i = 0; i < array.length; i++) {
			int number = array[i];
			/*(각 수를 저장하는 식 입력)*/
			// visualize {
			arrayTracer.select(i);
			countsTracer.patch(number, counts[number]);
			Tracer.delay();
			countsTracer.depatch(number);
			arrayTracer.deselect(i);
			// }
		}

		// 누적 값 저장
		for (int i = 1; i <= max; i++) {
			/*(count 누적을 구하는 식 입력)*/
			// visualize {
			countsTracer.select(i - 1);
			countsTracer.patch(i, counts[i]);
			Tracer.delay();
			countsTracer.depatch(i);
			countsTracer.deselect(i - 1);
			// }
		}

		// create a sorted array based on the prefix sums
		sortedArray = new int[array.length];
		// visualize {
		sortedArrayTracer.set(sortedArray);
		// }
		for (int i = array.length - 1; i > 0; i--) {
			int number = array[i];
			int count = counts[/*(?)*/];
			sortedArray[count - 1] = /*(?)*/;
			// visualize {
			arrayTracer.select(i);
			countsTracer.select(number);
			sortedArrayTracer.patch(count - 1, sortedArray[count - 1]);
			Tracer.delay();
			sortedArrayTracer.depatch(count - 1);
			countsTracer.deselect(number);
			arrayTracer.deselect(i);
			// }
			counts[/*(?)*/]--;
		}
	}

	public static void main(String[] args) {
		new Main();
	}
}