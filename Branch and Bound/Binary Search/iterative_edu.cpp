#include <iostream>
#include <vector>
#include "algorithm-visualizer.h"

const int ARRAYSIZE = /*(시각화 하고자 하는 배열 크기를 입력)*/
int						D[ARRAYSIZE]; //정렬 대상이 되는 배열
//visualize {
ChartTracer				chart("ChartTracer");
Array1DTracer			tracer("Array1DTracer");
LogTracer				logger("LogTracer");
Randomize::Integer		integer(0, ARRAYSIZE + 20);
Randomize::Array1D<int> array1D(ARRAYSIZE, integer);
int						count = 0;		//무한루프 방지

void InitBinarySearch()
{
	Layout::setRoot(VerticalLayout({ chart, tracer, logger }));
	array1D.sorted();
	array1D.fill(D);
	tracer.set(D);
	tracer.chart(chart);
	Tracer::delay();
}
// }

void BinarySearch(int array[15], int element)
{
	// visualize {
	count++;
	if (count > ARRAYSIZE / 2) return;
	logger.println("Using iterative binary search to find" + std::to_string(element));
	// }
	int minIndex =		/*(array의 최소 인덱스를 설정)*/
	int maxIndex =		/*(array의 최대 인덱스를 설정)*/
	int testElement;	//element와 같은지 확인하기 위한 변수

	while (/*(알맞은 조건)*/)
	{
		int middleIndex = /*(middleIndex를 알맞게 설정)*/

		//middleIndex를 바꿔가면서 testElement가 element와 일치하는지 탐색
		testElement = array[middleIndex];

		//visualize {
		tracer.select(minIndex, maxIndex);
		Tracer::delay();
		tracer.patch(middleIndex);
		logger.println("Searching at index: " + std::to_string(middleIndex));
		Tracer::delay();
		tracer.depatch(middleIndex);
		tracer.deselect(minIndex, maxIndex);
		// }

		if (/*(알맞은 조건)*/)
		{
			//visualize {
			logger.println("Going right.");
			// }
			/*(minIndex,maxIndex 둘중 하나)*/ = middleIndex + 1;
		}
		else if (/*(알맞은 조건)*/)
		{
			//visualize {
			logger.println("Going left.");
			// }
			/*(minIndex,maxIndex 둘중 하나)*/ = middleIndex - 1;
		}
		else
		{
			//찾았을 경우
			//visualize {
			logger.println(std::to_string(element) + "is found at position " + std::to_string(middleIndex) + "!");
			tracer.select(middleIndex);
			// }
			return;
		}
	}
	//visualize {
	logger.println(std::to_string(element) + " is not found!");
	// }
	return;
}

int main()
{
	//visualize {
	InitBinarySearch();
	//}
	Randomize::Integer randInteger(0, 14);	//0~14 사이 난수 발생 객체( create() 호출 시 난수 반환)
	int element = D[randInteger.create()];	//D의 값중 임의의 값 element로 선택
	BinarySearch(D, element);				//D 배열에서 element search
}