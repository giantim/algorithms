import org.algorithm_visualizer.*;
import java.util.Arrays;

class Main {
    //visualizer{
    private static ChartTracer chartTracer = new ChartTracer();
    private static LogTracer logTracer = new LogTracer("Console");
    //}
    private static int sizeOfArray = /*(배열 크기 입력)*/
    private static int minValue = /*(배열 최소값 입력)*/
    private static int maxValue = /*(배열 최대값 입력)*/
    
    //array[] :sizeOfArray개의 minValue ~ maxValue 사이의 난수 값을 갖는 배열
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
            int j = /*(알맞은 값)*/;
            int temp = array[i];
            //visualizer{
            chartTracer.select(i);
            Tracer.delay();
            logTracer.printf("insert %s\n",temp);
            //}
            while (/*(알맞은 조건)*/)
             {
                //밀어내기
                array[j + 1] = array[j];
                //visualizer{
                chartTracer.patch(j + 1, array[j + 1]);
                Tracer.delay();
                chartTracer.depatch(j + 1);
                //}
                j--;
            }
            //다음 값 저장
            array[/*(?)*/] = /*(?)*/;
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