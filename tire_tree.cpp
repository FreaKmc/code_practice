#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Node
{
public:
	int count;
	char c;
	Node* next;
	Node* right;
public:
	Node(char cc) :count(1), c(cc),next(NULL),right(NULL){};
};

//ifstream ifs("test.txt");

void constructTree(Node* head){
	string s;
	cin >> s;
	Node* cur = head->next,*tmp=head;
	for (auto ch : s)
	{
		if (cur)
		{
			if (cur->c==ch) //duplicate node
			{
				cur->count++;
				tmp = cur;
				cur = cur->next;
				continue;
			}
			while (cur&&cur->c!=ch) // search node to right
			{
				tmp = cur;
				cur = cur->right;
			}
			if (cur) //find
			{
				cur->count++;
				tmp = cur;
				cur = cur->next;
				continue;
			}
			else //not find
			{
				cur = new Node(ch);
				tmp->right = cur;
				tmp = cur;
				cur = cur->next;
				continue;
			}
		}
		else //create node
		{
			cur = new Node(ch);
			tmp->next = cur;
			tmp = cur;
			cur = cur->next;
			continue;
		}
	}
}

int countNumber(Node* head){
	string s;
	cin >> s;
	Node* cur = head->next;
	Node* pre = head;
	for (auto cc:s)
	{
		if (cur)
		{
			if (cur->c == cc) //find to the next
			{
				pre = cur;
				cur = cur->next;
				continue;
			}
			while (cur&&cur->c!=cc) //to right
			{
				pre = cur;
				cur = cur->right;
			}
			if (cur) //find
			{
				pre = cur;
				cur = cur->next;
				continue;
			}
			else //not find
			{
				return 0;
			}

		}
		else //lengh to long
			return 0;
	}


	return pre->count; //return the number
}

int main(){
	int m,n;
	
	cin >> m;

	Node* head = new Node(' ');
	for (int i = 0; i < m; ++i){
		constructTree(head);
	}

	cin >> n;
	while (n--)
	{
		cout<<countNumber(head)<<endl;
	}

	return 0;
}
