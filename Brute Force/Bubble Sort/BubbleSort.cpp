#include "algorithm-visualizer.h"
#include <string>
#include <iostream>

ChartTracer chart("ChartTracer");
Array1DTracer tracer("Array1DTracer");
LogTracer logger("LogTracer");
int* D = new int[15];
Randomize::Array1D<int> array1D(15);

void InitBubbleSort()
{
	Layout::setRoot(VerticalLayout({ chart,tracer,logger }));
	//fill: vector로 바로 뽑을 수 있도록 수정 필요할듯
	array1D.fill(D);
	std::vector<int> v(15);
	for (int i = 0; i < 15; i++)
		v[i] = D[i];
	tracer.set(v);
	tracer.chart(chart);
}

int main()
{
	InitBubbleSort();
	logger.print("original array = [");
	for (int i = 0; i < 14; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[14]) + " ] ");
	int N = 15;
	bool swapped;
	do {
		swapped = false;
		tracer.select(N - 1);
		Tracer::delay();
		for (int i = 1; i < N; i++)
		{
			tracer.select(i);
			Tracer::delay();
			if (D[i - 1] > D[i]) {
				logger.println("swap " + std::to_string(D[i - 1]) + " and " +
					std::to_string(D[i]));
				int temp = D[i - 1];
				D[i - 1] = D[i];
				D[i] = temp;
				swapped = true;
				tracer.patch(i - 1, D[i - 1]);
				tracer.patch(i, D[i]);
				Tracer::delay();
				tracer.depatch(i - 1);
				tracer.depatch(i);
			}
			tracer.deselect(i);
		}
		tracer.deselect(N - 1);
		N--;
	} while (swapped);
	logger.println("sorted array = ");
	for (int i = 0; i < 14; i++)`
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[14]) + " ] ");
}