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
	vector<vector<double>> dp(m, vector<double>(n + 1, 1 - p));
	dp[0][n] = 1;
	for (int i = 1; i < m; ++i){
		double maxP = 0.0;
		for (int j = 0; j < n; ++j){
			//keep stock
			double price1 = dp[i - 1][j] / prices[i - 1][j] * prices[i][j];
			//sell other stock to buy this one
			double price2 = dp[i - 1][n] / prices[i - 1][j] * prices[i][j] * (1 - p);
			dp[i][j] = max(price1, price2);
			maxP = maxP>dp[i][j] ? maxP : dp[i][j];
		}
		//not buy stock
		dp[i][n] = max(maxP, dp[i - 1][n]);
	}
	return dp[m - 1][n];
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