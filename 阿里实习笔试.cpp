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
//5
//6
//0 1
//1 3
//1 2
//2 3
//2 4
//3 4

void dfs(vector < vector < int > > edges,int cur,int fa,vector<int> &count,int n,vector<int> path,int& num){
	for (int i = 0; i < n - 1; i++){ 
		if (cur == 0){
			num++;
			for (auto c : path)
				count[c]++;
			return;
		}
		if (edges[cur][i]){
			for (auto c : path){
				if (i == c)
					return;
			}
			edges[cur][i] = 0;
			path.push_back(i);
			dfs(edges, i, cur, count, n, path,num);
			path.pop_back();
		}
	}
}
vector < int > Joint(int n, vector < vector < int > > edges) {
	vector<int> count(n + 1, 0);
	vector<int> path{n-1};
	vector<int> res;
	int num = 0;
	dfs(edges, n - 1, n - 1, count, n, path, num);
	for (int i = 0; i < n - 1;i++)
	{
		if (count[i] == num)
			res.push_back(i + 1);
	}
    return res;
}

int main() {
	vector < int > res;

	int _n;
	ifs >> _n;
	//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector< vector < int > > _edges;
	for (int i = 0; i < _n; ++i) {
		_edges.push_back(vector<int>());
		for (int j = 0; j < _n; ++j) {
			_edges.back().push_back(0);
		}
	}
	int _m = 0;
	ifs >> _m;
	for (int i = 0; i < _m; ++i) {
		int a = 0;
		int b = 0;
		ifs >> a >> b;
		_edges[a][b] = 1;
		_edges[b][a] = 1;
	}

	res = Joint(_n, _edges);
	for (int res_i = 0; res_i < res.size(); res_i++) {
		cout << res[res_i] << ' ';
	}
	cout << endl;

	return 0;

}