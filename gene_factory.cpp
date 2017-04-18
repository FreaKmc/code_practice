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

int solve(string s, int k){
	int n = s.size();
	int res = 0;
	if (2 * k <= n){
		for (int i = 0; i < k; ++i){
			if (s[i] != s[n-k+i])
				++res;
		}
	}
	else{
		int t = n - k;
		for (int i = 0; i < t; ++i){
			int count[4] = { 0 };
			int num = 0;
			for (int j = i; j < n; j += t){
				++num;
				if (s[j] == 'A')
					count[0]++;
				else if (s[j] == 'C')
					count[1]++;
				else if (s[j] == 'G')
					count[2]++;
				else if (s[j] == 'T')
					count[3]++;
			}
			int tmp = max(max(count[0], count[1]), max(count[2], count[3]));
			res += num - tmp;
		}
	}
	return res;
}

int main(){
	int n;
	ifs >> n;
	for (int i = 0; i < n; ++i){
		string s;
		ifs >> s;
		int k;
		ifs >> k;
		cout << solve(s, k) << endl;
	}
	return 0;
}