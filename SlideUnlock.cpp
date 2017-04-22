#include<iostream>  
#include<fstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<sstream>
#include<queue>
#include<unordered_set>
using namespace std;
#define _debug
#ifdef _debug
ifstream ifs("test.txt");
#else
istream &ifs = cin;
#endif
int T, m, a[10], ans;
vector<int> mg[10];
int g[10][10];
bool used[10];
void init()
{
	memset(g, 0, sizeof(g));
	g[1][3] = g[3][1] = 2; g[1][7] = g[7][1] = 4;
	g[1][9] = g[9][1] = 5; g[2][8] = g[8][2] = 5;
	g[3][7] = g[7][3] = 5; g[4][6] = g[6][4] = 5;
	g[7][9] = g[9][7] = 8; g[3][9] = g[9][3] = 6;
}
void dfs(int s, int matching, int step)
{
	used[s] = true;
	if (matching >= m &&step >= 4)
		ans++;
	int sz = mg[s].size();
	if (sz == 1 && !used[mg[s][0]])
	{
		int u = mg[s][0];
		int v = g[s][u];
		if (v && used[v] || v == 0)
			dfs(mg[s][0], matching + 1, step + 1);
	}
	else if (sz == 2 && ((used[mg[s][0]] && !used[mg[s][1]]) || (!used[mg[s][0]] && used[mg[s][1]])))
	{
		if (!used[mg[s][0]])
		{
			int u = mg[s][0];
			int v = g[s][u];
			if (v&&used[v] || v == 0)
				dfs(mg[s][0], matching + 1, step + 1);
		}

		else
		{
			int u = mg[s][1];
			int v = g[s][u];
			if (v&&used[v] || v == 0)
				dfs(mg[s][1], matching + 1, step + 1);
		}

	}
	else if (sz == 0 || sz == 1)
	{
		for (int i = 1; i < 10; i++)
		{
			if (i == s)
				continue;
			int u = g[s][i];
			if (u && used[u] && !used[i])
			{
				dfs(i, matching, step + 1);
			}
			else if (u == 0 && !used[i])
			{
				dfs(i, matching, step + 1);
			}
		}
	}
	used[s] = false;
}
int main()
{
	ifs >> T;
	init();
	while (T--)
	{
		ifs >> m;
		int u, v;
		for (int i = 0; i < 10; i++)
			mg[i].clear();
		for (int i = 0; i < m; i++)
		{
			ifs >> u >> v;
			mg[u].push_back(v);
			mg[v].push_back(u);
		}
		memset(used, 0, sizeof(used));
		ans = 0;
		for (int i = 1; i < 10; i++)
		{
			dfs(i, 0, 1);
		}
		cout << ans << endl;
	}
	return 0;
}