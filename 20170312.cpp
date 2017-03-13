//void zeroScore(){
//	int sum, n, tag1 = -1, tag2 = -1, high1 = 2, high2 = 2;
//	string one, two, three;
//	vector<int> number1, number2, addSum;
//	vector<int> res;
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		number1.clear();
//		number2.clear();
//		addSum.clear();
//		cin >> one >> two >> three;
//
//		for (auto c : one){
//			if (isdigit(c))
//				number1.push_back(c - '0');
//			else
//				number1.push_back(-1);
//		}
//
//		for (auto c : two){
//			if (isdigit(c))
//				number2.push_back(c - '0');
//			else
//				number2.push_back(-1);
//		}
//
//		for (auto c : three){
//			addSum.push_back(c - '0');
//		}
//
//		reverse(number1.begin(), number1.end());
//		reverse(number2.begin(), number2.end());
//		reverse(addSum.begin(), addSum.end());
//
//		if (number1.size() < 3)
//		{
//			high1 = number1.size() - 1;
//			for (int i = number1.size(); i <= 2; i++)
//			{
//				number1.push_back(0);
//			}
//		}
//		if (number2.size() < 3)
//		{
//			high2 = number2.size() - 1;
//			for (int i = number2.size(); i <= 2; i++)
//			{
//				number2.push_back(0);
//			}
//		}
//		if (addSum.size() < 4)
//		{
//			for (int i = addSum.size(); i <= 3; i++)
//			{
//				addSum.push_back(0);
//			}
//		}
//
//		for (int i = 0; i < number1.size(); ++i)
//		{
//			if (number1[i] == -1){
//				tag1 = i;
//			}
//		}
//		for (int i = 0; i < number2.size(); ++i)
//		{
//			if (number2[i] == -1){
//				tag2 = i;
//			}
//		}
//
//		if (tag1 == -1 || tag2 == -1)
//		{
//			res.push_back(1);
//			continue;
//		}
//
//		if (tag1 != tag2){
//			res.push_back(1);
//			continue;
//		}
//
//
//		else{
//			if (tag1 == 0 && tag2 == 0)
//			{
//
//				//<10
//				if ((number1[1] + number2[1]) % 10 == addSum[1]){
//					res.push_back(addSum[0] - 1);
//					continue;
//				}
//				//>10
//				else{
//					res.push_back(9 - addSum[0]);
//					continue;
//				}
//
//			}
//
//			if (tag1 == 1 && tag2 == 1)
//			{
//
//				int flag = 0;
//				if (number1[0] + number2[0] >= 10)
//				{
//					flag = 1;
//				}
//				//<10
//				if ((number1[2] + number2[2]) % 10 == addSum[2]){
//					res.push_back(addSum[1] - flag - 1);
//					continue;
//				}
//				else{//>=10			
//					if (addSum[1] == 0){
//						res.push_back(9 - flag);
//						continue;
//					}
//					else{
//						res.push_back(9 + flag - addSum[1]);
//						continue;
//					}
//				}
//
//			}
//			if (tag1 == 2 && tag2 == 2)
//			{
//				int flag = 0;
//				if (number1[1] + number2[1] + (number1[0] + number2[0] / 10) >= 10){
//					flag = 1;
//				}
//
//				//<10
//				if (addSum[3] == 0){
//					res.push_back(addSum[2] - flag - 1);
//					continue;
//				}
//
//				else{//>=10			
//					if (addSum[2] == 0){
//						res.push_back(9 - flag);
//						continue;
//					}
//					else{
//						res.push_back(9 + flag - addSum[2]);
//						continue;
//					}
//				}
//			}
//		}
//	}
//	for (auto c : res)
//	{
//		cout << c << endl;
//	}
//}


//class SomeThing{
//public:
//	SomeThing(ostream &o, char c = ' '):os(o),sep(c){};
//	//void operator()(const int i)const { cout<<i<<sep<<endl; }
//	bool operator<( SomeThing r) const
//	{
//		return this->sep < r.sep;
//	}
//	
//public:
//	char sep;
//private:
//	ostream &os;
//	
//
//};
//
//string decodeString(string input,unsigned int& i){
//	string res;
//
//	while (i < input.length() && input[i] != ']'){
//		if (!isdigit(input[i])){
//			res += input[i++];
//		}
//
//		else{
//			int n = 0;
//			while (i<input.length()&&isdigit(input[i]))
//			{
//				n = n * 10 + input[i++] - '0';
//			}
//
//			i++;
//			string tmp = decodeString(input, i);
//			i++;
//
//			while (n-->0)
//				res += tmp;
//
//		}
//	}
//	return res;
//}
//
//void f(int &&a, int& b){
//	
//}
//
//
//void generate(int left, int right, string s, vector<string>& result){
//	if (left == 0 && right == 0){
//		result.push_back(s);
//		return;
//	}
//	if (left > 0)
//		generate(left - 1, right, s + "(", result);
//	if (right > 0 && left < right)
//		generate(left, right - 1, s + ")", result);
//	
//}
////class Solution {
////public:
////	
////	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
////		vector<pair<int, int>> result;
////		int m = matrix.size();
////		int n = matrix[0].size();
////
////		vector<vector<bool>> pv(m, vector<bool>(n, false));
////		vector<vector<bool>> av(m, vector<bool>(n, false));
////		for (int i = 0; i < m; i++){
////			compute(0, i, matrix, pv, m, n);
////			compute(n - 1, i, matrix, av, m, n);
////		}
////		for (int j = 0; j < n; j++){
////			compute(j, 0, matrix, pv, m, n);
////			compute(j, m - 1, matrix, av, m, n);
////		}
////		for (int i = 0; i < m; i++){
////			for (int j = 0; j < n; j++){
////				cout << pv[i][j];
////
////				if (pv[i][j] == true && av[i][j] == true)
////					result.push_back({ i, j });
////			}
////			cout << endl;
////		}
////
////
////		return result;
////
////
////	}
////	
////	void compute(int num1, int num2, vector<vector<int>>& matrix, vector<vector<bool>> &res, int m, int n){
////		vector<int> x = { 1, 0, -1, 0 };
////		vector<int> y = { 0, -1, 0, 1 };
////		int dx, dy;
////		res[num1][num2] = true;
////		for (int i = 0; i < 4; i++){
////			dx = num1 + x[i];
////			dy = num2 + y[i];
////			if (dx >= 0 && dx < n&&dy >= 0 && dy < m){
////				if (res[dx][dy] == false && matrix[dx][dy] >= matrix[num1][num2])
////					compute(dx, dy, matrix, res, m, n);
////			}
////		}
////
////
////	}
////
////};
//
//vector<int> grayCode(int n) {
//	vector<int> result;
//
//	if (n == 0)
//		return{ 0 };
//	if (n == 1)
//		return{ 0, 1 };
//	int mask = 1, num, first, second;
//
//	for (int i = 0; i < (2 << (n - 1)); ++i){
//		num = 0;
//
//		first = (i >> (n - 1)) & 1;
//		second = ((i >> (n - 2)) & 1);
//
//		num |= (first << (n - 1));
//		num |= (first^second) << (n - 2);
//
//		for (int j = 3; j < n; ++j){
//			num |= (((i >> (n - j)) & 1) ^ second) << (n - j);
//		}
//
//		result.push_back(num);
//	}
//
//
//	return result;
//
//}
//int searchInsert(vector<int>& nums, int target) {
//	int start = 0, end = nums.size(), mid = start + (end - start) / 2;
//	int pre = -1;
//	if (target > nums[nums.size() - 1])
//		return nums.size() - 1;
//	if (target < nums[0])
//		return 0;
//	while (pre != mid){
//		pre = mid;
//
//		if (nums[mid] == target)
//			return mid;
//		else if (nums[mid] < target)
//			start = mid + 1;
//
//		else
//			end = mid-1;
//		mid = start + (end - start) / 2;
//
//	}
//
//	if (nums[mid] < target)
//		return mid - 1;
//	else
//		return mid;
//
//}
//
//class Singleton{
//public:
//	static Singleton* instence(){
//		if (NULL == ins)
//			ins = new Singleton();
//		return ins;
//	}
//private:
//	Singleton(){};
//	~Singleton(){};
//	static Singleton* ins;
//};
//Singleton* Singleton::ins = NULL;
//
//
//
//int characterReplacement(string s, int k) {
//	int max = 0;
//	int begin = 0, end = 0, temp = 0, tempNum = 0;
//	vector<int> ivec(26, 0);
//	while (end<s.size()){
//		ivec[s[end++] - 'A']++;
//		if (end - begin - *max_element(ivec.begin(), ivec.end())>k){
//			ivec[s[begin++] - 'A']--;
//		}
//	}
//
//
//	return end - begin;
//}
//
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//	
//};
//
//
//class Base{
//public:
//	Base(){};
//	void f(){};
//	virtual void g(){ cout << "base.g" << endl; };
//	int a, b;
//};
//
//class Derive:public Base{
//	virtual void g(){};
//
//
//};
//
//class Solution {
//public:
//	Solution(vector<int> nums)
//	{
//		vector<pair<int, int>> pvec;
//		for (int i = 0; i < nums.size(); ++i)
//		{
//			pvec.push_back(make_pair(nums[i], i));
//		}
//		sort(pvec.begin(), pvec.end());
//
//		for (int i = 0; i < pvec.size(); ++i)
//		{
//			vector<int> tmp;
//			tmp.push_back(pvec[i].second);
//			int old = pvec[i].first;
//			
//			while (i + 1 < pvec.size() && old == pvec[i + 1].first)
//				{
//					tmp.push_back(pvec[++i].second);
//				}
//				
//			vvec.push_back(make_pair(old, tmp));
//		}
//
//	}
//
//	int pick(int target) {
//		for (int i = 0; i < vvec.size(); ++i)
//		{
//			if (vvec[i].first == target)
//			{
//				int index=rand() % vvec[i].second.size();
//				return vvec[i].second[index];
//			}
//		}
//	}
//
//public:
//	vector<pair<int, vector<int>>> vvec;
//};
//
//class Base{
//public:
//	Base(){ num = 1; }
//	explicit Base(int i ){ num = i; }
//	
//	Base& operator= (const Base &r){ num = r.num; return *this; }
//	virtual void print1()
//	{
//		cout << "base" << endl;
//	}
//	void speak(){ cout << "a" << endl; }
//
//public:
//	int num;
//};
//
//class Derive : public Base{
//public:
//	Derive(int i){
//	num = i; }
//	virtual void print1(){
//		cout << "derive" << endl;
//	}
//	virtual void print12(){
//		cout << "derive" << endl;
//	}
//	static void f(){
//		
//	}
//
//
//};
//class Solution {
//public:
//	int lastRemaining(int n) {
//		return recursion(n, true);
//	}
//	// return the left number of 1 - n starting from eliminting left to right
//	int recursion(int n, bool isLeft) {
//		if (n == 1) return n;
//		if (!isLeft && (n % 2) == 0) {
//			// eliminate all the even numbers
//			// [1, 2, 3, 4, 5, 6] -> [1, 3, 5]
//			// It is equivalent to consider the number left in [1, 2, 3] * 2 - 1
//			return recursion(n / 2, !isLeft) * 2 - 1;
//		}
//		else {
//			// eliminate all the odd numbers
//			// [1, 2, 3, 4, 5, 6] -> [2, 4, 6]
//			// It is equivalent to consider the number left in [1, 2, 3] * 2
//			return recursion(n / 2, !isLeft) * 2;
//		}
//	}
//	static  int i;
//};

//void print_subset(int n, int s){
//	for (int i = 1; i <=n;++i)
//	{
//		if (s&(1 << i))
//			cout << i+1;
//	}
//	cout << endl;
//}
//const int N = 35;
//int vis[N], res[N], n, maxx, a, k;
//
//bool judge(int t) {
//	int i = t / 20 + 2, j;//这层以下爬楼梯  
//	k = 0;
//	while (i <= maxx) {// i为最后一个到达的人的目标楼层  
//		while (i <= maxx && !vis[i])
//			i++;
//		if (4 * (i - 1) + 10 * k > t)
//			return false;
//		j = (t - 10 * k + 20 * i + 4) / 24;//原式 t-10*k-4*(j-1)-20*(j-i)=0 此时j > i  
//		i = (t - 10 * k + 16 * j + 4) / 20 + 1;//原式 t-10*k-4*(j-1)-20*(i-j)=0,以j为下一个起点  
//		res[k++] = j;
//	}
//	return true;
//}

//class Solution {
//public:
//	bool searchMatrix(vector<vector<int>>& matrix, int target) {
//		if (matrix.size() == 0 || matrix[0].size() == 0)
//			return false;
//		int sizei = matrix.size(), sizej = matrix[0].size();
//		return helper(matrix, target, sizei, sizej, 0, 0);
//
//	}
//
//
//	bool helper(vector<vector<int>>& matrix, int target, int x, int y, int zerox, int zeroy){
//		
//
//		if (target<matrix[zerox][zeroy] || target>matrix[zerox+x-1][zeroy+y-1])
//			return false;
//		int n = min(x, y), a;
//		for (int i = 0; i<n; ++i){
//			if (target>matrix[zerox + i][zeroy + i])
//				a = i;
//			if (target == matrix[zerox + i][zeroy + i])
//				return true;
//		}
//		if (x >= a + 2 && y >= a + 2)
//			return helper(matrix, target, x - a - 1, a + 1, zerox + a+1, zeroy) || helper(matrix, target, a + 1, y - a - 1, zerox, zeroy + a+1);
//		else if (x >= a + 2)
//			return helper(matrix, target, x - a-1, a+1, zerox + a+1, zeroy);
//		else
//			return helper(matrix, target, a+1, y - a-1, zerox, zeroy + a+1);
//
//
//	}
//};
//
//class Solution {
//public:
//	int lengthOfLIS(vector<int>& nums) {
//		vector<int> count(nums.size(), 0);
//		int res = 0;
//		int max;
//		for (int i = 0; i < nums.size(); ++i){
//			max = 0;
//			for (int j = 0; j < i; ++j){
//				if (nums[j]<nums[i])
//					max = max>count[j] ? max : count[j];
//			}
//			count[i] = max + 1;
//		}
//
//		for (int i = 0; i<count.size(); ++i)
//			res = res>count[i] ? res : count[i];
//
//		return res;
//
//	}
//};
//vector<string> getLines(string& input) {
//	istringstream iss(input);
//	string curr;
//	vector<string> lines;
//	while (getline(iss, curr, '\n')) lines.push_back(curr);
//	return lines;
//}
//
//int lengthLongestPath(string input) {
//	vector<string> lines = getLines(input);
//	int numLines = lines.size();
//	vector<int> lens(numLines + 1, 0);
//	int maxLen = 0;
//	for (auto line : lines) {
//		size_t pos = line.find_last_of('\t');
//		int levl = (pos == string::npos) ? 0 : (levl = pos + 1);
//		if (line.find('.') == string::npos) {
//			lens[levl + 1] = lens[levl] + line.size() - levl;
//		}
//		else {
//			//maxLen = max(maxLen, (int)(lens[levl - 1] + line.size() + 1));
//			maxLen = max(maxLen, (int)(lens[levl] + line.size()));
//		}
//	}
//	return maxLen;
//}
//

//class Solution {
//public:
//	int getMoneyAmount(int n) {
//		vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
//
//		if (n == 1)
//			return 0;
//		for (int i = 1; i <= n; ++i){
//			for (int j = i - 1; j >= 1; --j){
//				dp[j][i] = INT_MAX;
//				for (int k = j; k <= i; ++k)
//					dp[j][i] = min(dp[j][i], k + max(dp[j][k - 1], dp[k + 1][i]));
//			}
//
//		}
//
//		return dp[1][n];
//
//	}
//};

//void dp(vector<vector<int>>& res, vector<int> tmp, vector<int>& nums, int n){
//	res.push_back(tmp);
//	for (int i = n; i < nums.size(); ++i){
//		if (i != n&&nums[i] == nums[i - 1])
//			continue;
//		tmp.push_back(nums[i]);
//		dp(res, tmp, nums, i + 1);
//		tmp.pop_back();
//	}
//
//}
//
//
//vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//	vector<vector<int>> result;
//	sort(nums.begin(), nums.end());
//	dp(result, {}, nums, 0);
//
//	return result;
//}

//#define _Debug
//#ifdef _Debug
//ifstream in("test.txt");
//#else
//istream &in = cin;
//#endif

