#include<iostream>  
#include<fstream>
#include<algorithm>
//#include<functional>
//#include<set>
//#include<vector>
//#include<bitset>
using namespace std;
#define _debug
#ifdef _debug
ifstream ifs("test.txt");
#else
istream &ifs = cin;
#endif

int n, m, L;
int l, r, t, b;

int countPoint(int pl,int pr,int pt,int pb){
	int res = 0;
	int ll = max(l, pl);
	int rr = min(r, pr);
	int tt = max(t, pt);
	int bb = min(b, pb);

	if (ll >= rr || tt >= bb)
		return (pr - pl) * (pb - pt);

	int inside = 0;
	if (ll > pl && ll < pr && tt > pt && tt < pb)
		inside++;
	if (rr > pl && rr < pr && tt > pt && tt < pb)
		inside++;
	if (ll > pl && ll < pr && bb > pt && bb < pb)
		inside++;
	if (rr > pl && rr < pr && bb > pt && bb < pb)
		inside++;

	if (inside == 1 || inside == 4)
		return (pr - pl) * (pb - pt) - (rr - ll) * (bb - tt);
	else
		return 0;
}

void solve(){
	int res = 0, s = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m;++j){
			for (int k = 1; k < L / 2; ++k){
				int num = countPoint(j,min(j+k,m),i,min(i+(L/2)-k,n));
				res = res>num ? res : num;
			}
		}
	}
	cout << res << endl;
}

int main()
{
	ifs >> n >> m >> L >> l >> r >> t >> b;
	solve();
	system("pause");
	return 0;
}