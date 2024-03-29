import org.algorithm_visualizer.*;
import java.util.Arrays;

class Main {
    //visualizer{
    private static ChartTracer chartTracer = new ChartTracer();
    private static LogTracer logTracer = new LogTracer("Console");
    //}
    private static int sizeOfArray = 15;
    private static int minValue = 1;
    private static int maxValue = 20;
    private static Integer [] array = (Integer[]) new Randomize.Array1D(sizeOfArray, new Randomize.Integer(minValue, maxValue)).create();

    public static void main(String[] args) {
        int length = array.length;
        //visualizer{
        Layout.setRoot(new VerticalLayout(new Commander[]{chartTracer, logTracer}));
        logTracer.printf("original array = %s\n", Arrays.toString(array));
        chartTracer.set(array);
        Tracer.delay();
        //}
        for (int i = 1; i < length; i++) 
        {
            int j = i - 1;
            int temp = array[i];
            //visualizer{
            chartTracer.select(i);
            Tracer.delay();
            logTracer.printf("insert %s\n",temp);
            //}
            while (j >= 0 && array[j] > temp)
             {
                array[j + 1] = array[j];
                //visualizer{
                chartTracer.patch(j + 1, array[j + 1]);
                Tracer.delay();
                chartTracer.depatch(j + 1);
                //}
                j--;
            }
            array[j + 1] = temp;
            //visualizer{
            chartTracer.patch(j + 1, temp);
            Tracer.delay();
            chartTracer.depatch(j + 1);
            chartTracer.deselect(i);
            //}
        }
        logTracer.printf("sorted array = %s\n",Arrays.toString(array));
    }
}
