#include<iostream>

class Solution {
public:
	int climbStairs(int n) {
		if (n < 2) {
			return n;
		}

		int cur = 1;
		int prev = 0;

		for (int i = 0; i < n; i++) {
			int temp = cur;
			cur += prev;
			prev = temp;
		}

		return cur;
	}
};

int main() {
	std::cout << Solution().climbStairs(0);

	return 0;
}