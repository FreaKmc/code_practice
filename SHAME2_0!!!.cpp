#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
	string a, b;
	int c, sum1 = 0, sum2 = 0, res = 0;
	cin >> a >> b >> c;
	vector<int> tag1, tag2(3,0);
	for (int i = 0; i < a.size(); ++i){
		if (isdigit(a[i])){
			sum1 += (a[i] - '0')*pow(10, (a.size() - i - 1));
		}
		else{
			tag1.push_back(a.size() - 1 - i);
		}
	}
	for (int i = 0; i < b.size(); ++i){
		if (isdigit(b[i])){
			sum2 += (b[i] - '0')*pow(10, (b.size() - i - 1));
		}
		else{
			tag2[b.size() - 1 - i]=1;
		}
	}
	int tmp = 0;

	if (tag1.size()==1){
		for (int i = 1; i <= 9;++i)
		{
			int tmp = i*pow(10, tag1[0]);
			int t = c - tmp - sum1 - sum2;
			if (t>0 && t<1000 && ((t > 100 && tag2[2] == 1) || (t / 100 == 0 && tag2[2] == 0)) && (((t / 10) % 10 >= 1 && tag2[1] == 1) || ((t / 10) % 10 == 0 && tag2[1] == 0)) && ((t % 10 >= 1 && tag2[0] == 1) || (t % 10 == 0 && tag2[0] == 0)))
			{
				res++;
			}
		}
	}

	else if (tag1.size()==2){
		for (int i = 1; i <= 9; ++i){
			for (int j = 1; j <= 9; ++j){
				tmp = i*pow(10,tag1[0]) + j*pow(10,tag1[1]);
				int t = c - tmp - sum1 - sum2;
				if (t>0 && t<1000&&((t > 100 && tag2[2] == 1) || (t / 100 == 0 && tag2[2] == 0)) && (((t / 10) % 10 >= 1 && tag2[1] == 1) || ((t / 10) % 10 == 0 && tag2[1] == 0)) && ((t % 10 >= 1 && tag2[0] == 1) || (t % 10 == 0 && tag2[0] == 0)))
				{
					res++;
				}
			}
		}
	}

	else if(tag1.size()==3){
		for (int i = 1; i <= 9; ++i){
			for (int j = 1; j <= 9; ++j){
				for (int k = 1; k <= 9; ++k){
					tmp = i*pow(10, tag1[0]) + j*pow(10, tag1[1]) + k*pow(10, tag1[2]);	
					int t = c - tmp - sum1 - sum2;
					if (t>0&&t<1000&&((t > 100 && tag2[2] == 1) || (t / 100 == 0 && tag2[2] == 0)) && (((t / 10) % 10 >= 1 && tag2[1] == 1) || ((t / 10) % 10 == 0 && tag2[1] == 0)) && ((t % 10 >= 1 && tag2[0] == 1) || (t % 10 == 0 && tag2[0] == 0)))
					{
						cout << t << " ";
						res++;
					}
				}
			}
		}
	}

	else{
		res = 1;
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