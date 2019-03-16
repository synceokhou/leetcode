#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>


#ifndef MAX
#define MAX 10000000
#endif

#ifndef inf
#define inf 9999999
#endif

int min(int a, int b)
{
	return a < b ? a : b;
}


int dp[10005];



int main()
{

	int m, n;
	int w[1005], v[1005];

	while(scanf("%d", &m) != EOF)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &w[i]);
			v[i] = 1;
		}

		for (int i = 1; i < 10005; ++i)
		{
			dp[i] = inf;
		}

		
		for (int i = 1; i <= n; ++i)
		{
			for (int j = m; j >= w[i] ; j--)
			{

				dp[j] = min(dp[j], dp[j - w[i]] + v[i]);

			}
		}
		if (dp[m] > 20)
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n", dp[m]);
		}
		
	}
	

	return 0;
}


































