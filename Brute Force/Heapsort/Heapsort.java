import org.algorithm_visualizer.*;
import java.util.Arrays;

public class Main {

   ChartTracer chart;
   LogTracer logger;
   Integer [] array;
   Array1DTracer tracer;

   Main()
   {
      chart = new ChartTracer();
      logger = new LogTracer("Console");
      array = (Integer[]) new Randomize.Array1D(10, new Randomize.Integer(1, 20)).create();
      tracer = new Array1DTracer("Array1DTracer");
      Layout.setRoot(new VerticalLayout(new Commander[]{chart, tracer, logger}));   
      tracer.set(array);
      tracer.chart(chart);

      heapSort(array, array.length);
      for(int i =0; i < array.length; i++)
         logger.print(array[i] + " ");

   }

   void heapSort(Integer[] array, int size) {
      int i, j, temp;


      for (i = (int) (Math.ceil(size / 2) - 1); i >= 0; i--) {
         heapify(array, size, i);
      }

      for (j = size - 1; j >= 0; j--) {
         temp = array[0];
         array[0] = array[j];
         array[j] = temp;

         tracer.patch(0, array[0]);
         tracer.patch(j, array[j]);
         logger.println("Swapping elements : " + array[0] + " & " +  array[j]);
         Tracer.delay();
         tracer.depatch(0);
         tracer.depatch(j);
         tracer.select(j);
         Tracer.delay();

         heapify(array, j, 0);

         tracer.deselect(j);
      }
   }

   void heapify(Integer[] array, int size, int root) 
   {
      int largest = root;
      int left = 2 * root + 1;
      int right = 2 * root + 2;
      int temp;

      if (left < size && array[left] > array[largest]) {
         largest = left;
      }

      if (right < size && array[right] > array[largest]) {
         largest = right;
      }

      if (largest != root) {
         temp = array[root];
         array[root] = array[largest];
         array[largest] = temp;

         tracer.patch(root, array[root]);
         tracer.patch(largest, array[largest]);
         logger.println("Swapping elements : " + array[root] + " & " + array[largest]);
         Tracer.delay();
         tracer.depatch(root);
         tracer.depatch(largest);

         heapify(array, size, largest);
      }
   }

   public static void main(String[] args) {
      new Main();
   }
}