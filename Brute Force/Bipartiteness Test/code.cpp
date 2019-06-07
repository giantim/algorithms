#include "algorithm-visualizer.h"
#include <iostream>
#include <vector>
#include <queue>

//visualizer{
int G[5][5] = {
	{0, 1, 0, 1, 1},
	{1, 0, 1, 0, 0},
	{0, 1, 0, 1, 0},
	{1, 0, 1, 0, 0}, // <-- replace latest 0 with 1 to make G not biparted
	{1, 0, 0, 0, 0},
};

GraphTracer		tracer("GraphTracer");
LogTracer		logger("LogTracer");
Array1DTracer	colorsTracer("Colors");

void InitBipartitenessTest()
{
	tracer.directed(false);
	tracer.log(logger);
	tracer.set(G);
	Layout::setRoot(VerticalLayout({ tracer,logger,colorsTracer }));
}
//}visualizer

bool BFSCheckBipartiteness(int s)
{
	std::queue<int> Q;

	std::vector<int> Colors(sizeof(G) / sizeof(G[0]));
	for (int _i = 0; _i < sizeof(G) / sizeof(G[0]); _i++) Colors[_i] = -1;
	colorsTracer.set(Colors);

	Colors[s] = 1;
	colorsTracer.patch(s, 1);

	Q.push(s);

	while (Q.size() > 0)
	{
		int node = Q.front(); Q.pop();
		//visualizer{
		tracer.visit(node);
		Tracer::delay();
		//}

		for (int i = 0; i < sizeof(G[node]) / sizeof(int); i++)
		{
			if (G[node][i]) {
				if (Colors[i] == -1) {
					Colors[i] = 1 - Colors[node];
					colorsTracer.patch(i, 1 - Colors[node]);

					Q.push(i);
					tracer.visit(i, node);
					//visualizer{
					Tracer::delay();
					//}
				}
				else if (Colors[i] == Colors[node]) {
					//visualizer{
					logger.println("Graph is not bipated");
					//}
					return false;
				}
			}
		}
	}
	//visualizer{
	logger.println("Graph is biparted");
	//}
	return true;
}

int main()
{
	InitBipartitenessTest();
	BFSCheckBipartiteness(0);
}