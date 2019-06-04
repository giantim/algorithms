import org.algorithm_visualizer.*;
import java.util.*;

public class Main {
	
	Array1DTracer tracer = new Array1DTracer("Sequence");
	
	Main() {
		Layout.setRoot(new VerticalLayout(new Commander[] { tracer }));
		int index = 15;
		ArrayList<Integer> D = new ArrayList<Integer>(index);
		D.add(1);
		D.add(1);
		for (int i = 2; i < index; i++) {
		  D.add(0);
		}
		tracer.set(D);
		Tracer.delay();

		for (int i = 2; i < index; i++) {
		  D.add(i, D.get(i-2) + D.get(i-1));
		  tracer.select(i - 2, i - 1);
		  Tracer.delay();
		  tracer.patch(i, D.get(i));
		  Tracer.delay();
		  tracer.depatch(i);
		  tracer.deselect(i - 2, i - 1);
		}
	}
	
	public static void main(String[] args) {
		new Main();
	}
}
