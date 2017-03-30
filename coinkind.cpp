#include "iostream"
#include "algorithm"
#include "vector"
#include "iterator"
#include "string"

using namespace std;

int count1(int money, int type, int mvec[]){
	vector<vector<int>> table(type + 1);
	for (int i = 0; i <= type; i++){
		table[i].resize(money + 1);
	}
	for (int i = 0; i <= type; ++i){
		for (int j = 0; j <= money; ++j){
			table[i][j] = 0;
		}
	}

	for (int i = 0; i <= type; ++i){
		table[i][0] = 1;
	}
	for (int i = 1; i <= type; i++){
		for (int j = 1; j <= money; j++){
			
			for (int k = 0; k <= j / mvec[i-1]; k++){
				table[i][j] += table[i - 1][j - k*mvec[i-1]];
			}
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	return table[type][money];
}


int main(){

	int mvec[6] = { 1, 5, 10, 20, 50, 100 };
	int result=count1(20,6,mvec);


	system("pause");
	return 0;
}