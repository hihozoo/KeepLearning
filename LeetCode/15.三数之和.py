# -*- coding: utf-8 -*-
'''
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''
class Solution(object):
	'''
	'''
	def threeSum(self, nums):
		"""
		:type nums: List[int]
		:rtype: List[List[int]]
		"""
		nums.sort()

		l = len(nums)
		i = 0

		ret = []
		while i < l:
			ret.extend(self.twoSum(nums, -nums[i], i + 1))
			old = nums[i]
			while i < l and nums[i] == old:
				i += 1
		return nums

	def twoSum(self, nums, tgt, start):
		lo, hi = start, len(nums) - 1
		ret = []
		while lo < hi:
			tmp = nums[lo] + nums[hi]
			if tmp < tgt:
				lo += 1
			elif tmp > tgt:
				hi -= 1
			else:
				left = nums[lo]
				right = nums[hi]
				ret.append([-tgt, left, right])
				while hi > lo and nums[lo] == left:
					lo += 1
				while hi > lo and nums[hi] == right:
					hi -= 1
		return ret

