#include "algorithm-visualizer.h"
#include <iostream>


const int				ARRAYSIZE = /*(배열 길이 입력)*/
//visualizer{
ChartTracer				chart("ChartTracer");
Array1DTracer			tracer("Array1DTracer");
LogTracer				logger("LogTracer");
Randomize::Array1D<int> array1D(ARRAYSIZE);
int						D[ARRAYSIZE];
int						count = 0;	//무한루프 방지

void InitSeletionSort()
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
	InitSeletionSort();
	//visualizer{
	logger.print("original array = [");
	for (int i = 0; i < ARRAYSIZE - 1; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[ARRAYSIZE - 1]) + " ] ");
	//}

	for (int i = 0; i < sizeof(D) / sizeof(int); i++) {
		int minJ = i;
		//visualizer{
		tracer.select(i);
		Tracer::delay();
		//}
		for (int j = i + 1; j < sizeof(D) / sizeof(int); j++) {
			//visualizer{
			tracer.select(j);
			Tracer::delay();
			if (count++ > ARRAYSIZE*ARRAYSIZE*2) return;	//무한루프 방지
			//}
			if (/*(알맞은 조건 입력)*/) {
				minJ = j;
				//visualizer{
				tracer.patch(j);
				Tracer::delay();
				tracer.depatch(j);
				//}
			}
			//visualizer{
			tracer.deselect(j);
			//}
		}
		if (/*(알맞은 조건 입력)*/) {
			//visualizer{
			logger.println("swap " + std::to_string(D[i]) + " and " + std::to_string(D[minJ]));
			//}
			int temp = D[i];
			D[i] = D[minJ];
			D[minJ] = temp;
			//visualizer{
			tracer.patch(i, D[i]);
			tracer.patch(minJ, D[minJ]);
			Tracer::delay();
			tracer.depatch(i);
			tracer.depatch(minJ);
			//}
		}
		//visualizer{
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