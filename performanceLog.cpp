#include<iostream>  
#include<fstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<sstream>
#include<queue>
#include<stack>
#include<unordered_set>
using namespace std;
#define _debug
#ifdef _debug
ifstream ifs("test.txt");
#else
istream &ifs = cin;
#endif

class Task{
public:
	string name;
	int h, m, s;
	int op;
	Task(string nn, int hh, int mm, int ss, int oop) :name(nn), h(hh), m(mm), s(ss), op(oop){};
};

vector<Task> tv;

string calTime(Task l,Task r){
	int t = l.h * 3600 + l.m * 60 + l.s - (r.h * 3600 + r.m * 60 + r.s);
	if (t < 0)
		return "error";
	int hh = t / 3600,mm=t%3600/60,ss=t%60;
	string rh, rm, rs;
	if (hh < 10)
		rh = "0" + to_string(hh);
	if (mm < 10)
		rm = "0" + to_string(mm);
	if (ss < 10)
		rs = "0" + to_string(ss);
	return  rh+ ":" + rm + ":" + rs;
}

void solve(){
	vector<string> taskLog;
	stack<Task> tStack;
	for (int i = 0; i < (int)tv.size(); ++i){
		if (tv[i].op)
			tStack.push(tv[i]);
		else{
			if (tStack.empty()){
				cout << "Incorrect performance log";
				return;
			}
			else{
				Task tmp = tStack.top();
				tStack.pop();
				if (tmp.name == tv[i].name){
					string lo;
					string ti = calTime(tv[i], tmp);
					if (ti == "error"){
						cout << "Incorrect performance log";
						return;
					}
					lo = tmp.name + " " + ti;
					taskLog.push_back(lo);
				}
				else{
					cout << "Incorrect performance log";
					return;
				}
			}
		}
	}
	if (!tStack.empty()){
		cout << "Incorrect performance log";
		return;
	}

	for (auto c:taskLog){
		cout << c << endl;
	}
}
int main(){
	int n;
	ifs >> n;
	for (int i = 0; i < n;++i){
		string name,time,op; 
		ifs >> name >> time >> op;
		istringstream sss(time);
		string tt;
		vector<int> iv;
		while (getline(sss, tt, ':')){
			iv.push_back(stoi(tt));
		}
		int tag=0;
		if (op == "START")
			tag = 1;
		tv.push_back(Task(name, iv[0], iv[1], iv[2], tag));
	}
	solve();
	return 0;
}