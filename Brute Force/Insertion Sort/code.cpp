#pragma once
#include "algorithm-visualizer.h"
#include <iostream>
#include <string>

ChartTracer chart("ChartTracer");
Array1DTracer tracer("Array1DTracer");
LogTracer logger("LogTracer");
Randomize::Array1D<int> array1D(15);
int D[15];

void InitInsertionSort()
{
	Layout::setRoot(VerticalLayout({ chart,tracer,logger }));
	array1D.fill(D);
	tracer.set(D);
	tracer.chart(chart);
	Tracer::delay();
}

int main()
{
	InitInsertionSort();
	logger.print("original array = [");
	for (int i = 0; i < 14; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[14]) + " ] ");

	for (int i = 1; i < 15; i++) {
		int key = D[i];
		logger.println("insert" + std::to_string(key));
		tracer.select(i);
		Tracer::delay();
		int j;
		for (j = i - 1; (j >= 0) && (D[j] > key); j--) {
			D[j + 1] = D[j];
			tracer.patch(j + 1, D[j + 1]);
			Tracer::delay();
			tracer.depatch(j + 1);
		}
		D[j + 1] = key;
		tracer.patch(j + 1, D[j + 1]);
		Tracer::delay();
		tracer.depatch(j + 1);
		tracer.deselect(i);
	}
	logger.print("sorted array = [");
	for (int i = 0; i < 14; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[14]) + " ] ");
}