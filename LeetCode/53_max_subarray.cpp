/**
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。
*/

/**
 * 假设 f(i) 表示以下标 i 结尾的最大子数组和
 * 那么原问题就可以转换成求出所有 f(i)，然后在里面求最大值
*/
#include <cmath>
using namespace std;

int max(const int& a, const int&b){
	return a > b ? a: b;
}
int maxSubArray(int* nums, int numsSize){
	int maxSum = nums[0];
	int pre = 0;

	for (int i = 0; i < numsSize; i++){
		pre = max(pre + nums[i], nums[i]);
		maxSum = max(pre, maxSum);
	}
	return maxSum;
}

int main(){
	return 0;
}