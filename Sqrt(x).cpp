#include <iostream>

class Solution {
public:
	int mySqrt(int x) {
		int result = 0;
		int lastresult = 0;
		int left = 0;
		int right = x;

		while (left <= right) {
			result = left + (right - left) / 2;
			if (result * result == x) {
				return result;
			}

			if (result * result < x) {
				left = result + 1;
			}
			else {
				right = result - 1;
			}
			lastresult = result;
		}

		return right;
	}
};

int main() {
	std::cout << Solution().mySqrt(1);


	return 0;
}