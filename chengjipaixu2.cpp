#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#ifndef MAX
#define MAX 100001
#endif

struct Student
{
	int xuehao;
	int score;

	bool operator < (const Student &rhs) const
	{
		if (score < rhs.score)
		{
			return true;
		}
		else if (score == rhs.score)
		{
			return xuehao < rhs.xuehao;
		}
		return false;
	}

} s[MAX];

int main()
{
	int geshu;
	scanf("%d", &geshu);

	for (int i = 0; i < geshu; ++i)
	{
		scanf("%d %d", &s[i].xuehao, &s[i].score);

	}

	sort(s, s + geshu);

	for (int i = 0; i < geshu; ++i)
	{
		printf("%d %d\n", s[i].xuehao, s[i].score);
	}


	return 0;
}

















