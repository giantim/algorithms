#include "algorithm-visualizer.h"
#include <iostream>

//visualizer{
Array1DTracer tracer("Sequence");
const int	  ARRYSIZE = 16;

void InitFibonacciSequence()
{
	Layout::setRoot(VerticalLayout({ tracer }));
}
//}

int main()
{
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
		D[i] = D[i - 2] + D[i - 1];
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