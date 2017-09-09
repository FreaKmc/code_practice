class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2)
			return 0;
		int maxN = INT_MIN, minN = INT_MAX;
		int len = nums.size();
		for (auto c : nums) {
			maxN = max(c, maxN);
			minN = min(c, minN);
		}
		int bucketGap = ceil((double)(maxN - minN) / (len - 1));
		if (bucketGap == 0)
			return 0;
		int bucketSize = (maxN - minN) / bucketGap + 1;

		vector<int> maxNum(bucketSize, INT_MIN), minNum(bucketSize, INT_MAX);

		for (auto c : nums) {
			int id = (c - minN) / bucketGap;
			minNum[id] = min(minNum[id], c);
			maxNum[id] = max(maxNum[id], c);
		}

		int preMax = maxNum[0], res = 0;
		for (int i = 1; i < maxNum.size(); ++i) {
			if (minNum[i] != INT_MAX) {
				res = max(res, minNum[i] - preMax);
				preMax = maxNum[i];
			}

		}
		return res;
	}
};
