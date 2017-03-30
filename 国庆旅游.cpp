#include<iostream>  
#include<fstream>
//#include<algorithm>
//#include<set>
#include<vector>
#include<bitset>
using namespace std;
#define _debug
#ifdef _debug
ifstream ifs("test.txt");
#else
istream &ifs = cin;
#endif

int city[101][101];
vector<int> u[101];
int seq[101];
int curNum,m,isOk;

bitset<101> hasChild[102];

void getChild(int cur,int fa){
	hasChild[cur][cur] = 1;

	for (int i = 0; i < (int)u[cur].size(); ++i)
	{
		int v = u[cur][i];
		if (v==fa)
		{
			continue;
		}
		getChild(v, cur);
		hasChild[cur] |= hasChild[v];
	}

}
void travel(int cur, int fa){
	if (curNum < m&&cur == seq[curNum])
	{
		curNum++;
	}

	if (curNum == m)
	{
		isOk = 1;
		return;
	}

	while (curNum < m){
		int curIndex = curNum;
		int nextId = seq[curNum];
		for (int i = 0; i < u[cur].size(); ++i)
		{
			int v = u[cur][i];
			
			if (v == fa)
			{
				continue;
			}

			if (hasChild[v][nextId] && city[cur][v])
			{
				city[cur][v] = 0;
				travel(v, cur);
			}
		}
		if (curIndex == curNum)
		{
			break;
		}
	}

}
void solve()
{
	int q;
	ifs >> q;
	int n = q - 1;
	while (n--)
	{
		int a, b;
		ifs >> a >> b;
		u[a].push_back(b);
		u[b].push_back(a);
		city[a][b] =city[b][a]= 1;
	}
	ifs >> m;

	for(int j = 0; j < m;j++)
	{
		int a;
		ifs >> a;
		seq[j] = a;
	}
	getChild(1,- 1);
	travel(1, -1);
	if (isOk)
	{
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;

}

int main()
{
	int n;
	ifs >> n;
	while (n--)
	{
		for (int i = 1; i <= 101;i++)
		{
			u[i].clear();
			hasChild[i].reset();
		}
		memset(city, 0, sizeof(city));
		memset(seq, 0, sizeof(seq));
		isOk = 0;
		curNum = 0;
		solve();
	}
	system("pause");
	return 0;
}