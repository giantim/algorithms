#include "algorithm-visualizer.h"
#include <iostream>

const int				ARRAYSIZE = /*(배열 사이즈 입력)*/
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
	while (/*(알맞은 조건 입력)*/) {
		i = low;
		j = high;
		s = D[low];
		while (i < j) {
			//visualizer{
			tracer.select(high);
			tracer.select(low);
			Tracer::delay();
			//}
			while (/*(알맞은 조건 입력)*/) {
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
			while (/*(알맞은 조건 입력)*/ && i < j) {
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