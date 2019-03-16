#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#ifndef MAX
#define MAX 100001
#endif

int arr[1001];
int prime[MAX];
bool mark[MAX];
int primeSize;

void findPrime()
{
	for (int i = 0; i < MAX; ++i)
	{
		mark[i] = false;
	}
	primeSize = 0;
	for (int i = 2; i < MAX; ++i)
	{
		if (mark[i] == true)
		{
			continue;
		}
		else
		{
			prime[primeSize++] = i;
		}
		for (int j = i*i; j < MAX; j = j+i)
		{
			mark[j] = true;
		}
	}
}



int main()
{
	findPrime();

	int n, k, temp, ans;
	while(scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &arr[i]);
		}
		
		for (int i = 0; i < n; ++i)
		{
			ans = 1;
			int j;
			for (j = 0; j < primeSize && arr[i] > 1; ++j)
			{
				temp = 0;
				while(arr[i] % prime[j] == 0 && arr[i] > 1)
				{
					temp++;
					arr[i] = arr[i] / prime[j];
				}
				ans = ans * (temp + 1);
				
			}
			if (j == primeSize && arr[i] > 1)
			{
				ans = ans * 2;
			}
			printf("%d\n", ans);
		}



	}
	return 0;
}

















