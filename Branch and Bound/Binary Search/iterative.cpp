#include <iostream>
#include <vector>
#include "algorithm-visualizer.h"

//visualizer{
ChartTracer				chart("ChartTracer");
Array1DTracer			tracer("Array1DTracer");
LogTracer				logger("LogTracer");
Randomize::Integer		integer(0, 50);
Randomize::Array1D<int> array1D(15, integer);
int D[15];

void InitBinarySearch()
{
	//레이아웃 설정
	Layout::setRoot(VerticalLayout({ chart, tracer, logger }));
	array1D.sorted();
	array1D.fill(D);
	tracer.set(D);
	tracer.chart(chart);
	Tracer::delay();
}
//}

void BinarySearch(int array[15], int element)
{
	//visualizer{
	logger.println("Using iterative binary search to find" + std::to_string(element));
	//}
	int minIndex = 0;
	int maxIndex = 14;
	int testElement;

	while (minIndex <= maxIndex)
	{
		int middleIndex = (minIndex + maxIndex) / 2;
		testElement = array[middleIndex];
		//visulizer{
		tracer.select(minIndex, maxIndex);
		Tracer::delay();
		tracer.patch(middleIndex);
		logger.println("Searching at index: " + std::to_string(middleIndex));
		Tracer::delay();
		tracer.depatch(middleIndex);
		tracer.deselect(minIndex, maxIndex);
		//}
		if (testElement < element)
		{
			//visualizer{
			logger.println("Going right.");
			//}
			minIndex = middleIndex + 1;
		}
		else if (testElement > element)
		{
			//visualizer{
			logger.println("Going left.");
			//}
			maxIndex = middleIndex - 1;
		}
		else
		{
			//visualizer{
			logger.println(std::to_string(element) + "is found at position " + std::to_string(middleIndex) + "!");
			tracer.select(middleIndex);
			//}
			return;
		}
	}
	//visualizer{
	logger.println(std::to_string(element) + " is not found!");
	//}
	return;
}

int main()
{
	InitBinarySearch();
	Randomize::Integer randInteger(0, 14);
	int element = D[randInteger.create()];
	BinarySearch(D, element);
}