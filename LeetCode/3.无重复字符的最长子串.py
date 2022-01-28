class Solution(object):
	# 滑动窗口
    def lengthOfLongestSubstring(self, s):
        max_len = 0
        i = 0
        j = 0
        while j < len(s):
            while s[j] in s[i:j]:
                i += 1
            j += 1
            max_len = max(max_len, j - i)
        return max_len
