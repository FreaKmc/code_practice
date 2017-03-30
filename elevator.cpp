#include "iostream"
#include "algorithm"
#include "vector"
#include "iterator"
#include "string"
#include "unordered_map"
#include <memory>
using namespace std;

class Person{
public:
	Person(int t,int c,int floor) :time(t),endTime(0),eleTime(0),curFloor(c),destFloor(floor){};
public:
	int time;
	int endTime;
	int eleTime;
	int curFloor;
	
	int destFloor;
};

class Elevator{
public:
	Elevator() :dir(1), curFloor(1), fvec({}){};
public:
	int dir;
	int curFloor;
	vector<int> fvec;

};

bool operator==(Person l,Person r)
{
	return l.destFloor == r.destFloor;
}


int main(){
	Elevator e;
	Person p1(1, 10, 9);
	/*Person p2(5,4,3);
	Person p3(10, 8, 9);*/
	vector<Person> vacantPerson ;
	vector<Person> waitPerson ;
	vector<Person> elevatorPerson;
	vector<Person> finishPerson;
	vacantPerson.push_back(p1);
	//vacantPerson.push_back(p2);
	//vacantPerson.push_back(p3);
	int time = 1;

	while (finishPerson.size()!=1)//all person finish
	{
		for (auto v = vacantPerson.begin(); v != vacantPerson.end();)
		{
			if (v->time == time)
			{

				waitPerson.push_back(*v);
				e.fvec.push_back(v->curFloor);
				v = vacantPerson.erase(v);
			}
			else
				v++;
		}

		for (auto w = waitPerson.begin(); w != waitPerson.end();)
		{
			if (w->curFloor == e.curFloor)
			{
				elevatorPerson.push_back(*w);
				e.fvec.push_back(w->destFloor);
				
				w = waitPerson.erase(w);

				
				for (auto it = e.fvec.begin(); it != e.fvec.end();)
				{
					if (*it == e.curFloor)
					{
						it = e.fvec.erase(it);
					}
					else
						it++;
				}
			}
			else
				w++;
		}

		for (auto ele = elevatorPerson.begin(); ele != elevatorPerson.end();)
		{
			if (ele->destFloor == e.curFloor)
			{
				ele->endTime = time;
				finishPerson.push_back(*ele);
				for (auto it = e.fvec.begin(); it != e.fvec.end();)
				{
					if (*it == e.curFloor)
					{
						it = e.fvec.erase(it);
					}
					else
						it++;
				}
				ele = elevatorPerson.erase(ele);
			}
			else
				ele++;
		}
		//enter people

		//leave people
		time++;
		if (e.fvec.size()==0)
		{
			
			continue;
		}
		//determinate vector destfloor
		if (e.dir==1)
		{
			auto it = find_if((e.fvec).begin(), (e.fvec).end(), [&](int floor){return floor > e.curFloor; });
			if (it==e.fvec.end())
			{
				e.dir = -1;
				--e.curFloor;
			}
			else{
				
				++e.curFloor;
			}
		}
		else if (e.dir==-1)
		{
			auto it = find_if((e.fvec).begin(), (e.fvec).end(), [&](int floor){return floor < e.curFloor; });
			if (it == e.fvec.end())
			{
				e.dir = 1;
				++e.curFloor;
			}
			else{

				--e.curFloor;
			}
		}
	}
	
	for (auto it = finishPerson.begin(); it != finishPerson.end();++it)
	{
		cout << it->endTime<<it->time << endl;
	}


	system("pause");
	return 0;
}


