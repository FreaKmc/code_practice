#include<iostream>  
#include<cstring>  
using namespace std;

#define ll long long int  
#define rep(a,b,c) for(int a = b ;  a < c; a++)  

const int mod = 1000000007;

struct node{
	ll s, n;
};

node dp[21][20][400];

int bits[21];
ll base[21];


node dfs(int len, int dig, bool begin_zero, bool end_flag, int sum){
	node t;
	t.n = 0, t.s = 0;
	if (len>=20||len<=0||dig<0||dig>9||sum>=200||sum<-200)
		return t;
	if (!end_flag&&dp[len][dig + (begin_zero ? 0 : 10)][sum + 200].n != -1)
		return dp[len][dig + (begin_zero ? 0 : 10)][sum + 200];
	if (len==1){
		if (dig!=sum){
			return t;
		}
		t.n = 1;
		t.s = sum;
		return t;
	}
	int end = end_flag ? bits[len - 2] : 9;
	int newsum = dig - sum;
	node tmp;
	for (int i = 0; i < end + 1;++i){

		if (!begin_zero)
			tmp = dfs(len - 1, i, i != 0, end_flag && (i == end), sum);
		else
			tmp = dfs(len - 1, i, true, end_flag && (i == end), newsum);
		t.n += tmp.n;
		t.s = (t.s + tmp.s) % mod + (((dig* tmp.n) % mod*base[len - 1]) % mod) % mod;
	}
	if (!end_flag)
	{
		dp[len][dig + (begin_zero ? 0 : 10)][sum + 200] = t;	
	}
	return t;
}


int solve(ll n, int s){
	if (n <= 0)
		return 0;
	int l = 0;
	rep(i, 0, 21) bits[i] = 0;
	while (n){
		bits[l++] = n % 10;
		n /= 10;
	}
	return dfs(l + 1, 0, false, true, s).s;
}

int main(){
	ll l, r, s;
	node t;
	t.n = -1;
	t.s = 0;
	rep(i, 0, 21) rep(j, 0, 20) rep(k, 0, 400) dp[i][j][k] = t;
	base[0] = 1;
	rep(i, 1, 21) base[i] = (base[i - 1] * 10) % mod;
	cin >> l >> r >> s;
	cout << (solve(r, s) - solve(l - 1, s) + mod) % mod << endl;
	return 0;
}