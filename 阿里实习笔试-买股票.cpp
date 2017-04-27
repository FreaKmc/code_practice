#include<iostream>  
#include<fstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<sstream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_set>
using namespace std;
#define _debug
#ifdef _debug
ifstream ifs("test.txt");
#else
istream &ifs = cin;
#endif

double StockGod(int n, int m, double p, const vector<vector<double>>& prices){
	double res = 1.0;
	vector<vector<double>> dp(m, vector<double>(n, (1-p)));
	for (int i = 1; i <m; ++i){
		for (int j = 0; j < n; ++j){
			for (int k = 0; k < n;++k){
				double tmp = dp[i - 1][k] / prices[i - 1][j] * prices[i][j] * (1 - p);
				//keep the same stock
				if (j == k){
					dp[i][j] = max(dp[i][j], tmp / (1 - p));
				}
				//change the stock
				else{
					dp[i][j] = max(dp[i][j], tmp);
				}
			}
			//not buy
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	for (int i = 0; i < n; ++i)
		res = res>dp[m-1][i] ? res : dp[m-1][i];
	return res;
}
/******************************½áÊøÐ´´úÂë******************************/


int main()
{
	int n = 0;
	int m = 0;
	double p = 0;
	ifs >> n >> m >> p;
	vector<vector<double>> prices;
	for (int i = 0; i < m; ++i) {
		prices.push_back(vector<double>());
		for (int j = 0; j < n; ++j) {
			double x = 0;
			ifs >> x;
			prices.back().push_back(x);
		}
	}
	double final = StockGod(n, m, p, prices);
	printf("%.1f\n", final);
	return 0;
}