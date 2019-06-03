#include "algorithm-visualizer.h"
#include <iostream>
#include <string>

ChartTracer				chart("ChartTracer");
Array1DTracer			tracer("Array1DTracer");
LogTracer				logger("LogTracer");
Randomize::Array1D<int> array1D(15);
int D[15];

void InitShellSort()
{
	Layout::setRoot(VerticalLayout({ chart,tracer,logger }));
	array1D.fill(D);
	tracer.set(D);
	tracer.chart(chart);
	Tracer::delay();
}

int main()
{
	InitShellSort();
	logger.print("original array = [");
	for (int i = 0; i < 14; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[14]) + " ] ");

	int N = sizeof(D) / sizeof(int);

	for (int gap = N; gap = gap / 2;) {
		logger.println("");
		logger.println("Gap of " + std::to_string(gap));
		for (int i = gap; i < N; i++) {
			tracer.select(i);
			tracer.select(i - gap);
			Tracer::delay();
			int k = D[i];
			logger.println("Holding: " + std::to_string(k));
			int j;
			for (j = i; j >= gap && k < D[j - gap]; j -= gap) {
				logger.println(std::to_string(k) + " < " + std::to_string(D[j - gap]));
				D[j] = D[j - gap];
				tracer.patch(j, D[j]);
				Tracer::delay();
				tracer.depatch(j);
			}
			int old = D[j];
			D[j] = k;
			if (old != k) {
				tracer.patch(j, D[j]);
				Tracer::delay();
				tracer.depatch(j);
				logger.println("Swapped " + std::to_string(D[j]) + " with " + std::to_string(old));
			}

			tracer.deselect(i);
			tracer.deselect(i - gap);
		}
	}
	logger.println("");
	logger.print("sorted array = [");
	for (int i = 0; i < 14; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[14]) + " ] ");
}