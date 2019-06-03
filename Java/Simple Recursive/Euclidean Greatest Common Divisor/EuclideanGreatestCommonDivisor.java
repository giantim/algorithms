import org.algorithm_visualizer.*;
import java.util.Arrays;

class Main {
	private static Array1DTracer tracer = new Array1DTracer("Euclidean Algorithm");
	private static LogTracer logger = new LogTracer("Console");
	private static int[] a = new int[2];

	public static void main(String[] args) {
		Layout.setRoot(new VerticalLayout(new Commander[]{tracer, logger}));
		
		a[0] = 465;
		a[1] = 255;
		tracer.set(a);
		Tracer.delay();

		logger.println("Finding the greatest common divisor of " + a[0] + " and " + a[1]);
		logger.println("Checking if first number is at most the second number");

		if (a[0] > a[1]) 
		{
			int tmp = a[0];
			a[0] = a[1];
			a[1] = tmp;
			logger.println("The first number is bigger than the second number. Switching the numbers.");
			tracer.set(a);
			Tracer.delay();
		}


		while (a[0] > 0) 
		{
			logger.println(a[1]+ "%" + a[0] + " = " + (a[1] % a[0]));
			logger.println("Switching a[1] with a[1] % a[0]");
			a[1] %= a[0];
			tracer.patch(1, a[1]);
			Tracer.delay();
			logger.println("Now switching the two values to keep a[0] < a[1]");
			int tmp = a[0];
			a[0] = a[1];
			a[1] = tmp;
			tracer.patch(0, a[0]);
			tracer.patch(1, a[1]);
			Tracer.delay();
			tracer.depatch(0);
			tracer.depatch(1);
		}

		logger.println("The greatest common divisor is "+ a[1]);
	}
}