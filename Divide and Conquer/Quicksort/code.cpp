#include "algorithm-visualizer.h"
#include <iostream>

//visualizer{
const int				ARRAYSIZE = 20;
ChartTracer				chart("ChartTracer");
Array1DTracer			tracer("Array1DTracer");
LogTracer				logger("LogTracer");
Randomize::Array1D<int> array1D(ARRAYSIZE);
int						D[ARRAYSIZE];

void InitQuickSort()
{
	Layout::setRoot(VerticalLayout({ chart,tracer,logger }));
	array1D.fill(D);
	tracer.set(D);
	tracer.chart(chart);
	Tracer::delay();
}
//}

void partition(int D[ARRAYSIZE], int low, int high)
{
	int i;
	int j;
	int s;
	while (high > low) {
		i = low;
		j = high;
		s = D[low];
		while (i < j) {
			//visualizer{
			tracer.select(high);
			tracer.select(low);
			Tracer::delay();
			//}
			while (D[j] > s) {
				//visualizer{
				tracer.select(j);
				Tracer::delay();
				tracer.deselect(j);
				//}
				j--;
			}
			D[i] = D[j];
			//visualizer{
			tracer.patch(i, D[j]);
			Tracer::delay();
			tracer.depatch(i);
			//}
			while (s >= D[i] && i < j) {
				//visualizer{
				tracer.select(i);
				Tracer::delay();
				tracer.deselect(i);
				//}
				i++;
			}
			D[j] = D[i];
			//visualizer{
			tracer.patch(j, D[i]);
			Tracer::delay();
			tracer.depatch(j);
			tracer.deselect(high);
			tracer.deselect(low);
			//}
		}
		D[i] = s;
		//visualizer{
		tracer.patch(i, s);
		Tracer::delay();
		tracer.depatch(i);
		//}
		partition(D, low, i - 1);
		low = i + 1;
	}
}

void quicksort(int D[ARRAYSIZE]) {
	partition(D, 0, ARRAYSIZE - 1);
}

int main()
{
	InitQuickSort();
	//visualizer{
	logger.print("original array = [");
	for (int i = 0; i < ARRAYSIZE-1; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[ARRAYSIZE-1]) + " ] ");
	//}
	quicksort(D);
	//visualizer{
	logger.print("sorted array = [");
	for (int i = 0; i < ARRAYSIZE-1; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[ARRAYSIZE-1]) + " ] ");
	//}
}