/**
 * 给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] 中找出并返回第 n 位上的数字。
*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
		int bitNum = 1;
		int areaCount = 9;

		while (n > (long) bitNum * areaCount){
			n -= bitNum * areaCount;
			bitNum++;
			areaCount *= 10;
		}

		int start = pow(10, bitNum - 1);
		int offset = (n - 1) / bitNum;
		int digit = (n - 1) % bitNum;

		int num = start + offset;

		if (false){
			cout << num << endl;
			cout << start << endl;
			cout << offset << endl;
			cout << digit << endl;
			cout << bitNum << endl;
		}
		return (int)(num / pow(10, bitNum - digit - 1)) % 10;
    }
};

int main(){
	int nth = 0;
	cin >> nth;

	Solution s = Solution();
	cout << s.findNthDigit(nth) << endl;

	return 0;
}