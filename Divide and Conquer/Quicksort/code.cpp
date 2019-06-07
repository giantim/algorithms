#include "algorithm-visualizer.h"
#include <iostream>
#include <string>

ChartTracer				chart("ChartTracer");
Array1DTracer			tracer("Array1DTracer");
LogTracer				logger("LogTracer");
Randomize::Array1D<int> array1D(15);
int D[15];

void InitQuickSort()
{
	Layout::setRoot(VerticalLayout({ chart,tracer,logger }));
	array1D.fill(D);
	tracer.set(D);
	tracer.chart(chart);
	Tracer::delay();
}

void partition(int D[15], int low, int high)
{
	int i;
	int j;
	int s;
	while (high > low) {
		i = low;
		j = high;
		s = D[low];
		while (i < j) {
			tracer.select(high);
			tracer.select(low);
			Tracer::delay();
			while (D[j] > s) {
				tracer.select(j);
				Tracer::delay();
				tracer.deselect(j);
				j--;
			}
			D[i] = D[j];
			tracer.patch(i, D[j]);
			Tracer::delay();
			tracer.depatch(i);
			while (s >= D[i] && i < j) {
				tracer.select(i);
				Tracer::delay();
				tracer.deselect(i);
				i++;
			}
			D[j] = D[i];
			tracer.patch(j, D[i]);
			Tracer::delay();
			tracer.depatch(j);
			tracer.deselect(high);
			tracer.deselect(low);
		}
		D[i] = s;
		tracer.patch(i, s);
		Tracer::delay();
		tracer.depatch(i);
		partition(D, low, i - 1);
		low = i + 1;
	}
}

void quicksort(int D[15]) {
	partition(D, 0, 15 - 1);
}

int main()
{
	InitQuickSort();
	logger.print("original array = [");
	for (int i = 0; i < 14; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[14]) + " ] ");
	quicksort(D);
	logger.print("sorted array = [");
	for (int i = 0; i < 14; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[14]) + " ] ");
}