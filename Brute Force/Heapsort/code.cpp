#include "algorithm-visualizer.h"
#include <iostream>

//visualizer{
const int				ARRAYSIZE = 10;
ChartTracer				chart("ChartTracer");
Array1DTracer			tracer("Array1DTracer");
LogTracer				logger("LogTracer");
Randomize::Array1D<int> array1D(ARRAYSIZE);
int						D[ARRAYSIZE];

void InitHeapSort()
{
	Layout::setRoot(VerticalLayout({ chart,tracer,logger }));
	array1D.fill(D);
	tracer.set(D);
	tracer.chart(chart);
	Tracer::delay();
}
// }

void Heapify(int _array[ARRAYSIZE], int size, int root)
{
	int largest = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	int temp;

	if (left < size && _array[left] > _array[largest]) {
		largest = left;
	}

	if (right <size && _array[right] > _array[largest]) {
		largest = right;
	}

	if (largest != root) {
		temp = _array[root];
		_array[root] = _array[largest];
		_array[largest] = temp;

		//visualizer{
		tracer.patch(root, _array[root]);
		tracer.patch(largest, _array[largest]);

		logger.println("Swapping elements : " + std::to_string(_array[root]) + " and " + std::to_string(_array[largest]));
		Tracer::delay();
		tracer.depatch(root);
		tracer.depatch(largest);
		//}
		Heapify(_array, size, largest);
	}
}

void HeapSort(int _array[ARRAYSIZE], int size)
{
	int i, j, temp;

	for (i = size / 2; i >= 0; i--)
		Heapify(_array, size, i);

	for (j = size - 1; j >= 0; j--) {
		temp = _array[0];
		_array[0] = _array[j];
		_array[j] = temp;

		//visualizer{
		tracer.patch(0, _array[0]);
		tracer.patch(j, _array[j]);
		logger.println("Swapping element : " + std::to_string(_array[0]) + " and " + std::to_string(_array[j]));
		Tracer::delay();
		tracer.depatch(0);
		tracer.depatch(j);
		tracer.select(j);
		Tracer::delay();
		//}
		Heapify(_array, j, 0);

		//visualizer{
		tracer.deselect(j);
		//}
	}
}

int main()
{
	InitHeapSort();
	//visualizer{
	logger.print("original array = [");
	for (int i = 0; i < ARRAYSIZE-1; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[ARRAYSIZE-1]) + " ] ");

	HeapSort(D, sizeof(D) / sizeof(int));

	logger.print("Final array = [");
	for (int i = 0; i < ARRAYSIZE-1; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[ARRAYSIZE-1]) + " ] ");
}