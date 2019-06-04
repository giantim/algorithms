#include "algorithm-visualizer.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

Array2DTracer			tracer("Array2DTracer");
LogTracer				logger("LogTracer");
Randomize::Integer		integer1(0, 50);
Randomize::Integer		integer2(0, 0);
Randomize::Array1D<int>	array1D1(20, integer1);
Randomize::Array1D<int>	array1D2(20, integer2);

int D[2][20];

void InitMergeSort()
{
	Layout::setRoot(VerticalLayout({ tracer,logger }));
	array1D1.fill(D[0]);
	array1D2.fill(D[1]);
	tracer.set(D);
	Tracer::delay();
}

void copy(int mergeFrom, int mergeTo, int start, int end)
{
	int i;
	for (i = start; i < end; i++) {
		tracer.select(mergeFrom, i);
		tracer.patch(mergeTo, i, D[mergeFrom][i]);
		Tracer::delay();

		D[mergeTo][i] = D[mergeFrom][i];

		tracer.deselect(mergeFrom, i);
		tracer.depatch(mergeTo, i);
	}
}

void merge(int mergeFrom, int start, int middle, int end, int mergeTo)
{
	int i = start;
	int j = middle;
	int k;

	logger.println("merging segments [" + std::to_string(start) + ".." + std::to_string(middle)
		+ "] and [" + std::to_string(middle) + ".." + std::to_string(end) + "]");
	tracer.selectRow(mergeFrom, start, end - 1);
	Tracer::delay();
	tracer.deselectRow(mergeFrom, start, end - 1);

	for (k = start; k < end; k++) {
		if (j < end) {
			tracer.select(mergeFrom, j);
		}
		if (i < middle) {
			tracer.select(mergeFrom, i);
		}
		if (i < middle && j < end) {
			logger.println("compare index " + std::to_string(i) + " and " + std::to_string(j)
				+ ", values: " + std::to_string(D[mergeFrom][i]) + " and " + std::to_string(D[mergeFrom][j]));
			Tracer::delay();
		}

		if (i < middle && (j >= end || D[mergeFrom][i] <= D[mergeFrom][j])) {
			if (j < end) {
				logger.println("writing smaller value to output");
			}
			else {
				logger.println("copying index " + std::to_string(i) + " to output");
			}
			tracer.patch(mergeTo, k, D[mergeFrom][i]);
			Tracer::delay();
			tracer.depatch(mergeTo, k);
			tracer.deselect(mergeFrom, i);

			D[mergeTo][k] = D[mergeFrom][i];
			i += 1;
		}
		else {
			if (i < middle) {
				logger.println("writing smaller value to output");
			}
			else {
				logger.println("copying index " + std::to_string(j) +  " to output");
			}
			tracer.patch(mergeTo, k, D[mergeFrom][j]);
			Tracer::delay();
			tracer.depatch(mergeTo, k);
			tracer.deselect(mergeFrom, j);
			D[mergeTo][k] = D[mergeFrom][j];
			j += 1;
		}
	}
}

int _min(int a, int b)
{
	return a > b ? b : a;
}

void mergeSort(int start, int end) {
	if (std::abs(end - start) <= 1) return;

	int mergeFrom = 0;
	int mergeTo = 1;
	int width;
	int i;
	for (width = 1; width < end; width *= 2) {
		// visualization {
		logger.println("merging arrays of width : " + std::to_string(width) );
		// }
		for (i = 0; i < end; i += 2 * width) {
			merge(mergeFrom, i, _min(i + width, end), _min(i + 2 * width, end), mergeTo);
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

int main()
{
	InitMergeSort();
	logger.print("original array = [");
	for (int i = 0; i < 19; i++)
	{
		logger.print(std::to_string(D[0][i]) + " , ");
	}
	logger.println(std::to_string(D[0][19]) + " ] ");

	mergeSort(0, 20);

	logger.print("sorted array = [");
	for (int i = 0; i < 19; i++)
	{
		logger.print(std::to_string(D[0][i]) + " , ");
	}
	logger.println(std::to_string(D[0][19]) + " ] ");
}