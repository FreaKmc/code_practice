#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;
const int MAXCAR = 498; //the number of cars
const int PX = 50;     //position of people
const int PY = 50;
class Node
{
public:
	int x, y,num;
	Node(int xx, int yy,int nn) :x(xx), y(yy),num(nn){};
};
Node car[MAXCAR + 5];

void solve(int n){
	Node people(PX, PY,-1);
	vector<Node> nearNode;
	double dis = 1.0;	      //expand the distance
	while (nearNode.size() <= 2){
		for (int i = 0; i < n; ++i){
			if (car[i].x <= dis&&car[i].y <= dis)
				nearNode.push_back(car[i]);
			if (car[i].x>dis)
			{
				dis *= 2;
				break;
			}
		}
	}
	sort(nearNode.begin(), nearNode.end(), [](Node l, Node r){ return (l.x*l.x) + (l.y*l.y) < (r.x*r.x) + (r.y*r.y); });
	cout << "the nearest cars num1:" << nearNode[0].num << " x1=" << nearNode[0].x + PX << " y1=" << nearNode[0].y + PY << "   num2:" << nearNode[1].num << " x2=" << nearNode[1].x + PX << " y2=" << nearNode[1].y + PY<<endl;
}

int main()
{
	srand((unsigned)time(NULL));
	int n = 2 + rand() % MAXCAR;
	cout << "passenger X:50 Y:50, Map 100*100" << endl;
	cout <<"random numbers of cars :"<< n << endl;
	int j = 1;
	for (int i = 0; i < n; ++i,++j){
		int x = rand() % 100-PX;
		int y = rand() % 100-PY;
		car[i] = Node(x, y,i);
		cout <<"cars "<<i<<" x:"<< x+PX << " y:" << y+PY <<"  ";
		if (j % 3 == 0)
			cout << endl;
	}
	cout << endl;
	sort(car, car + n, [](Node l, Node r){return abs(l.x) < abs(r.x); });
	solve(n);
	system("pause");
	return 0;
}