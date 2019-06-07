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
    
    public static void main(String[] args) 
    {
        int length = array.length;
        //visualizer{
        logTracer.printf("original array = %s\n",Arrays.toString(array));
        chartTracer.set(array);
        Layout.setRoot(new VerticalLayout(new Commander[]{chartTracer, logTracer}));
        Tracer.delay();
        //}
        boolean flag;

        for (int i = length - 1; i > 0; i--) 
        {
            flag = true;
            for (int j = 0; j < i; j++) 
            {
                //visualizer{
                chartTracer.select(j);
                chartTracer.select(j + 1);
                Tracer.delay();
                //}
                if (/*알맞은 조건*/) 
                {
                    //visualizer{
                    logTracer.printf("swap %s and %s\n",array[j],array[j + 1]);
                    //}
                    swap(/*?*/, /*?*/, array);
                    flag = false;
                }
                //visualizer{
                chartTracer.deselect(j);
                chartTracer.deselect(j + 1);
                //}
            }
            if (flag) 
            {
                break;
            }
        }
        logTracer.printf("sorted array = %s\n",Arrays.toString(array));
    }

    private static void swap(int x, int y, Integer [] array) {
        //swap
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
}