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

	int a0, a1, p, q, k;

	int a2;

	while(scanf("%d %d %d %d %d", &a0, &a1, &p, &q, &k) != EOF)
	{
		a0 = a0 % 10000;
		a1 = a1 % 10000;
		p = p % 10000;
		q = q % 10000;

		
		for (int i = 2; i <= k; ++i)
		{
			
			a2 = ((p*a1)%10000 + (q*a0)%10000) %10000;
			// printf("%d %d %d %d\n", i, a2, a1, a0);
			a0 = a1;
			a1 = a2;
		}


		if (k == 0)
		{
			printf("%d\n", a0);
		}
		else if (k == 1)
		{
			printf("%d\n", a1);
		}
		else
		{
			printf("%d\n", a2);
		}
		
	
	}


	return 0;
}








