import org.algorithm_visualizer.*;
import java.util.Arrays;

public class Main {
	private static Array2DTracer tracer = new Array2DTracer();
	private static LogTracer logger = new LogTracer("Console");
	private static Object[][] D = 
		{
				new Randomize.Array1D(20, new Randomize.Integer(0, 50)).create(),
				new Randomize.Array1D(20, new Randomize.Integer(0, 0)).create(),
		};

	Main()
	{
		Layout.setRoot(new VerticalLayout(new Commander[]{tracer, logger}));
		tracer.set(D);
		Tracer.delay();

		mergeSort(0, D[0].length);  
		
        logger.print("sorted array = ");
        for(int i =0; i < D[0].length; i++)
            logger.print(D[0][i]+" ");
	}

	void mergeSort(int start, int end) {
		if (Math.abs(end - start) <= 1) return;

		int mergeFrom = 0;
		int mergeTo = 1;
		int width;
		int i;
		for (width = 1; width < end; width *= 2) {
			// visualization {
			logger.println("merging arrays of width: " + width);
			// }
			for (i = 0; i < end; i += 2 * width) {
				merge(mergeFrom, i, Math.min(i + width, end), Math.min(i + 2 * width, end), mergeTo);
			}
			// this could be copy(mergeTo, mergeFrom, start, end);
			// but it is more effecient to swap the input arrays
			// if you did copy here, you wouldn't need the copy at the end
			mergeFrom = (mergeFrom == 0 ? 1 : 0);
			mergeTo = 1 - mergeFrom;
		}
		if (mergeFrom != 0) {
			// visualization {
			logger.println("final copy to original");
			// }
			copy(mergeFrom, mergeTo, start, end);
		}
	}

	void merge(int mergeFrom, int start, int middle, int end, int mergeTo) {
		int i = start;
		int j = middle;
		int k;
		// in an actual merge implementation, mergeFrom and mergeTo would be arrays
		// here for the ability to trace what is going on better, the arrays are D[mergeFrom] and D[mergeTo]
		// visualization {
		logger.println("merging segments "+ "["+start+ ".." + middle + "]and ["+middle+".." +end +"]");
		tracer.selectRow(mergeFrom, start, end - 1);
		Tracer.delay();
		tracer.deselectRow(mergeFrom, start, end - 1);
		// }

		for (k = start; k < end; k++) {
			// visualization {
			if (j < end) {
				tracer.select(mergeFrom, j);
			}
			if (i < middle) {
				tracer.select(mergeFrom, i);
			}
			if (i < middle && j < end) {
				logger.println("compare index "+i+ " and " +" j , values: "+ D[mergeFrom][i] + " and " + D[mergeFrom][j]);
				Tracer.delay();
			}
			// }

			if (i < middle && (j >= end || (int)D[mergeFrom][i] <= (int)D[mergeFrom][j])) {
				// visualization {
				if (j < end) {
					logger.println("writing smaller value to output");
				} else {
					logger.println("copying index "+i+" to output");
				}
				tracer.patch(mergeTo, k, D[mergeFrom][i]);
				Tracer.delay();
				tracer.depatch(mergeTo, k);
				tracer.deselect(mergeFrom, i);
				// }

				D[mergeTo][k] = D[mergeFrom][i];
				i += 1;
			} else {
				// visualization {
				if (i < middle) {
					logger.println("writing smaller value to output");
				} else {
					logger.println("copying index "+ j +" to output");
				}
				tracer.patch(mergeTo, k, D[mergeFrom][j]);
				Tracer.delay();
				tracer.depatch(mergeTo, k);
				tracer.deselect(mergeFrom, j);
				// }

				D[mergeTo][k] = D[mergeFrom][j];
				j += 1;
			}
		}
	}

	void copy(int mergeFrom, int mergeTo, int start, int end) {
		int i;
		for (i = start; i < end; i++) {
			// visualization {
			tracer.select(mergeFrom, i);
			tracer.patch(mergeTo, i, D[mergeFrom][i]);
			Tracer.delay();
			// }

			D[mergeTo][i] = D[mergeFrom][i];

			// visualization {
			tracer.deselect(mergeFrom, i);
			tracer.depatch(mergeTo, i);
			// }
		}
	}

	public static void main(String[] args) {
		new Main();
	}
}
