# -*- coding: utf-8 -*-
'''
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''



class Solution(object):
	def coinChange(self, coins, amount):
		"""
		:type coins: List[int]
		:type amount: int
		:rtype: int
		""" 
		'''
		f(n) = 1 + f(n - c), c 是当前选择的钱币, f(n - c) < 0, f(n) 也是 < 0
		'''
		
		dit = [0 for _ in xrange(amount)]

		def dp(amount):
			if amount < 0: return -1
			if amount == 0: return 0

			if dit[amount - 1] != 0:
				return dit[amount - 1]		

			mini = amount + 1
			for c in coins:
				res = dp(amount - c)
				if res < 0:
					continue
				mini = min(mini, res + 1)

			dit[amount - 1] = mini if mini <= amount else -1
			return dit[amount - 1]

		return dp(amount)

	
if __name__ == "__main__":
	s = Solution()
	print s.coinChange([1, 2, 5], 100)
