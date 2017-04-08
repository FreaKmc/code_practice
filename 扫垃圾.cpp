#include<iostream>  
#include<fstream>
#include<algorithm>
#include <numeric>
#include <limits>
//#include<functional>
//#include<set>
#include<vector>
//#include<bitset>
using namespace std;
#define _debug
#ifdef _debug
ifstream ifs("test.txt");
#else
istream &ifs = cin;
#endif

int n, m, q;
int dp[1001][1<<10];
int w[1001];
bool isok[1 << 10];

void init(){
	for (int i = 0; i < (1 << m); ++i){
		int val = i, cnt = 0;
		while (val>0){
			cnt+=(val&1);
			val >>= 1;
		}
		isok[i] = (cnt <= q);
	}
}

void solve(){
	memset(dp, -1, sizeof(dp));
	memset(dp[0], 0, sizeof(dp[0]));
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j < (1 << m); ++j){
			if (dp[i - 1][j] != -1){		
				int s0 = ((1 << m) - 1)&(j<<1);
				int s1 = ((j << 1) | 1)&((1 << m) - 1);
				dp[i][s0] = max(dp[i][s0], dp[i - 1][j]);
				if (isok[s1]){
					dp[i][s1] = max(dp[i][s1], dp[i - 1][j]+w[i]);
				}
			}
		}
	}
	int res = 0;
	for (int i = 0; i < (1 << m); ++i)
		res = max(res, dp[n][i]);

	cout << res << endl;
}

int main() {
	ifs >> n >> m >> q;
	for (int i = 1; i <=n; i++)
		ifs >> w[i];
	init();
	solve();
	system("pause");
	return 0;

}