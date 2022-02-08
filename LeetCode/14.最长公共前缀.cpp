#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() <= 0){
			return "";
		}
		return commonPrefix(strs, 0, strs.size());
    }

	string commonPrefix(vector<string>& strs, const int start, const int end){
		if (start - end == 1){
			return strs[start];
		}
		int mid = (int)((start + end) / 2);
		string c1 = commonPrefix(strs, start, mid);
		string c2 = commonPrefix(strs, mid, end);
		int i = 0;
		while (i < c1.length() && i < c2.length()){
			if (c1[i] != c2[i]){
				break;
			}
			i++;
		}
		return c1.substr(0, i);
	}

	string longestCommonPrefix2(vector<string>& strs){
		if (strs.size() <= 0){
			return "";
		}
		string common = strs[0];
		int z = common.length();
		for (int i = 1, c = strs.size(); i < c; i++){
			string& cur_str = strs[i];

			int m = z > cur_str.length() ? cur_str.length(): z;
			int j = 0;
			while (j < m && common[j] == cur_str[j]){
				j++;
			}
			if (j < z){
				z = j;
			}
			if (z == 0){
				break;
			}
		}
		return common.substr(0, z);
	}
};