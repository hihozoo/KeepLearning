# -*- coding: utf-8 -*-
'''
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''

class Solution(object):
	def maxArea(self, height):
		"""
		:type height: List[int]
		:rtype: int
		"""
		area = 0
		for i in xrange(len(height)):
			for j in xrange(i + 1, len(height)):
				tmp = (j - i) * min(height[i], height[j])
				area = max(tmp, area)
		return area

# 双指针
class Solution2(object):
	def maxArea(self, height):
		i = 0
		j = len(height) - 1

		ret = 0
		while i < j:
			ret = max(ret, (j - i) * min(height[i], height[j]))
			if height[i] < height[j]:
				i += 1
			else:
				j -= 1
		return ret
