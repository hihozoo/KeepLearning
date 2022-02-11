class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int> > ans;
		vector<int> path;
		path.reserve(nums.size());
		permute(ans, path, nums, nums.size());
		return ans;
    }

	void permute(vector<vector<int> >& ans, vector<int> &path, vector<int>& nums, const int& size){
		if (size <= 0){
			ans.push_back(path);
			return;
		}
		int i = 0;
		while (i < size){
			int val = nums[i];
			swap(nums[i], nums[size - 1]);
			path.push_back(val);
			permute(ans, path, nums, size - 1);
			path.pop_back();
			swap(nums[i], nums[size - 1]);
			i++;
		}
	}
};