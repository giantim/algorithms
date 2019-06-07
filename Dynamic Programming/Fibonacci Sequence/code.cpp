#include "algorithm-visualizer.h"
#include <iostream>
#include <string>

Array1DTracer tracer("Sequence");

void InitFibonacciSequence()
{
	Layout::setRoot(VerticalLayout({ tracer }));
}

int main()
{
	InitFibonacciSequence();
	
	int index = 15;
	int D[15] = { 1, 1 };
	for (int i = 2; i < index; i++) {
		D[i] = 0;
	}
	tracer.set(D);
	Tracer::delay();

	for (int i = 2; i < index; i++) {
		D[i] = D[i - 2] + D[i - 1];
		tracer.select(i - 2, i - 1);
		Tracer::delay();
		tracer.patch(i, D[i]);
		Tracer::delay();
		tracer.depatch(i);
		tracer.deselect(i - 2, i - 1);
	}
}