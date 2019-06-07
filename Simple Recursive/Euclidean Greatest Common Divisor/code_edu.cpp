#include "algorithm-visualizer.h"
#include <iostream>
#include <vector>

const int			X = /*(원하는 정수값 입력)*/
const int			Y = /*(원하는 정수값 입력)*/
//visualizer{
Array1DTracer		tracer("Euclidean Algorithm");
LogTracer			logger("LogTracer");
std::vector<int>	a;
int					count = 0;//무한루프 방지


void InitEuclideanGreatestCommonDivisor()
{
	a.push_back(X);
	a.push_back(Y);
	tracer.set(a);
	Layout::setRoot(VerticalLayout({ tracer,logger }));
	Tracer::delay();
}
//}

int main()
{
	//a : GCD구할 값이 저장된 길이 2짜리 배열
	InitEuclideanGreatestCommonDivisor();

	//visualizer{
	logger.println("Finding the greatest common divisor of " + std::to_string(a[0])
		+ " and " + std::to_string(a[1]));

	logger.println("Checking if first number is at most the second number");
	//}

	if (a[0] > a[1]) {
		int tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
		//visualizer{
		logger.println("The first number is bigger than the second number. Switching the numbers.");
		tracer.set(a);
		Tracer::delay();
		//}
	}

	while (a[0] /*(알맞은 조건 입력)*/ 0) {
		//visualizer{
		logger.println(std::to_string(a[1]) + " % " + std::to_string(a[0]) + " = "
			+ std::to_string(a[1] % a[0]));
		logger.println("Switching a[1] with a[1]%a[0]");
		if (count++ > 100) {
			logger.println(" Your code has fallen into an infinite loop or Recursive call ");
			return;
		}
		//}
		a[1] /*(알맞은 연산자 입력)*/ a[0];
		//visualizer{
		tracer.patch(1, a[1]);
		Tracer::delay();
		logger.println("Now switching the two values to keep a[0] < a[1]");
		//}
		int tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
		//visualizer{
		tracer.patch(0, a[0]);
		tracer.patch(1, a[1]);
		Tracer::delay();
		tracer.depatch(0);
		tracer.depatch(1);
		//}
	}
	//visualizer{
	logger.println("The greatest common divisor is " + std::to_string(a[1]));
	//}
}