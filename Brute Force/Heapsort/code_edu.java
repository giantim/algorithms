import org.algorithm_visualizer.*;
import java.util.Arrays;

public class Main {
    //visualizer{
	private static ChartTracer chart = new ChartTracer();
	private static LogTracer logger = new LogTracer("Console");
	private static Array1DTracer tracer = new Array1DTracer("Array1DTracer");
	//}
	private static int sizeOfArray = /*배열 크기 입력*/
    private static int minValue = /*배열 최소값 입력*/
    private static int maxValue = /*배열 최대값 입력*/
    
	//array[] :sizeOfArray개의 minValue ~ maxValue 사이의 난수 값을 갖는 배열
    private static Integer [] array = (Integer[]) new Randomize.Array1D(sizeOfArray, new Randomize.Integer(minValue, maxValue)).create();
	Main()
	{
	    //visualizer{
		Layout.setRoot(new VerticalLayout(new Commander[]{chart, tracer, logger}));	
		tracer.set(array);
		tracer.chart(chart);
        //}
		heapSort(array, array.length);
		
		for(int i =0; i < array.length; i++)
			logger.print(array[i] + " ");
	}

	void heapSort(Integer[] array, int size) 
	{
		int i, j, temp;

		for (i = (int) (Math.ceil(size / 2) - 1); i >= 0; i--) 
		{
			heapify(array, size, i);
		}

		for (j = size - 1; j >= 0; j--) 
		{
			temp = array[0];
			array[0] = array[j];
			array[j] = temp;
            
            //visualizer{
			tracer.patch(0, array[0]);
			tracer.patch(j, array[j]);
			logger.println("Swapping elements : " + array[0] + " & " +  array[j]);
			Tracer.delay();
			tracer.depatch(0);
			tracer.depatch(j);
			tracer.select(j);
			Tracer.delay();
            //}
			heapify(array, j, 0);
            //visualizer{
			tracer.deselect(j);
			//}
		}
	}

	void heapify(Integer[] array, int size, int root) 
	{
		int largest = root;
		int left = /*알맞은 값*/
		int right = /*알맞은 값*/
		int temp;

		if (left < size && /*알맞은 조건*/)
		{
			largest = left;
		}

		if (right < size && /*알맞은 조건*/) 
		{
			largest = right;
		}

		if (largest != root) 
		{
		    //swap ( array[root], array[largest] )
			temp = /*?*/
			/*?*/ = /*?*/
			/*?*/ = /*?*/
			
            //visualizer{
			tracer.patch(root, array[root]);
			tracer.patch(largest, array[largest]);
			logger.println("Swapping elements : " + array[root] + " & " + array[largest]);
			Tracer.delay();
			tracer.depatch(root);
			tracer.depatch(largest);
            //}
			heapify(array, size, largest);
		}
	}

	public static void main(String[] args) {
		new Main();
	}
}