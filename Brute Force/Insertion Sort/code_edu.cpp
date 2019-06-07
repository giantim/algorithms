#include "algorithm-visualizer.h"
#include <iostream>


const int				ARRAYSIZE = /*(배열 길이 입력)*/
//visualizer{
ChartTracer				chart("ChartTracer");
Array1DTracer			tracer("Array1DTracer");
LogTracer				logger("LogTracer");
Randomize::Array1D<int> array1D(ARRAYSIZE);
int						D[ARRAYSIZE];
int						count = 0;//무한루프 방지

void InitInsertionSort()
{
	Layout::setRoot(VerticalLayout({ chart,tracer,logger }));
	array1D.fill(D);
	tracer.set(D);
	tracer.chart(chart);
	Tracer::delay();
}
//}

int main()
{
	InitInsertionSort();
	//visualizer{
	logger.print("original array = [");
	for (int i = 0; i < ARRAYSIZE - 1; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[ARRAYSIZE - 1]) + " ] ");
	//}

	for (int i = 1; i < ARRAYSIZE; i++) {
		int key = D[i];
		//visualizer{
		logger.println("insert" + std::to_string(key));
		tracer.select(i);
		Tracer::delay();
		//}
		int j;
		for (j = i - 1; (j >= 0) && (D[j] /*(알맞은 조건 입력)*/ key); j--) {
			D[j + 1] = D[j];
			//visualizer{
			tracer.patch(j + 1, D[j + 1]);
			Tracer::delay();
			tracer.depatch(j + 1);
			if (count++ > ARRAYSIZE*ARRAYSIZE * 2) return;	//무한루프 방지
			//}
		}
		D[j + 1] = /*(알맞은 값 입력)*/
		//visualizer{
		tracer.patch(j + 1, D[j + 1]);
		Tracer::delay();
		tracer.depatch(j + 1);
		tracer.deselect(i);
		//}
	}
	//visualizer{
	logger.print("sorted array = [");
	for (int i = 0; i < ARRAYSIZE - 1; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[ARRAYSIZE - 1]) + " ] ");
	//}
}