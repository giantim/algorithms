import org.algorithm_visualizer.*;
import java.util.Arrays;

class Main {
    //visualizer{
	private static Array1DTracer tracer = new Array1DTracer("Euclidean Algorithm");
	private static LogTracer logger = new LogTracer("Console");
	private static int[] a = new int[2];
    //}
	public static void main(String[] args) {
	    //visualizer{
		Layout.setRoot(new VerticalLayout(new Commander[]{tracer, logger}));
		//}
		
		a[0] = /*첫 번째 값*/
		a[1] = /*두 번째 값*/
		
		//visualizer{
		tracer.set(a);
		Tracer.delay();
		logger.println("Finding the greatest common divisor of " + a[0] + " and " + a[1]);
		logger.println("Checking if first number is at most the second number");
        //}
        //작은 값을 a[0], 큰 값을 a[1]에 저장
		if (a[0] > a[1]) 
		{
		    //swap(a[0],a[1])
            int tmp = /*?*/
            /*?*/ = /*?*/
            /*?*/ = /*?*/
			//visualizer{
			logger.println("The first number is bigger than the second number. Switching the numbers.");
			tracer.set(a);
			Tracer.delay();
			//}
		}
    
        //GCD 구하기
		while (a[0] > 0) 
		{
		    //visualizer{
			logger.println(a[1]+ "%" + a[0] + " = " + (a[1] % a[0]));
			logger.println("Switching a[1] with a[1] % a[0]");
			a[1] %= a[0];
			tracer.patch(1, a[1]);
			Tracer.delay();
			logger.println("Now switching the two values to keep a[0] < a[1]");
			//}
			int tmp = /*?*/
			/*?*/ = /*?*/
			/*?*/ = /*?*/
			//visualizer{
			tracer.patch(0, a[0]);
			tracer.patch(1, a[1]);
			Tracer.delay();
			tracer.depatch(0);
			tracer.depatch(1);
			//}
		}
        //visualizer{
		logger.println("The greatest common divisor is "+ a[1]);
		//}
	}
}