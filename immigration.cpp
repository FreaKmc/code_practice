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

class City{
public:
	int l, r, n;
	City(int a,int b,int c) :l(a), r(b), n(c){};
};

bool solve(vector<int>& ivec,vector<City>& cvec,int maxP){
	int n = ivec.size(), m = cvec.size();
	if (m == 0)
		return true;
	int li = 0, ln = cvec[0].n;
	for (int i = 0; i < n; ++i){
		int pp = maxP;
		if (cvec[li].r < ivec[i])
			return false;
		for (int j = li; j <=m; ++j){
			if (j == m)
				return true;
			if (cvec[j].l>ivec[i]){
				li = j;
				ln = cvec[j].n;
				break;
			}
			int tmp = li == j ? ln : cvec[j].n ;
			pp -= tmp;
			if (pp < 0){
				li = j;
				ln = -pp;
				break;
			}
		}
	}
	return false;
}

int getMin(vector<pair<int, int>>& p,int r){
	vector<City> cvec;
	vector<int> x;
	int N = p.size();
	int maxR=0;
	long long sum=0;
	for (int i = 0; i < N; ++i){
		x.push_back(p[i].first);
		if (p[i].second){
			cvec.push_back(City(p[i].first - r, p[i].first + r, p[i].second));
			sum += p[i].second;
			maxR = max(maxR, p[i].second);
		}
	}
	int ll = (sum+N-1)/N,rr =maxR;
	while (ll != rr){
		int mid = (ll + rr) / 2;
		if (solve(x, cvec, mid))
			rr = mid;
		else
			ll = mid + 1;
	}
	return ll;
}

int main(){
	int n;
	ifs >> n;
	for (int i = 0; i < n; ++i){
		int m, r;
		ifs >> m >> r;
		vector<pair<int, int>> locate(m, {-1,-1});
		for (int j = 0; j < m; j++){
			int a, b;
			ifs >> a >> b;
			locate[j] = make_pair(a, b);
		}
		sort(locate.begin(), locate.end());
		cout << getMin(locate,r) << endl;
	}
	return 0;
}