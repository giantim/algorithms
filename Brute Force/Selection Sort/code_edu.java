import org.algorithm_visualizer.*;
import java.util.Arrays;

public class Main {
    //visualizer{
    private static ChartTracer chartTracer = new ChartTracer();
    private static LogTracer logTracer = new LogTracer("Console");
    //}
    private static int sizeOfArray = /*배열 크기 입력*/
    private static int minValue = /*배열 최소값 입력*/
    private static int maxValue = /*배열 최대값 입력*/

    //array[] :sizeOfArray개의 minValue ~ maxValue 사이의 난수 값을 갖는 배열
    private static Integer [] array = (Integer[]) new Randomize.Array1D(sizeOfArray, new Randomize.Integer(minValue, maxValue)).create();

    Main()
    {
        int length = array.length;
        //visualizer{
        Layout.setRoot(new VerticalLayout(new Commander[]{chartTracer, logTracer}));
        logTracer.printf("original array = %s\n", Arrays.toString(array));
        chartTracer.set(array);
        Tracer.delay();
        //} 
        int minIndex;

        for (int i = 0; i < length; i++)
        {
            //visualizer{
            chartTracer.select(i);
            Tracer.delay();
            //}
            minIndex = i;
            for (int j = i + 1; j < length; j++)
            {
                //visualizer{
                chartTracer.select(j);
                Tracer.delay();
                //}
                if(/*알맞은 조건*/) 
                {
                    //visualizer{
                    chartTracer.patch(j, array[j]);
                    Tracer.delay();
                    chartTracer.depatch(j);
                    //}
                    minIndex = /*?*/;
                }
                //visualizer{
                chartTracer.deselect(j);
                //}
            }
            //알맞은 매개변수 입력
            swap(/*?*/,/*?*/, array);
            //visualizer{
            chartTracer.deselect(i);
            //}
        }

        logTracer.printf("sorted array = %s\n", Arrays.toString(array));
    }
    
    void swap(int x, int y, Integer[] array) {
        int temp = /*?*/
        /*?*/ = /*?*/
        /*?*/ = /*?*/
        //visualizer{
        chartTracer.patch(x, array[x]);
        chartTracer.patch(y, array[y]);
        Tracer.delay();
        chartTracer.depatch(x);
        chartTracer.depatch(y);
        //}
    }

    public static void main(String[] args) {
    	new Main();
    }
}