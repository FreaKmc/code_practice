#include<iostream>  
#include<fstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<sstream>
#include<queue>
#include<stack>
#include<unordered_set>
using namespace std;
#define _debug
#ifdef _debug
ifstream ifs("test.txt");
#else
istream &ifs = cin;
#endif

int M, N;
int val[105];
vector<int> iv[105];
int cost[105][105];

void dfs(int n,int p){
	cost[n][1] = val[n];
	for (int i = 0; i < iv[n].size(); ++i){
		if (iv[n][i]!=p){
			dfs(iv[n][i], n);
			for (int j = M; j >= 2; --j){
				for (int k = 1; k <= j-1; ++k){
					cost[n][j] = max(cost[n][j], cost[n][j - k] + cost[iv[n][i]][k]);
				}
			}
		}
	}
}

void solve(){
	dfs(1, 0);
	cout << cost[1][M] << endl;
}

int main(){
	ifs >> N >> M;
	for (int i =1; i <=N; ++i){
		ifs >> val[i];
	}
	for (int i = 0; i < N-1 ; ++i){
		int a, b;
		ifs >> a >> b;
		iv[a].push_back(b);
		iv[b].push_back(a);
	}
	solve();
	return 0;
}