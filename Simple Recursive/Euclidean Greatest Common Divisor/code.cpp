#include "algorithm-visualizer.h"
#include <iostream>
#include <vector>

//visualizer{
Array1DTracer		tracer("Euclidean Algorithm");
LogTracer			logger("LogTracer");
std::vector<int>	a;
const int			X = 465;
const int			Y = 255;

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
	InitEuclideanGreatestCommonDivisor();

	//visualizer{
	logger.println("Finding the greatest common divisor of " + std::to_string(a[0])
		+ " and " +std::to_string(a[1]));

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

	while (a[0] > 0) {
		//visualizer{
		logger.println(std::to_string(a[1]) + " % " + std::to_string(a[0]) + " = "
			+ std::to_string(a[1] % a[0]));
		logger.println("Switching a[1] with a[1]%a[0]");
		//}
		a[1] %= a[0];
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