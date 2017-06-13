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
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return 0;
		int row = matrix.size(), col = matrix[0].size();
		vector<vector<int>> path(row, vector<int>(col, -1));
		
		int res = 0;
		for (int i = 0; i < row; ++i){
			for (int j = 0; j < col; ++j){
				if (path[i][j] == -1)
					res=max(res,dfs(matrix,path,i,j,row,col,-1));
			}
		}
		return res;
	}

	int dfs(vector<vector<int>>& matrix, vector<vector<int>>& path,int i,int j,int row,int col,int lastVal){
		if (i < 0 || i >= row || j < 0 || j >= col)
			return 0;
		if (matrix[i][j]>lastVal){
			if (path[i][j] != -1)
				return path[i][j];
			int left = dfs(matrix, path, i - 1, j, row, col, matrix[i][j]) + 1;
			int right = dfs(matrix, path, i +1, j, row, col, matrix[i][j]) + 1;
			int up = dfs(matrix, path, i, j-1, row, col, matrix[i][j]) + 1;
			int down = dfs(matrix, path, i, j + 1, row, col, matrix[i][j]) + 1;
			path[i][j] = max(max(left, right), max(up, down));
			return path[i][j];
		}
		return 0;
	}

};


int main(){
	vector<vector<int>> iv{ { 3, 4, 5 }, { 3, 2, 6 }, { 2, 2, 1 } };
	Solution s;
	cout<<s.longestIncreasingPath(iv);
	return 0;
}
