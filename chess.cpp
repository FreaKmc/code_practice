#include "iostream"
#include "algorithm"
#include "vector"
#include "iterator"
#include "string"
#include <memory>
#include "fstream"
using namespace std;

#define  _DEBUG

class Person{
public:
	Person(int n) :num(n){};
	int num;
};

void findChess(int a[8][8], int x, int y, int z,int xDir,int yDir){
	int i = 1;

	while (a[x + i*xDir][y + i*yDir] == -z)
	{
		i++;
	}
	if (i>1 && a[x + i*xDir][y + i*yDir]==z)
	{
		for (int j = 1; j <= i - 1;j++)
		{
			a[x + j*xDir][y + j*yDir] = z;
		}
	}

}

void chess(int a[8][8],int x,int y,int z){
	a[x][y] = z;
	if (x!=0)
	{
		findChess(a, x, y, z, -1, 0);
		if (y!=0)
		{
			findChess(a, x, y, z, -1, 1);
		}
		if (y!=7)
		{
			findChess(a, x, y, z, -1, -1);
		}
	}
	if (y!=0)
	{
		findChess(a, x, y, z, 0, -1);
	}
	if (y!=7)
	{
		findChess(a, x, y, z, 0, 1);
	}
	
	if (x!=7)
	{
		findChess(a, x, y, z, 1, 0);
		if (y!=0)
		{
			findChess(a, x, y, z, 1, -1);
		}
		if (y!=7)
		{
			findChess(a, x, y, z, 1, 1);
		}
	}
	

	
}

int main(){

	string s;
	int arr[8][8];
	ifstream in("input.txt");
	for(int i=0;i<8;i++){
		getline(in,s);
		for (int j = 0; j < 8;j++)
		{
			switch (s[j])
			{
			case '.': arr[i][j] = 0; break;
			case 'o': arr[i][j] = 1; break;
			case '*': arr[i][j] = -1; break;
			default:
				break;
			}
		}
	}
	

	getline(in, s);
	int n = s[0]-'0';
	for (int k = 0; k < n;k++)
	{
		getline(in, s);
		int x = s[0]-'0';
		int y = s[2] - '0';

		int z = s[4] - '0';
		if (z == 0)
		{
			z = -1;
		}
		else
			z = 1;
		chess(arr, x, y, z);
	}
	int black = 0, white = 0;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (arr[i][j]==-1)
			{
				++black;
			}
			else if (arr[i][j] == 1)
			{
				++white;
			}

		}
		
	}

	cout << black << " " << white << endl;
	system("pause");
	return 0;
}


