#include<iostream>  
#include<fstream>
#include<algorithm>
#include<vector>
#include<functional>
#include<unordered_map>
#include<queue>
#include<string>
#include<set>
#include<sstream>
#include<deque>
#include<stack>
#include<mutex>
#include<condition_variable>
#include<iomanip>
#include<map>
#include <numeric>
//#include<map>
//#include<set>
#include<unordered_set>
//#include<bitset>
#include<assert.h>
//#include<iterator>
//#include <type_traits>
//#include<windows.h>

using namespace std;


//class Solution {
//public:
//	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//		int vis[55][55] = {0};
//		int row = image.size();
//		if (row == 0)
//			return image;
//		int col = image[0].size();
//
//		queue<pair<int, int>> q;
//		int color = image[sr][sc];
//		image[sr][sc] = newColor;
//		q.push({ sr, sc });
//
//		int x[4] = { 0, 1, 0, -1 };
//		int y[4] = { 1, 0, -1, 0 };
//		while (!q.empty()) {
//			auto tmp = q.front();
//			q.pop();
//			for (int i = 0; i < 4; ++i) {
//				int nx = tmp.first + x[i], ny = tmp.second + y[i];
//				if (nx >= 0 && nx < row&&ny >= 0 && ny < col&&vis[nx][ny] == 0 && image[nx][ny] == color) {
//					image[nx][ny] = newColor;
//					vis[nx][ny] = 1;
//					q.push({ nx, ny });
//				}
//			}
//		}
//		return image;
//	}
//};


//class Solution {
//public:
//	bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
//		if (words1.size() != words2.size())
//			return false;
//		map<string, set<string>> mp;
//		for (int i = 0; i < pairs.size(); ++i) {
//			mp[pairs[i].first].insert(pairs[i].second);
//			mp[pairs[i].second].insert(pairs[i].first);
//		}
//
//		for (int i = 0; i < words1.size(); ++i) {
//			if (words1[i]==words2[i])
//				continue;
//			if (mp[words1[i]].find(words2[i]) == mp[words1[i]].end())
//				return false;
//		}
//		return true;
//	}
//};
//
//class Solution {
//public:
//	vector<int> asteroidCollision(vector<int>& asteroids) {
//		if (asteroids.size() == 1)
//			return asteroids;
//		vector<int> res,left;
//		for (int i = 0; i < asteroids.size(); ++i) {
//			if (asteroids[i]>0) {
//				left.push_back(asteroids[i]);
//			}
//			else {
//				int j = left.size() - 1;
//				while (j >= 0 && left[j] < abs(asteroids[i])) {
//					--j;
//					left.pop_back();
//				}
//				if (j >= 0 && left[j] == abs(asteroids[i]))
//					left.pop_back();
//				else if(left.empty()){
//					res.push_back(asteroids[i]);
//				}
//			}
//		}
//		if (!left.empty()){
//			for (int i = 0; i < left.size(); ++i) {
//				res.push_back(left[i]);
//			}
//		}
//		return res;
//	}
//};

class Solution {
public:
	int evaluate(string expression) {
		if (expression.size() == 0)
			return 0;
		return solve(expression.substr(1, expression.size() - 2));
	}

	int decode(vector<string> sv) {
		if (sv[0] == "add") {

		}
		else if (sv[0] == "mult") {

		}
		else if (sv[0] == "let") {

		}
		return 1;
	}

	int solve(string s) {
		vector<string> sv;
		int j = 0,t = 0;
		s.push_back(' ');
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == ' '){
				sv.push_back(s.substr(j, i - j));

				j = i+1;
			}
			else if (s[i] == '(') {
				int k = i + 1;
				t++;
				i++;
				while (i<s.size() && t>0) {
					if (s[i] == '(')
						t++;
					else if (s[i] == ')')
						t--;
				}
				sv.push_back(to_string(solve(s.substr(k,i-k))));
			}
		}
		return decode(sv);
	}

	map<string, int> mp;
	map<string, int> need;
};

int main() {

	return 0;
}
