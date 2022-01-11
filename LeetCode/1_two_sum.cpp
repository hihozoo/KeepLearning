/**
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
		map<int, int> seed_map;
		for (int i = 0; i < nums.size(); i++){
			int val = nums[i];
			map<int, int>::iterator it = seed_map.find(target - val);
			if (it != seed_map.end()){
				return vector<int>{it->second, i};
			}
			seed_map.insert(pair<int, int>(val, i));
		}
		return vector<int>{};
    }
};

int main(){
	Solution s = Solution();

	vector<int> res = s.twoSum(vector<int>{2, 7, 11, 15}, 9);
	for (auto v: res){
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
