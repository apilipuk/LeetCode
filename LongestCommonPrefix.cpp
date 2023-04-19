#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) {
		std::string prefix = "";

		if (strs.size() < 1) {
			return prefix;
		}

		if (strs.size() == 1) {
			prefix = strs[0];
			return prefix;
		}

		int i = 0;
		int length = strs[0].size() < strs[1].size() ? strs[0].size() : strs[1].size();

		while (strs[0][i] == strs[1][i] && i < length) {
			prefix.push_back(strs[0][i++]);
		}

		int j = 2;

		while (!prefix.empty() && j < strs.size()) {
			while (!prefix.empty() && strs[j].find(prefix) != 0) {
				prefix.pop_back();
			}
			j++;
		}

		return prefix;
	};
};

int main() {
	std::vector<std::string> s = { "baab","bacb","b" }; 
	//

	std::cout << Solution().longestCommonPrefix(s);

	return 0;
}