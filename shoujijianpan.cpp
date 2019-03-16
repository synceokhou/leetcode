#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#ifndef MAX
#define MAX 10001
#endif

int w[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
int v[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8};

int main()
{

	char str[MAX];

	while(scanf("%s", str) != EOF)
	{
		int len = strlen(str);
		int ans = 0;
		for (int i = 0; i < len; i++)
		{
			int pos1 = str[i] - 'a';
            int pos2 = str[i-1] - 'a';
			if (i == 0) 
			{
				// printf("str[%d]=%c and w[]=%d\n", i, str[i], w[str[i] - 'a']);
				ans = w[pos1] + ans;
			}
			else if(v[pos1] == v[pos2])
			{
				// printf("str[%d]=%c and w[]=%d\n", i, str[i], w[str[i] - 'a']);
				ans = w[pos1] + ans + 2;
			}
			else
			{
				// printf("str[%d]=%c and w[]=%d\n", i, str[i], w[str[i] - 'a']);
				ans = w[pos1] + ans;
			}

		}
		printf("%d\n", ans);
	}
	return 0;
}