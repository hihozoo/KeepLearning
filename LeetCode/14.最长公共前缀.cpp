#include <string>
#include <vector>

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
};