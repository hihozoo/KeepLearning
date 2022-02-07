#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		int slen = s.length();
		bool dp[slen][slen];

		int max_len = 0;
		int max_beg = 0;
		for (int len = 1; len <= slen; len++){
			for (int i = 0; i < slen; i++){
				int j = i + len - 1;
				if (j >= slen){
					break;
				}

				if (s[i] != s[j]){
					dp[i][j] = false;
				}else{
					if (j - i < 3){
						dp[i][j] = true;
					}else{
						dp[i][j] = dp[i + 1][j - 1];
					}
				}
				if (dp[i][j] && (j - i + 1) > max_len){
					max_len = j - i + 1;
					max_beg = i;
				}
			}
		}
		return s.substr(max_beg, max_len);
    }
};