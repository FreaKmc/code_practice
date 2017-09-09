
class Solution {
public:
	int countDigitOne(int n) {
		vector<int> num;
		int pos = 0;
		while (n){
			num.push_back(n % 10);
			n /= 10;
			++pos;
		}
		vector<int> dp(num.size(), -1);
		return dfs(num, dp, pos - 1, 0, true);
	}

	int dfs(vector<int>& num, vector<int>& dp, int pos, int n, bool limit) {
		if (pos == -1)
			return n;
		if (!limit&&dp[pos] != -1) {
			return dp[pos];
		}
		int up = limit ? num[pos] : 9;
		int tmp = 0;
		for (int i = 0; i <= up; ++i) {
			tmp += dfs(num, dp, pos - 1, n + (i == 1), limit && i == num[pos]);
		}
		if (!limit)
			dp[pos] = tmp;
		return tmp;
	}
};