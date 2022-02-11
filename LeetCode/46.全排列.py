# -*- coding: utf-8 -*-
'''
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
'''

class Solution(object):
	def permute(self, nums):
		"""
		:type nums: List[int]
		:rtype: List[List[int]]
		"""

		'''
		nums 是选择列表，从中选择一个数，选择列表就少了一个数
		然后向前继续进行排列
		'''

		ans = []

		def do(path, num):
			if not num:
				ans.append(list(path))
				return
			nlen = len(num)
			while nlen > 0:
				nlen -= 1
				val = num.pop(0)
				path.append(val)
				do(path, num)
				num.append(val)
				path.remove(val)
		do([], nums)
		return ans

if __name__ == "__main__":
	s = Solution()
	ans = s.permute([1, 2, 3, 4])
	print len(ans)
