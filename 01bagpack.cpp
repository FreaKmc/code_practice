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
int n, m;
int cost[501], val[501];
int num[200001];
void solve(){
	for (int i = 0; i < n;++i){
		for (int j = m; j >=0; --j){
			if (j>=cost[i])	{
				num[j] = max(num[j], num[j - cost[i]] + val[i]);
			}
		}
	}
	int res=0;
	for (int i = 0; i < m;++i){
		res = res>num[i] ? res : num[i];
	}
	cout << res;
}

int main(){
	ifs >> n >> m;
	for (int i = 0; i < n; i++){
		ifs >> cost[i] >> val[i];
	}
	solve();
	system("pause");
	return 0;
}