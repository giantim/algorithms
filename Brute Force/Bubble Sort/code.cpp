#include "algorithm-visualizer.h"
#include <iostream>

//visualizer{
const int				MAXLENGH = 15;
ChartTracer				chart("ChartTracer");
Array1DTracer			tracer("Array1DTracer");
LogTracer				logger("LogTracer");
int						*D = new int[MAXLENGH];
Randomize::Array1D<int> array1D(MAXLENGH);

void InitBubbleSort()
{
	Layout::setRoot(VerticalLayout({ chart,tracer,logger }));
	array1D.fill(D);
	std::vector<int> v(MAXLENGH);
	for (int i = 0; i < MAXLENGH; i++)
		v[i] = D[i];
	tracer.set(v);
	tracer.chart(chart);
}
//}

int main()
{
	//visualizer{
	InitBubbleSort();
	logger.print("original array = [");
	for (int i = 0; i < MAXLENGH - 1; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[MAXLENGH - 1]) + " ] ");
	//}
	int N = MAXLENGH;	
	bool swapped;
	do {
		swapped = false;
		//visualizer{
		tracer.select(N - 1);
		Tracer::delay();
		//}
		for (int i = 1; i < N; i++)
		{
			//visualizer{
			tracer.select(i);
			Tracer::delay();
			//}
			if (D[i - 1] > D[i]) {
				//visualizer{
				logger.println("swap " + std::to_string(D[i - 1]) + " and " +
					std::to_string(D[i]));
				//}
				int temp = D[i - 1];
				D[i - 1] = D[i];
				D[i] = temp;
				swapped = true;
				//visualizer{
				tracer.patch(i - 1, D[i - 1]);
				tracer.patch(i, D[i]);
				Tracer::delay();
				tracer.depatch(i - 1);
				tracer.depatch(i);
				//}
			}
			//visualizer{
			tracer.deselect(i);
			//}
		}
		//visualizer{
		tracer.deselect(N - 1);
		//}
		N--;
	} while (swapped);
	//visualizer{
	logger.println("sorted array = ");
	//}
	for (int i = 0; i < MAXLENGH - 1; i++)
	{
		//visualizer{
		logger.print(std::to_string(D[i]) + " , ");
		//}
	}
	//visualizer{
	logger.println(std::to_string(D[MAXLENGH - 1]) + " ] ");
	//}
}