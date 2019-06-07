#include "algorithm-visualizer.h"
#include <iostream>
#include <string>

Array1DTracer arrayTracer("Array");
Array1DTracer countsTracer("Counts");
Array1DTracer sortedArrayTracer("Sorted Array");
int N = 20;
Randomize::Integer integer(0, 9);
Randomize::Array1D<int> array1D(N, integer);
int _array[20];
int max = 9;
int counts[10] = { 0,0,0,0,0,0,0,0,0,0 };

void InitCountingSort()
{
	Layout::setRoot(VerticalLayout({ arrayTracer,countsTracer,sortedArrayTracer }));
	array1D.fill(_array);
	arrayTracer.set(_array);
	countsTracer.set(counts);
	Tracer::delay();
}

int main()
{
	InitCountingSort();
	for (int i = 0; i < N; i++) {
		int number = _array[i];
		counts[number]++;
		arrayTracer.select(i);
		countsTracer.patch(number, counts[number]);
		Tracer::delay();
		countsTracer.depatch(number);
		arrayTracer.deselect(i);
	}

	for (int i = 1; i <= max; i++) {
		counts[i] += counts[i - 1];

		countsTracer.select(i - 1);
		countsTracer.patch(i, counts[i]);
		Tracer::delay();
		countsTracer.depatch(i);
		countsTracer.deselect(i - 1);
	}

	/*잘 초기화 되는지 보자*/
	int sortedArray[20];
	for (int i = 0; i < 20; i++)
		sortedArray[i] = NULL;
	sortedArrayTracer.set(sortedArray);

	for (int i = N - 1; i >= 0; i--) {
		int number = _array[i];
		int count = counts[number];
		sortedArray[count - 1] = number;

		arrayTracer.select(i);
		countsTracer.select(number);
		sortedArrayTracer.patch(count - 1, sortedArray[count - 1]);
		Tracer::delay();
		sortedArrayTracer.depatch(count - 1);
		countsTracer.deselect(number);
		arrayTracer.deselect(i);

		counts[number]--;
	}
}