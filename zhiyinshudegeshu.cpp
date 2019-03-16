#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#ifndef MAX
#define MAX 100001
#endif

int prime[MAX];
bool mark[MAX];
int primeSize;

void find()
{

	for (int i = 0; i < MAX; ++i)
	{
		mark[i] = false;
	}

	primeSize = 0;
	for (int i = 2; i < MAX; ++i)
	{
		if (mark[i] == false)
		{
			prime[primeSize++] = i;
		}
		for (int j = i*i; j < MAX; j = j + i)
		{
			mark[j] = true;
		}
	}
}



int main()
{

	find();



	int input;
	while(scanf("%d", &input) != EOF)
	{
		int ans = 0;
		int i;
		for (i = 0; i < primeSize && input > 1; ++i)
		{
			int temp = 0;
			while(input > 1 && input % prime[i] == 0)
			{
				// printf("input:%d and prime[i]:%d\n", input, prime[i]);
				temp++;
				input = input / prime[i];
			}
			ans = temp + ans;
		}
		if (i == primeSize && input != 1)
		{
			ans = ans + 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}
























