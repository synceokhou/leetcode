#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#ifndef MAX
#define MAX 100001
#endif



int main()
{
	double x0, y0, z0, x1, y1, z1;

	double radus, v;

	while(scanf("%lf %lf %lf %lf %lf %lf", &x0, &y0, &z0, &x1, &y1, &z1) != EOF)
	{
		radus = sqrt((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1) + (z0-z1)*(z0-z1));

		v = 4 * acos(-1) * radus * radus * radus / 3;

		printf("%.3lf %.3lf\n", radus, v);

	}


	return 0;
}

















