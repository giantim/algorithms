#include "algorithm-visualizer.h"
#include <iostream>

//visualizer{
const int				ARRAYSIZE = 17;
ChartTracer				chart("ChartTracer");
Array1DTracer			tracer("Array1DTracer");
LogTracer				logger("LogTracer");
Randomize::Array1D<int> array1D(ARRAYSIZE);
int						D[ARRAYSIZE];


void InitSeletionSort()
{
	Layout::setRoot(VerticalLayout({ chart,tracer,logger }));
	array1D.fill(D);
	tracer.set(D);
	tracer.chart(chart);
	Tracer::delay();
}
//}

int main()
{
	InitSeletionSort();
	//visualizer{
	logger.print("original array = [");
	for (int i = 0; i < ARRAYSIZE-1; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[ARRAYSIZE-1]) + " ] ");
	//}

	for (int i = 0; i < sizeof(D) / sizeof(int); i++) {
		int minJ = i;
		//visualizer{
		tracer.select(i);
		Tracer::delay();
		//}
		for (int j = i + 1; j < sizeof(D) / sizeof(int); j++) {
			//visualizer{
			tracer.select(j);
			Tracer::delay();
			//}
			if (D[j] < D[minJ]) {
				minJ = j;
				//visualizer{
				tracer.patch(j);
				Tracer::delay();
				tracer.depatch(j);
				//}
			}
			//visualizer{
			tracer.deselect(j);
			//}
		}
		if (minJ != i) {
			//visualizer{
			logger.println("swap " + std::to_string(D[i]) + " and " + std::to_string(D[minJ]));
			//}
			int temp = D[i];
			D[i] = D[minJ];
			D[minJ] = temp;
			//visualizer{
			tracer.patch(i, D[i]);
			tracer.patch(minJ, D[minJ]);
			Tracer::delay();
			tracer.depatch(i);
			tracer.depatch(minJ);
			//}
		}
		//visualizer{
		tracer.deselect(i);
		//}
	}
	//visualizer{
	logger.print("sorted array = [");
	for (int i = 0; i < ARRAYSIZE-1; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[ARRAYSIZE-1]) + " ] ");
	//}
}