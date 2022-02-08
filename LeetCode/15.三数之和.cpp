#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		vector<vector<int>> ans;
		for (int i = 0, cnt = nums.size(); i < cnt;){
			int cur = nums[i];
			this->twoSum(nums, -cur, i + 1, ans);
			while (++i < cnt && cur == nums[i]);
		}
		return ans;
    }

	// 如何避免返回值拷贝？
	void twoSum(vector<int>& nums, const int& tgt, const int& start, vector<vector<int>>& ans){
		int lo = start;
		int hi = nums.size() - 1;
		while (lo < hi){
			int tmp = nums[lo] + nums[hi];
			if (tmp < tgt){
				lo++;
			}else if (tmp > tgt){
				hi--;
			}else{
				int left = nums[lo];
				int right = nums[hi];
				ans.push_back({-tgt, left, right});

				while (++lo < hi && left == nums[lo]);
				while (lo < --hi && right == nums[hi]);
			}
		}
	}
};