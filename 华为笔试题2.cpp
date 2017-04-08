#include<iostream>  
#include<algorithm>
#include<vector>
#include<fstream>
#include<set>
using namespace std;
#define _debug
#ifdef _debug
ifstream ifs("test.txt");
#else
istream &ifs = cin;
#endif

void solve(vector<int>& n,set<int>& s){
	for (int i = 0; i < 3; ++i){
		s.insert(n[i]);
		s.insert(n[i] * 10 + n[(i + 1) % 3]);
		s.insert(n[i] * 10 + n[(i + 2) % 3]);
		s.insert(n[i] * 100 + n[(i + 1) % 3] * 10 + n[(i + 2) % 3]);
		s.insert(n[i] * 100 + n[(i + 2) % 3] * 10 + n[(i + 1) % 3]);
	}
}

int main() {
	string s;
	while (ifs >> s){
		if (s.size() != 5 || s[1] != ',' || s[3] != ',' || !isdigit(s[0]) || !isdigit(s[2]) || !isdigit(s[4])){
			cout << -1 << endl;
			return -1;
		}
		vector<int> num;
		set<int> ss;
		int a = 0, b = 0, c = 0;
		a = s[0] - '0';
		b = s[2] - '0';
		c = s[4] - '0';
		num.push_back(a);
		num.push_back(b);
		num.push_back(c);
		sort(num.begin(), num.end());
		int maxN = num[2] - 1;
		if (a*b == 10 || b*c == 10 || a*c == 10 || a*b == 54 || b*c == 54 || a*c == 54){
			if (a*b*c != 60 && a*b*c != 90 && a*b*c != 108 && a*b*c != 270)
				solve(num, ss);
			else{
				if (a*b*c == 60 || a*b*c == 90){
					vector<int> num1{ 2, 5, 6 };
					solve(num1, ss);
					vector<int> num2{ 2, 5, 9 };
					solve(num2, ss);
				}
				else if (a*b*c == 108 || a*b*c == 270){
					vector<int> num1{ 2, 6, 9 };
					solve(num1, ss);
					vector<int> num2{ 5, 6, 9 };
					solve(num2, ss);
				}
			}
		}
		else if ((a*b == 12&&a+b==8) || (b*c == 12&&b+c==8) || (a*c == 12&&a+c==8) || 
			(a*b == 18&&a+b==11) || (b*c == 18&&b+c==11) || (a*c == 18&&a+c==11) || 
			a*b == 30 || b*c == 30 || a*c == 30 || a*b == 45 || b*c == 45 || a*c == 45){
			int three = -1;
			for (int i = 0; i < 3; ++i){
				if (num[i] != 2 && num[i] != 6 && num[i] != 5 && num[i] != 9)
					three = num[i];
			}
			vector<int> num1{ three, 2, 6 };
			solve(num1, ss);
			vector<int> num2{ three, 2, 9 };
			solve(num2, ss);
			vector<int> num3{ three, 5, 6 };
			solve(num3, ss);
			vector<int> num4{ three, 5, 9 };
			solve(num4, ss);
		}
		else if (a == 2 || b == 2 || c == 2 || a == 5 || b == 5 || c == 5 || 
			a == 6 || b == 6 || c == 6 || a == 9 || b == 9 || c == 9){
			int two = -1, three = -1;
			for (int i = 0; i < 3; ++i){
				if (num[i] != 2 && num[i] != 6 && num[i] != 5 && num[i] != 9){
					if (two == -1)
						two = num[i];
					else
						three = num[i];
				}
			}
			vector<int> num1, num2;
			if (a == 2 || b == 2 || c == 2 || a == 5 || b == 5 || c == 5){
				num1 = { 2, two, three };
				num2 = { 5, two, three };
			}
			else if (a == 6 || b == 6 || c == 6 || a == 9 || b == 9 || c == 9){
				num1 = { 6, two, three };
				num2 = { 9, two, three };
			}
			solve(num1, ss);
			solve(num2, ss);
		}
		else
			solve(num, ss);

		if (maxN > ss.size())
			cout << *(--ss.end()) << endl;
		else{
			auto it = ss.begin();
			while (maxN--){
				it++;
			}
			cout << *it << endl;
		}
	}
	return 0;
}