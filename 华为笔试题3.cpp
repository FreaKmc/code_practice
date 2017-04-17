#include<iostream>  
#include<fstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<sstream>
#include<queue>
using namespace std;
#define _debug
#ifdef _debug
ifstream ifs("test.txt");
#else
istream &ifs = cin;
#endif

class Task{
public:
	int id, l, st, dt;
	Task(int a, int b, int c, int d) :id(a), l(b), st(c), dt(d){};
	bool operator>(Task a,Task b){ return a.l < b.l; };
};

int main(){
	string s,tmp;
	ifs >> s;
	istringstream iss(s);
	vector<Task> tv;
	while (getline(iss, tmp, '|')){
		istringstream isss(tmp.substr(1,tmp.size()-2));
		string t;
		vector<int> ivec;
		while (getline(isss, t, '.')){
			ivec.push_back(atoi(t.c_str()));
		}
		tv.push_back(Task(ivec[0],ivec[1],ivec[2],ivec[3]));
	}

	int time = 0,finishTask=0,por=-1,doingId=0;
	priority_queue<Task, vector<Task>,greater<Task>> q;
	while (finishTask < 5){
		for (int i = 0; i < 5; ++i){
			if (tv[i].st == time)
				q.push(tv[i]);
		}
		if (doingId>0&&tv[doingId - 1].dt == 0){
			cout << "[" << doingId << "." << time << "]";
			finishTask++;
			if (!q.empty()){
				doingId = q.top().id;
				por = q.top().l;
				q.pop();
			}
			else{
				doingId = 0;
				por = -1;
			}
		}
		if (!q.empty()&&q.top().l>por){
			if (doingId==0){
				cout << "[0." <<time<< "]";
			}
			else{
				q.push(tv[doingId-1]);
				cout << "[" << doingId << "." << time << "]";
			}
			doingId = q.top().id;
			por = q.top().l;
			q.pop();
		}
		if (doingId)
			tv[doingId - 1].dt--;
		time++;
	}
	return 0;
}

