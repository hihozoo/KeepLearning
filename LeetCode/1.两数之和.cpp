#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());

	int lo, hi = 0, nums.size() - 1;

	while (lo < hi){
		int sum = nums[lo] + nums[hi];
		if (sum < target){
			lo++;
		}else if (sum > target){
			hi--;
		}else{
			return {nums[lo], nums[hi]};
		}
	}
	return {};
}

vector<vector<int> > twoSumAll(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());

	int lo, hi = 0, nums.size() - 1;
	vector<vector<int> > ans;
	while (lo < hi){
		int sum = nums[lo] + nums[hi];
		if (sum < target){
			lo++;
		}else if (sum > target){
			hi--;
		}else{
			int left = nums[lo];
			int right = nums[hi];

			ans.push_back(left, right);

			while (left == nums[lo]){
				lo++;
			}
			while (right == nums[hi]){
				hi--;
			}
		}
	}
	return {};
}