#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>


#ifndef MAX
#define MAX 1600000
#endif

#ifndef inf
#define inf 9999999
#endif


using namespace std;



typedef pair<string, int> Node;
std::map<string, int> m;
queue<Node> q;



int bfs(string str, int len)
{
	m[str] = 1;
	q.push(Node(str, 0));
	while(q.empty() == false)
	{
		Node p = q.front();
		q.pop();
		string t = p.first;
		int step = p.second;
		if (t.find("2012") != string::npos)
		{
			return step;
		}
		else
		{
			for (int i = 0; i < len-1; ++i)
			{
				string temp = t;
				temp[i] = temp[i+1];
				temp[i+1] = t[i];
				if (m.find(temp) == m.end())
				{
					m[temp] = 1;
					q.push(Node(temp, step + 1));
				}
			}
		}
	}
	return -1;
}



int main()
{

	int n;
	int len;
	string str;
	int cnt[3];
	while(scanf("%d", &n) != EOF)
	{
		cin >> str;
		len = str.length();
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < len; ++i)
		{
			cnt[str[i]-'0']++;
		}
		while(!q.empty())
		{
			q.pop();
		}
		m.clear();

		if (cnt[0] < 1 || cnt[1] < 1 || cnt[2] < 2)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", bfs(str, len));
		}

	}
	

	return 0;
}


































