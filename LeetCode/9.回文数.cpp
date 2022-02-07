class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0){
			return false;
		}
		int x2 = x;
		int y = 0;
		while (x2 != 0){
			y = y * 10 + x2 % 10;
			x2 = (int)(x2 / 10);
		}
		return x == y;
    }
};