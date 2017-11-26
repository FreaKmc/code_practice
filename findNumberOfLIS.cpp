class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		vector<vector<pair<int, int>>> iv;
		for (int i = 0; i<nums.size(); ++i) {
			if (iv.empty()){
				iv.push_back(vector<pair<int, int>>{{ nums[i], 1 }});
				continue;
			}
			int count = 0;
			for (int j = iv.size() - 1; j >= 0; --j) {
				if (nums[i]>iv[j].back().first) {
					for (int k = iv[j].size() - 1; k >= 0 && iv[j][k].first < nums[i]; --k){
						count += iv[j][k].second;
					}
					if (iv.size() <= j + 1){
						iv.push_back(vector<pair<int, int>>{{ nums[i], count }});
						break;
					}
					else{
						iv[j + 1].push_back({ nums[i], count });
						break;
					}
				}
				else if (nums[i] == iv[j].back().first) {
					if (j - 1 < 0)
						iv[j][iv[j].size() - 1].second += 1;
					else{
						for (int k = iv[j - 1].size() - 1; k >= 0 && iv[j-1][k].first < nums[i]; --k){
							count += iv[j - 1][k].second;
						}
						iv[j][iv[j].size() - 1].second += j == 0 ? 1 : count;
					}
					break;
				}
				else{
					if (j == 0){
						iv[j].push_back({ nums[i], 1 });
						break;
					}
				}
			}
		}
		int res = 0;
		for (int i = 0; i < iv[iv.size() - 1].size(); ++i){
			res += iv[iv.size() - 1][i].second;
		}
		return res;
	}

};