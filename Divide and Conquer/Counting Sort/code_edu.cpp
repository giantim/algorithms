#include "algorithm-visualizer.h"
#include <iostream>

const int				ARRAYSIZE = /*(배열 길이 입력)*/
const int				max = /*(0~max 사이의 난수로 배열 초기화-max 값 입력)*/
//visualizer{
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
	//_array		: 정렬하고자 하는 배열
	//counts		: _array의 각 원소의 갯수를 저장할 배열
	//sortedArray	: 정렬된 _array가 들어갈 배열
	InitCountingSort();
	for (int i = 0; i < ARRAYSIZE; i++) {
		int number = /*(알맞은 값 입력)*/
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
		counts[i] += /*(알맞은 값 입력)*/

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

		/*(counts[number]값을 알맞게 변경)*/
	}
}