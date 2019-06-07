import org.algorithm_visualizer.*;
import java.util.Arrays;

public class Main {
    //visualizer {
	private static Array2DTracer tracer = new Array2DTracer();
	private static LogTracer logger = new LogTracer("Console");
	//}
	private static int sizeOfArray = /*배열의 크기 입력*/
	private static int maxValue = /*배열의 최댓값 입력*/
	private static Object[][] D = 
		{
				new Randomize.Array1D(sizeOfArray, new Randomize.Integer(0, maxValue)).create(),
				new Randomize.Array1D(sizeOfArray, new Randomize.Integer(0, 0)).create(),
		};

	Main()
	{
	    //visualizer {
		Layout.setRoot(new VerticalLayout(new Commander[]{tracer, logger}));
		tracer.set(D);
		Tracer.delay();
        //}
		mergeSort(0, D[0].length);  
		
        logger.print("sorted array = ");
        for(int i =0; i < D[0].length; i++)
            logger.print(D[0][i]+" ");
	}

	void mergeSort(int start, int end) {
		if (Math.abs(end - start) <= 1) return;
        
		int mergeFrom = 0; //
		int mergeTo = 1;   //D[0]][] < - >  D[1][] 정렬값을 주고 받기 위한 구분을 위해 선언
		int width;
		int i;
		for (width = 1; width < end; width *= 2) {
			//visualizer {
			logger.println("merging arrays of width: " + width);
			// }
			for (i = 0; i < end; i += 2 * width) {
				merge(mergeFrom, i, Math.min(i + width, end), Math.min(i + 2 * width, end), mergeTo);
			}

			mergeFrom = (mergeFrom == 0 ? 1 : 0);
			mergeTo = 1 - mergeFrom;
		}
		if (mergeFrom != 0) {
			//visualizer {
			logger.println("final copy to original");
			// }
			copy(mergeFrom, mergeTo, start, end);
		}
	}

	void merge(int mergeFrom, int start, int middle, int end, int mergeTo) {
		int i = start;
		int j = middle;
		int k;
		
		//visualizer {
		logger.println("merging segments "+ "["+start+ ".." + middle + "]and ["+middle+".." +end +"]");
		tracer.selectRow(mergeFrom, start, end - 1);
		Tracer.delay();
		tracer.deselectRow(mergeFrom, start, end - 1);
		// }

		for (k = start; k < end; k++) {
			//visualizer {
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
	       //알맞은 조건을 입력하여 merge를 수행
			if (i < /*?*/ && (j >= /*?*/ || (int)D[/*?*/][/*?*/] <= (int)D[/*?*/][/*?*/])) {
				//visualizer {
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
				D[mergeTo][k] = D[/*?*/][/*?*/];
				i += 1;
			} else {
				//visualizer {
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
				D[mergeTo][k] = D[/*?*/][/*?*/];
				j += 1;
			}
		}
	}

	void copy(int mergeFrom, int mergeTo, int start, int end) {
		int i;
		for (i = start; i < end; i++) {
			//visualizer {
			tracer.select(mergeFrom, i);
			tracer.patch(mergeTo, i, D[mergeFrom][i]);
			Tracer.delay();
			// }
			D[mergeTo][i] = D[mergeFrom][i];
			//visualizer {
			tracer.deselect(mergeFrom, i);
			tracer.depatch(mergeTo, i);
			// }
		}
	}

	public static void main(String[] args) {
		new Main();
	}
}
