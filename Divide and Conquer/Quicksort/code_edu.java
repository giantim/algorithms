import org.algorithm_visualizer.*;
import java.util.Arrays;

class Main {
    //visualizer{
    private static ChartTracer chartTracer = new ChartTracer();
    private static LogTracer logTracer = new LogTracer("Console");
    private static Array1DTracer tracer = new Array1DTracer();
    //}
    private static int sizeOfArray = /*배열 크기 입력*/
    private static int minValue = /*배열 최소값 입력*/
    private static int maxValue = /*배열 최대값 입력*/
    //array[] :sizeOfArray개의 minValue ~ maxValue 사이의 난수 값을 갖는 배열
    private static Integer [] array = (Integer[]) new Randomize.Array1D(sizeOfArray, new Randomize.Integer(minValue, maxValue)).create();

    public static void main(String[] args) {
        //visualizer{
        tracer.set(array);
        tracer.chart(chartTracer);
        Layout.setRoot(new VerticalLayout(new Commander[]{chartTracer, tracer, logTracer}));
        logTracer.printf("original array = %s\n", Arrays.toString(array));

        Tracer.delay();
        //}
        quickSort(array, 0, array.length - 1);
        //visualizer{
        logTracer.printf("sorted array = %s\n", Arrays.toString(array));
        //}
    }

    public static void quickSort(Integer[] arr, int left, int right) {
        int l, r, s;
        while (right > left) 
        {
            l = left;
            r = right;
            s = arr[left]; //pivot
            while (/*알맞은 조건*/) 
            {
                //visualizer{
                tracer.select(left);
                tracer.select(right);
                Tracer.delay();
                //}
                while (/*알맞은 조건*/) 
                {
                    //visualizer{
                    tracer.select(r);
                    Tracer.delay();
                    tracer.deselect(r);
                    //}
                    r--;
                }
                arr[l] = arr[r];
                //visualizer{
                tracer.patch(l, arr[r]);
                Tracer.delay();
                tracer.depatch(l);
                //}
                while (/*알맞은 조건*/ && /*알맞은 조건*/) 
                {
                    //visualizer{
                    tracer.select(l);
                    Tracer.delay();
                    tracer.deselect(l);
                    //}
                    l++;
                }
                arr[r] = arr[l];
                //visualizer{
                tracer.patch(r, arr[l]);
                Tracer.delay();
                tracer.depatch(r);
                tracer.deselect(left);
                tracer.deselect(right);
                //}
            }
            arr[l] = s;
            //visualizer{
            tracer.patch(l, s);
            Tracer.delay();
            tracer.depatch(l);
            //}
            quickSort(arr, left, l - 1);
            left = l + 1;
        }
    }
}
