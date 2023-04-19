#include <string>
#include <iostream>
#include <algorithm>


class Solution {
public:
	std::string addBinary(std::string a, std::string b) {
		std::reverse(a.begin(), a.end());
		std::reverse(b.begin(), b.end());
		std::string result = "";
		int remain = 0;

		for (int i = 0; i < std::max(a.size(), b.size()); i++) {
			int A = i < a.size() ? a[i] - '0' : 0;
			int B = i < b.size() ? b[i] - '0' : 0;

			int val = A + B + remain;

			result.push_back(val % 2+'0');

			remain = val > 1 ? 1 : 0;
		}

		if (remain) {
			result.push_back(remain + '0');
		}

		std::reverse(result.begin(), result.end());

		return result;
	}
};

int main() {
	std::cout << Solution().addBinary("11", "1")<<std::endl;

	return 0;
}