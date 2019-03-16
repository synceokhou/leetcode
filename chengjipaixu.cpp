#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#ifndef MAX
#define MAX 100
#endif



struct Student
{
	char name[100];
	int score;
	int rank;
};


bool cmp1(Student a, Student b)
{
	if (a.score > b.score)
	{
		return true;
	}
	else if(a.score == b.score)
	{
		return a.rank < b.rank;
	}
	return false;
}

bool cmp0(Student a, Student b)
{
	if (a.score < b.score)
	{
		return true;
	}
	else if(a.score == b.score)
	{
		return a.rank < b.rank;
	}
	return false;
}

Student s[1000];


int main()
{
	int n, k;
	while(scanf("%d", &n) != EOF)
	{
		scanf("%d", &k);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s %d", s[i].name, &s[i].score);
			s[i].rank = i;
		}

		if (k == 0)
		{
			sort(s, s+n, cmp1);
		}
		else
		{
			sort(s, s+n, cmp0);
		}
		
		for (int i = 0; i < n; ++i)
		{
			printf("%s %d\n", s[i].name, s[i].score);
		}

	}
	return 0;
}