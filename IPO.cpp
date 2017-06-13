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
#include<iterator>
#include <type_traits>
using namespace std;
#define _debug
#ifdef _debug
ifstream ifs("test.txt");
#else
istream &ifs = cin;
#endif

class Solution {
public:
	int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> p1;
		priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp1> p2;
		for (int i = 0; i < Profits.size(); ++i){
			p1.push({ Profits[i], Capital[i] });
		}
		int res=0;
		for (int i = 0; i < k; ++i){
			while (!p1.empty()&&p1.top().second<=W){
					p2.push(p1.top());
					p1.pop();
			}
			if (!p2.empty()){
				W += p2.top().first;
				p2.pop();
			}
		}
		return W;
	}
	struct Cmp{
		bool operator()(pair<int, int> l, pair<int, int> r){
			return l.second > r.second ;
		}
	};
	struct Cmp1{
		bool operator()(pair<int, int> l, pair<int, int> r){
			return l.first<r.first;
		}
	};
};

int main(){
	vector<int> p{ 1, 2, 3 }, c{ 0, 1, 1 };
	Solution s;
	cout<<s.findMaximizedCapital(2, 0, p, c);
	return 0;
}
