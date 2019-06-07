#include "algorithm-visualizer.h"
#include <iostream>

const int	  ARRYSIZE = /*(배열 길이 입력)*/
//visualizer{
Array1DTracer tracer("Sequence");

void InitFibonacciSequence()
{
	Layout::setRoot(VerticalLayout({ tracer }));
}
//}

int main()
{
	// D: 피보나치 수열의 값이 순차적으로 저장될 배열
	InitFibonacciSequence();

	int D[ARRYSIZE] = { 1, 1 };
	for (int i = 2; i < ARRYSIZE; i++) {
		D[i] = 0;
	}
	//visualizer{
	tracer.set(D);
	Tracer::delay();
	//}

	for (int i = 2; i < ARRYSIZE; i++) {
		D[i] = /*(D에대한 알맞은 수식 입력)*/
		//visaulizer{
		tracer.select(i - 2, i - 1);
		Tracer::delay();
		tracer.patch(i, D[i]);
		Tracer::delay();
		tracer.depatch(i);
		tracer.deselect(i - 2, i - 1);
		//}
	}
}