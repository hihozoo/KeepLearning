# -*- coding: utf-8 -*-
# 给你一个字符串 s，找到 s 中最长的回文子串。
# 暴力破解
import collections

class Solution(object):
	def longestPalindrome(self, s):
		max_len = 0
		max_len_str = ""

		str_len = len(s)
		i = 0

		while i < str_len:
			j = i + 1
			while j <= str_len:
				if not self.isPalindrome(s[i: j]):
					break
				if j - i > max_len:
					max_len = j - i
					max_len_str = s[i:j]
				j += 1
			i += 1
		return max_len_str

	def isPalindrome(self, s):
		i = 0
		j = len(s) - 1
		while i < j:
			if s[i] != s[j]:
				return False
			i += 1
			j -= 1
		return True


class SolutionDP(object):
	def longestPalindrome(self, s):
		str_len = len(s)
		
		dp = [[0 for _ in xrange(str_len)] for _ in xrange(str_len)]

		max_len = 0
		max_beg = 0

		ln = 1
		while ln <= str_len:
			i = 0
			while i < str_len:
				j = ln + i - 1
	
				if j >= str_len:
					break
				if s[i] != s[j]:
					dp[i][j] = False
				else:
					if j - i < 3:
						dp[i][j] = True
					else:
						dp[i][j] = dp[i + 1][j - 1]

				if dp[i][j] and j - i + 1 > max_len:
					max_len = j - i + 1
					max_beg = i
				i += 1

			ln += 1
		return s[max_beg: max_beg + max_len]
