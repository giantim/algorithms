#include "algorithm-visualizer.h"
#include <iostream>

const int				ARRAYSIZE = /*(배열 길이 입력)*/

//visualizer{
ChartTracer				chart("ChartTracer");
Array1DTracer			tracer("Array1DTracer");
LogTracer				logger("LogTracer");
Randomize::Array1D<int> array1D(ARRAYSIZE);
int						D[ARRAYSIZE];
int						count = 0; //무한 재귀호출 및 루프 방지

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
	//정렬할 배열구조를 힙으로 만드는 함수

	//visualizer{
	if (count++ > ARRAYSIZE*ARRAYSIZE*2) return;	//무한루프 방지
	//}
	int largest = root;
	int left = 2 * root + 1;
	int right = /*(알맞은 값 입력)*/
	int temp;

	if (left < size && _array[left] > _array[largest]) {
		largest = /*(알맞은 값 입력)*/
	}

	if (right <size && _array[right] > _array[largest]) {
		largest = /*(알맞은 값 입력)*/
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
		Heapify(_array, size, /*(알맞은 값 입력)*/);
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
		Heapify(_array, /*(알맞은 값 입력)*/, 0);

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
	//}
	HeapSort(D, sizeof(D) / sizeof(int));

	//visualizer{
	logger.print("Final array = [");
	for (int i = 0; i < ARRAYSIZE-1; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[ARRAYSIZE-1]) + " ] ");
	//}
}