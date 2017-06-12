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
#include<bitset>
#include<unordered_map>
using namespace std;
#define _debug
#ifdef _debug
ifstream ifs("test.txt");
#else
istream &ifs = cin;
#endif

class Solution {
public:
	int findMinStep(string board, string hand) {
		int bz = board.size(), hz = hand.size();
		int ans = INT_MAX;
		for (int i = 1; i < (1 << hz); ++i){
			string use;
			if (i == 3)
				cout << endl;
			for (int j = 0; j < hz; ++j){
				if (i&(j == 0 ? 1 : (1 << j)))
					use += hand[j];
			}

			if(solve(board, use,0))
				ans = ans < use.size() ? ans : use.size();
		}
		return ans == INT_MAX ? -1 : ans;
	}

	bool solve(string b,string use,int index){
		if (b.empty())
			return true;
		if (index >= use.size())
			return false;
		int k = 0;
		bool isOk = false;
		while ((k = b.find(use[index], k)) != -1){
			string tmp = b;
			tmp.insert(tmp.begin() + k, use[index]);
			check(tmp);
 			if (solve(tmp, use, index + 1))
				isOk = true;
			++k;
		}
		return isOk;
	}

	void check(string& s){
		bool isclear = false;
		while (s.size() >= 3 && !isclear){
			isclear = true;
			for (int i = 0; i <= s.size() - 3; ++i){
				if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]){
					int j = i + 3;
					while (j < s.size()){
						if (s[j] == s[i])
							++j;
						else
							break;
					}
					s.erase(s.begin() + i, s.begin() + j);
					isclear = false;
					break;
				}
			}
		}
	}

};


int main(){
	string s = "AABBBA";
	Solution ss;
	ss.findMinStep("WRYYRWWRRWW", "WYBR");
	return 0;
}
