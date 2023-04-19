#include <iostream>
#include <string>

class Solution {
public:
	bool isPalindrome(int x) {
		//std::string s = std::to_string(x);

		//for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
		//    if (s[i] != s[j]) {
		//        return false;
		//    }
		//}

		//return true;

		std::string s = std::to_string(x);
		std::string sBegin = s.substr(0, s.size() / 2);
		std::string sEnd = s.substr(s.size() - sBegin.size(), sBegin.size());
		std::reverse(sEnd.begin(), sEnd.end());

		return sBegin == sEnd;
	}
};

int main()
{
	std::cout << (Solution().isPalindrome(102301) ? "yes" : "no");
}