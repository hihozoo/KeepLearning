# -*- coding: utf-8 -*-
'''
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''

class Solution(object):
	def reverse(self, x):
		INT_MAX = 2**31 - 1
		INT_MIN = -2**31

		y = 0
		while x != 0:
			if y < INT_MIN // 10 + 1:
				return 0
			if y > INT_MAX // 10:
				return 0
			d = x % 10
			if x < 0 and d > 0:
				d -= 10
			y = y * 10 + d
			x = (x - d) // 10
		
		return y


if __name__ == "__main__":
	s = Solution()
	while True:
		i = input()
		s.reverse(i)

