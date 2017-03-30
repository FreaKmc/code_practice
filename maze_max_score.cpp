#include<iostream>  
#include<fstream>
#include<algorithm>
using namespace std;
#define _debug
#ifdef _debug
ifstream ifs("test.txt");
#else
istream &ifs = cin;
#endif
int m;
int reward[101][101];
int best[101][101];

void solve(){
	int tmp = 0;
	for (int i = 0; i < m; ++i){
		tmp += reward[i][0];
		best[i][0] = tmp;
	}

	if (m>1)
		best[1][1] = reward[0][0] + reward[1][1];
	
	for (int i = 2; i < m; ++i){
		for (int j = 1; j <= i; ++j){
			int sum = 0;
			if (j==i){
				 sum = best[i - 1][j - 1] + reward[i][j];
			}
			else{
				sum = max(best[i - 1][j], best[i - 1][j - 1]) + reward[i][j];
			}
			best[i][j] = best[i][j]>sum ? best[i][j] : sum;
		}
	}
	int res = 0;
	for (int i = 0; i < m;++i)
	{
		res = res>best[m-1][i] ? res : best[m-1][i];
	}
	cout << res;
}

int main(){
	ifs >> m;
	for (int i = 0; i < m; ++i){
		for (int j = 0; j <=i; ++j)
			ifs>>reward[i][j];
	}
	solve();
	return 0;
}