#include "algorithm-visualizer.h"
#include <iostream>


//visualizer{
const int				ARRAYSIZE = 20;
const int				max = 9;
Array1DTracer			arrayTracer("Array");
Array1DTracer			countsTracer("Counts");
Array1DTracer			sortedArrayTracer("Sorted Array");
Randomize::Integer		integer(0, max);
Randomize::Array1D<int> array1D(ARRAYSIZE, integer);
int						_array[ARRAYSIZE];
int						counts[max + 1];

void InitCountingSort()
{
	Layout::setRoot(VerticalLayout({ arrayTracer,countsTracer,sortedArrayTracer }));
	array1D.fill(_array);
	arrayTracer.set(_array);
	countsTracer.set(counts);
	Tracer::delay();
	for (int i = 0; i < max; i++)
		counts[i] = 0;
}
//}

int main()
{
	InitCountingSort();
	for (int i = 0; i < ARRAYSIZE; i++) {
		int number = _array[i];
		counts[number]++;
		//visualizer{
		arrayTracer.select(i);
		countsTracer.patch(number, counts[number]);
		Tracer::delay();
		countsTracer.depatch(number);
		arrayTracer.deselect(i);
		//}
	}

	for (int i = 1; i <= max; i++) {
		counts[i] += counts[i - 1];

		//visualizer{
		countsTracer.select(i - 1);
		countsTracer.patch(i, counts[i]);
		Tracer::delay();
		countsTracer.depatch(i);
		countsTracer.deselect(i - 1);
		//}
	}

	int sortedArray[ARRAYSIZE];
	for (int i = 0; i < ARRAYSIZE; i++)
		sortedArray[i] = NULL;
	//visualizer{
	sortedArrayTracer.set(sortedArray);
	//}

	for (int i = ARRAYSIZE - 1; i >= 0; i--) {
		int number = _array[i];
		int count = counts[number];
		sortedArray[count - 1] = number;

		//visualizer{
		arrayTracer.select(i);
		countsTracer.select(number);
		sortedArrayTracer.patch(count - 1, sortedArray[count - 1]);
		Tracer::delay();
		sortedArrayTracer.depatch(count - 1);
		countsTracer.deselect(number);
		arrayTracer.deselect(i);
		//}
		counts[number]--;
	}
}