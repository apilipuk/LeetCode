#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
	int lengthOfLastWord(std::string s) {
		int result = 0;
		int i = s.size() - 1;

		while (i >= 0 && s[i] == ' ') {
			i--;
		}

		while (i >= 0 && s[i] != ' ') {
			result++;
			i--;
		}

		return result;
	}
};

int main() {
	std::cout << Solution().lengthOfLastWord("a");

	return 0;
}