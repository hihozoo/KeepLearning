/**
 * 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
		// f(n) = 求和< f(m - 1) * f(n - m), m 从 1 -> n
		vector<int> result(n + 1, 0);	
		result[0] = 1;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= i; j++){
				result[i] += result[j - 1] * result[i - j];
			}
		}
		return result[n];
	}

	// 超时了
	int numTrees(int left, int right){
		if (left > right){
			return 0;
		}
		int num = 0;
		for (int i = left; i <= right; i++){
			int ln = numTrees(left, i - 1);
			int rn = numTrees(i + 1, right);

			num += max(ln, 1) * max(rn, 1);
		}
		return num;
	}
};

