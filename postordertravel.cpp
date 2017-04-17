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
string preorder, inorder;

string solve(int l, int r, int ll, int rr){
	if (l == r || ll == rr)
		return preorder.substr(l,1);
	if (r<l || rr<ll)
		return "";
	int mid = find(inorder.begin(), inorder.end(), preorder[l]) - inorder.begin();
	int ls = mid-ll, rs = rr - mid;
	return solve(l + 1, l + ls, ll, ll + ls-1) + solve(l + 1 + ls, r, ll+ls + 1, rr) + preorder[l];
}

int main(){
	cin >> preorder >> inorder;
	int size = preorder.size();
	auto res= solve(0, size-1, 0, size-1);
	cout << res;
	return 0;
}