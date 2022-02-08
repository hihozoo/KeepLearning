# -*- coding: utf-8 -*-
'''
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
'''

'''分治法'''
class Solution(object):
	def longestCommonPrefix(self, strs):
		"""
		:type strs: List[str]
		:rtype: str
		"""
		if not strs:
			return ""
		strslen = len(strs)
		return self.help(strs, 0, strslen)

	def help(self, strs, start, end):
		if end - start == 1:
			return strs[start]
		mid = (start + end) // 2
		c1 = self.help(strs, start, mid)
		c2 = self.help(strs, mid, end)
		i = 0
		while i < len(c1) and i < len(c2):
			if c1[i] != c2[i]:
				break
			i += 1
		return c1[0:i]

class Solution2(object):
	def longestCommonPrefix(self, strs):
		"""
		:type strs: List[str]
		:rtype: str
		"""
		if not strs:
			return ""
		index = 1
		common_prefix = strs[0]
		while index < len(strs):
			common_prefix = self.commonPrefix(common_prefix, strs[index])
			if not common_prefix:
				break
			index += 1
		return common_prefix

	def commonPrefix(self, c1, c2):
		i = 0
		while i < len(c1) and i < len(c2):
			if c1[i] != c2[i]:
				break
			i += 1
		return c1[0:i]

if __name__ == "__main__":
	s = Solution()
	print s.longestCommonPrefix(["flower",])

