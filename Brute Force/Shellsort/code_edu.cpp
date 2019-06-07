#include "algorithm-visualizer.h"
#include <iostream>

const int				ARRAYSIZE = /*(배열 길이 입력)*/
//visualizer{
ChartTracer				chart("ChartTracer");
Array1DTracer			tracer("Array1DTracer");
LogTracer				logger("LogTracer");
Randomize::Array1D<int> array1D(ARRAYSIZE);
int						D[ARRAYSIZE];
int						count1 = 0;
int						count2 = 0;	//무한루프 방지

void InitShellSort()
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
	InitShellSort();
	//visualizer{
	logger.print("original array = [");
	for (int i = 0; i < ARRAYSIZE - 1; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[ARRAYSIZE - 1]) + " ] ");
	//}
	int N = sizeof(D) / sizeof(int);

	for (int gap = N; gap = /*(알맞은 값 입력)*/;) {
		//visualizer{
		logger.println("");
		logger.println("Gap of " + std::to_string(gap));
		//}
		for (int i = /*(알맞은 값 입력)*/; i < N; i++) {
			//visualizer{
			tracer.select(i);
			tracer.select(i - gap);
			Tracer::delay();
			if (count1++ > ARRAYSIZE*ARRAYSIZE) return;
			//}
			int k = /*(알맞은 값 입력)*/
			//visualizer{
			logger.println("Holding: " + std::to_string(k));
			//}
			int j;
			for (j = i; j /*(알맞은 조건 입력)*/ gap && k < D[j - gap]; j -= gap) {
				//visualizer{
				if (count2++ > ARRAYSIZE*ARRAYSIZE*ARRAYSIZE) return;
				logger.println(std::to_string(k) + " < " + std::to_string(D[j - gap]));
				//}
				D[j] = D[j - gap];
				//visualizer{
				tracer.patch(j, D[j]);
				Tracer::delay();
				tracer.depatch(j);
				//}
			}
			int old = /*(알맞은 값 입력)*/
			D[j] = k;
			if (old != k) {
				//visualizer{
				tracer.patch(j, D[j]);
				Tracer::delay();
				tracer.depatch(j);
				logger.println("Swapped " + std::to_string(D[j]) + " with " + std::to_string(old));
				//}
			}
			//visualizer{
			tracer.deselect(i);
			tracer.deselect(i - gap);
			//}
		}
	}
	//visualizer{
	logger.println("");
	logger.print("sorted array = [");
	for (int i = 0; i < ARRAYSIZE - 1; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[ARRAYSIZE - 1]) + " ] ");
	//}
}