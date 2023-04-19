#include <iostream>
#include <string>
#include <map>


class RomanDigit {
public:
	RomanDigit(char d) : mDigit(d) {
	}

	int getInt() {
		return symbolValue.find(mDigit)->second;
	}


	bool operator<(const RomanDigit& s) {
		if ((symbolValue.find(mDigit))->second < (symbolValue.find(s.mDigit)->second)) {
			return true;
		}
		return false;
	}

private:
	char mDigit;

	std::map<char, int> symbolValue{ {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
};

class Solution {
public:
	int romanToInt(const std::string s) {

		int result = RomanDigit(s[s.length() - 1]).getInt();;

		for (int i = 0; i < s.length() - 1; i++) {
			RomanDigit rd(s[i]);
			RomanDigit rdNext(s[i + 1]);
			if (rd < rdNext) {
				result -= rd.getInt();
			}
			else {
				result += rd.getInt();
			}
		}

		return result;
	}

};

int main() {
	std::cout << Solution().romanToInt("MCMXCIV");

	return 0;
}