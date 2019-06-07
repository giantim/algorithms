#include "algorithm-visualizer.h"
#include <iostream>

const int				MAXLENGH = /*(배열 길이 입력)*/

//visualizer{
ChartTracer				chart("ChartTracer");
Array1DTracer			tracer("Array1DTracer");
LogTracer				logger("LogTracer");
int						*D = new int[MAXLENGH];
Randomize::Array1D<int> array1D(MAXLENGH);
int						count = 0;	//무한루프 방지

void InitBubbleSort()
{
	Layout::setRoot(VerticalLayout({ chart,tracer,logger }));
	//fill: vector로 바로 뽑을 수 있도록 수정 필요할듯
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
	//참고: D가 정렬하고자 하는 배열
	//visualizer{
	InitBubbleSort();
	logger.print("original array = [");
	for (int i = 0; i < MAXLENGH - 1; i++)
	{
		logger.print(std::to_string(D[i]) + " , ");
	}
	logger.println(std::to_string(D[MAXLENGH - 1]) + " ] ");
	//}
	int N = MAXLENGH;	//최대길이 설정
	bool swapped;
	do {
		swapped = false;
		//visualizer{
		tracer.select(N - 1);
		Tracer::delay();
		//}
		for (int i = 1;/*(알맞은 조건 입력)*/; i++)
		{
			//visualizer{
			tracer.select(i);
			Tracer::delay();
			//}
			if (/*알맞은 조건 입력*/) {
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
		
		/*(N값을 알맞게 조정)*/
		count++;
		if (count > MAXLENGH*MAXLENGH) break;	//무한루프 방지
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