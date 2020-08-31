#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	const double speed = 1.0;
	const unsigned repeat_max = 10;

	double dt = 1.0;
	double time = 0.0;
	double dist = 0.0;

	for (unsigned i = 0; i < repeat_max; ++i)
	{
		dist += speed * dt;
		time += dt;

		printf("Elapsed time = %.10fs,Distance =%.10fm\n", time, dist);
		
		dt = dt * 0.5;

	}
	return 0;
}