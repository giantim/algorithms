#include "algorithm-visualizer.h"
#include <iostream>
#include <string>
#include <vector>

Array1DTracer		tracer("Euclidean Algorithm");
std::vector<int>	a;
LogTracer			logger("LogTracer");

void InitEuclideanGreatestCommonDivisor()
{
	a.push_back(465);
	a.push_back(255);
	tracer.set(a);
	Layout::setRoot(VerticalLayout({ tracer,logger }));
	Tracer::delay();
}

int main()
{
	InitEuclideanGreatestCommonDivisor();

	logger.println("Finding the greatest common divisor of " + std::to_string(a[0])
		+ " and " +std::to_string(a[1]));

	logger.println("Checking if first number is at most the second number");

	if (a[0] > a[1]) {
		int tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
		logger.println("The first number is bigger than the second number. Switching the numbers.");
		tracer.set(a);
		Tracer::delay();
	}

	while (a[0] > 0) {
		logger.println(std::to_string(a[1]) + " % " + std::to_string(a[0]) + " = "
			+ std::to_string(a[1] % a[0]));
		logger.println("Switching a[1] with a[1]%a[0]");
		a[1] %= a[0];
		tracer.patch(1, a[1]);
		Tracer::delay();
		logger.println("Now switching the two values to keep a[0] < a[1]");
		int tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
		tracer.patch(0, a[0]);
		tracer.patch(1, a[1]);
		Tracer::delay();
		tracer.depatch(0);
		tracer.depatch(1);
	}

	logger.println("The greatest common divisor is " + std::to_string(a[1]));
}