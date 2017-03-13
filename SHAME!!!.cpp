#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
	string a, b;
	int c,sum1=0,sum2=0,tag1=-1,tag2=-1,res=0;
	cin >> a >> b >> c;

	for (int i = 0; i < a.size();++i){
		if (isdigit(a[i])){
			sum1 += (a[i] - '0')*pow(10, (a.size() - i-1));
		}
		else{
			tag1 = pow(10, (a.size() -1- i));
		}
	}
	for (int i = 0; i < b.size(); ++i){
		if (isdigit(b[i])){
			sum2 += (b[i] - '0')*pow(10, (b.size() - i-1));
		}
		else{
			tag2 = pow(10, (a.size() -1- i));
		}
	}

	if (tag1==-1||tag2==-1)
	{
		cout << 1 << endl;
		return;
	}

	for (int i = 1; i <= 9; i++){
		for (int j = 1; j <= 9; ++j){
			if (i*tag1 + j*tag2 == c - sum1 - sum2)
				res++;
		}
	}
	cout << res << endl;
}

int main() {

	int n;
	cin >> n;
	while (n--){
		solve();
	}

	system("pause");
	return 0;
}