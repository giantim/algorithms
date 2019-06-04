#include <iostream>
#include <vector>
#include "algorithm-visualizer.h"

const int ARRAYSIZE = /*(�ð�ȭ �ϰ��� �ϴ� �迭 ũ�⸦ �Է�)*/

//visualize {
ChartTracer				chart("ChartTracer");
Array1DTracer			tracer("Array1DTracer");
LogTracer				logger("LogTracer");
Randomize::Integer		integer(0, ARRAYSIZE + 20);
Randomize::Array1D<int> array1D(ARRAYSIZE, integer);
int D[ARRAYSIZE];
int count = 0;		//���ѷ��� ������ ����

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
	//array		: 0~50���� ������ ���ĵ� �迭
	//element	: array ���� ã���� �ϴ� ��
	// visualize {
	count++;
	if (count > ARRAYSIZE / 2) break;
	logger.println("Using iterative binary search to find" + std::to_string(element));
	// }
	int minIndex =		/*(array�� �ּ� �ε����� ����)*/
	int maxIndex =		/*(array�� �ִ� �ε����� ����)*/
	int testElement;	//element�� ������ Ȯ���ϱ� ���� ����

	while (/*(�˸��� ����)*/)
	{
		int middleIndex = /*(middleIndex�� �˸°� ����)*/

		//middleIndex�� �ٲ㰡�鼭 testElement�� element�� ��ġ�ϴ��� Ž��
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

		if (/*(�˸��� ����)*/)
		{
			//visualize {
			logger.println("Going right.");
			// }
			/*(minIndex,maxIndex ���� �ϳ�)*/ = middleIndex + 1;
		}
		else if (/*(�˸��� ����)*/)
		{
			//visualize {
			logger.println("Going left.");
			// }
			/*(minIndex,maxIndex ���� �ϳ�)*/ = middleIndex - 1;
		}
		else
		{
			//ã���� ���
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
	Randomize::Integer randInteger(0, 14);	//0~14 ���� ���� �߻� ��ü( create() ȣ�� �� ���� ��ȯ)
	int element = D[randInteger.create()];	//D�� ���� ������ �� element�� ����
	BinarySearch(D, element);				//D �迭���� element search
}