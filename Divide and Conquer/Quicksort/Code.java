import org.algorithm_visualizer.*;
import java.util.Arrays;

class Main {
    //visualizer{
    private static ChartTracer chartTracer = new ChartTracer();
    private static LogTracer logTracer = new LogTracer("Console");
    private static Array1DTracer tracer = new Array1DTracer();
    //}
    private static Integer[] array = (Integer[]) new Randomize.Array1D(15, new Randomize.Integer(1, 20)).create();

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
        while (right > left) {
            l = left;
            r = right;
            s = arr[left];
            while (l < r) {
                //visualizer{
                tracer.select(left);
                tracer.select(right);
                Tracer.delay();
                //}
                while (arr[r] > s) {
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
                while (s >= arr[l] && l < r) {
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
