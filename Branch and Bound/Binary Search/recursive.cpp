#include "algorithm-visualizer.h"
#include <iostream>


//visualizer{
const int				ARRAYSIZE = 15;
int						D[ARRAYSIZE];
ChartTracer				chart("ChartTracer");
Array1DTracer			tracer("Array1DTracer");
LogTracer				logger("LogTracer");
Randomize::Integer		integer(0, 50);
Randomize::Array1D<int> array1d(ARRAYSIZE, integer);



void InitBinarySearch_recursive()
{
	Layout::setRoot(VerticalLayout({ chart,tracer,logger }));
	array1d.sorted();
	array1d.fill(D);
	tracer.set(D);
	tracer.chart(chart);
	Tracer::delay();
}
//}

bool BinarySearch(int _array[ARRAYSIZE], int element, int minIndex, int maxIndex)
{
	if (minIndex > maxIndex) {
		//visualizer{
		logger.println(std::to_string(element) + " is not found!");
		//}
		return -1;
	}
	int middleIndex = (minIndex + maxIndex) / 2;
	int testElement = _array[middleIndex];

	//visualizer{
	tracer.select(minIndex, maxIndex);
	Tracer::delay();
	tracer.patch(middleIndex);
	logger.println("Searching at index : " + std::to_string(middleIndex));
	Tracer::delay();
	tracer.depatch(middleIndex);
	tracer.deselect(minIndex, maxIndex);
	//}

	if (testElement < element) {
		//visualizer{
		logger.println("Going right.");
		//}
		return BinarySearch(_array, element, middleIndex + 1, maxIndex);
	}

	if (testElement > element) {
		//visualizer{
		logger.println("Going left.");
		//}
		return BinarySearch(_array, element, minIndex, middleIndex - 1);
	}

	if (testElement == element) {
		//visualizer{
		logger.println(std::to_string(element) + " is found at position "
			+ std::to_string(middleIndex));
		tracer.select(middleIndex);
		//}
		return middleIndex;
	}
	//visualizer{
	logger.println(std::to_string(element) + " is not found!");
	//}
	return -1;
}

int main()
{
	InitBinarySearch_recursive();
	Randomize::Integer i(0, sizeof(D) / sizeof(int) - 1);
	int element = D[i.create()];
	//visualizer{
	logger.println("Using binary search to find " + std::to_string(element));
	//}
	BinarySearch(D, element, 0, sizeof(D) / sizeof(int) - 1);
}