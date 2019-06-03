#include "algorithm-visualizer.h"
#include <iostream>
#include <string>

ChartTracer				chart("ChartTracer");
Array1DTracer			tracer("Array1DTracer");
LogTracer				logger("LogTracer");
Randomize::Array1D<int> array1D(15);
int D[15];


void InitSeletionSort()
{
	Layout::setRoot(VerticalLayout({ chart,tracer,logger }));
	array1D.fill(D);
	tracer.set(D);
	tracer.chart(chart);
	Tracer::delay();
}

int main()
{
	InitSeletionSort();
	logger.print("original array = [");
	for (int i = 0; i < 14; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[14]) + " ] ");

	for (int i = 0; i < sizeof(D) / sizeof(int); i++) {
		int minJ = i;
		tracer.select(i);
		Tracer::delay();
		for (int j = i + 1; j < sizeof(D) / sizeof(int); j++) {
			tracer.select(j);
			Tracer::delay();
			if (D[j] < D[minJ]) {
				minJ = j;
				tracer.patch(j);
				Tracer::delay();
				tracer.depatch(j);
			}
			tracer.deselect(j);
		}
		if (minJ != i) {
			logger.println("swap " + std::to_string(D[i]) + " and " + std::to_string(D[minJ]));
			int temp = D[i];
			D[i] = D[minJ];
			D[minJ] = temp;
			tracer.patch(i, D[i]);
			tracer.patch(minJ, D[minJ]);
			Tracer::delay();
			tracer.depatch(i);
			tracer.depatch(minJ);
		}
		tracer.deselect(i);
	}
	logger.print("sorted array = [");
	for (int i = 0; i < 14; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[14]) + " ] ");
}