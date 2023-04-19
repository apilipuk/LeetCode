#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
	bool isValid(std::string s) {
		std::stack<char> result;
		std::string brackets = "({[]})";

		for (int i = 0; i < s.size(); i++) {
			int bracketsPos = brackets.find(s[i]);
			if (bracketsPos < brackets.size() / 2) {
				result.push(brackets[brackets.size() - 1 - bracketsPos]);
			}
			else {
				if (!result.empty() && result.top() == s[i]) {
					result.pop();
				}
				else {
					return false;
				}
			}
		}

		return result.empty();
	};
};

int main() {
	if (Solution().isValid("(([{}]))")) {
		std::cout << "true";
	}
	else {
		std::cout << "false";
	}

	return 0;
}