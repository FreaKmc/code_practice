#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include <fstream>
using namespace std;

//ifstream ifs("test.txt");

int solve(){
	string s,tmp;
	cin >> s;
	tmp.resize(2 * s.size() + 2);
	tmp[0] = '$';
	tmp[1] = '#';
	for (int i = 0; i < s.size(); ++i) {
		tmp[(i + 1) << 1] = s[i];
		tmp[((i + 1) << 1) + 1] = '#';
	}
	int tmpSize = tmp.size();
	int res = 0;
	vector<int> len(tmpSize, 0);
	for (int i = 1,id=0; i < tmp.size();++i){
		if (len[id] + id>i){
			len[i] = min(len[2 * id - i], len[id] + id - i);
		}
		else
			len[i] = 1;
		while (tmp[i + len[i]] == tmp[i - len[i]])
			len[i]++;
		if (i+len[i]>id+len[id])
		{
			id = i;
		}
		res = max(res, len[i]);
	}
	
	return res-1;

}

int main(){
	int n;
	cin >> n;
	while (n--){
		cout<<solve()<<endl;
	}

	system("pause");
	return 0;
}
