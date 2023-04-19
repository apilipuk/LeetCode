#include <iostream>
#include <vector>
//#include <algorithm>

class Solution {
public:
	std::vector<int> plusOne(std::vector<int>& digits) {
		digits[digits.size() - 1]++;
		std::vector<int> result;
		int remain = 0;

		for (int i = digits.size() - 1; i >= 0; i--) {
			int d = digits[i] + remain;
			if (d > 9) {
				result.push_back(d-10);
				remain = 1;
			}
			else {
				result.push_back(d);
				remain = 0;
			}
		}

		if (remain) {
			result.push_back(remain);
		}

		std::reverse(result.begin(), result.end());

		return result;
	}
};