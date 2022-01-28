/**
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
*/

#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int i = 0;
		int j = 0;
		int str_len = s.length();
		int max_len = 0;
		unordered_set<char> set;
		while (j < str_len){
			while (i < j && set.count(s[j]) > 0){
				set.erase(s[i]);
				i++;
			}
			set.insert(s[j]);
			j++;
			max_len = max(max_len, j - i);
		}
		return max_len;
    }
};