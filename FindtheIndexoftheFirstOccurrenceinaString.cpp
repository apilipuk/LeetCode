#include <iostream>
#include <string>

class Solution {
public:
	int strStr(std::string haystack, std::string needle) {
		int h = haystack.size();
		int n = needle.size();

		for (int i = 0; i < h - n + 1; i++) {
			int j = 0;
			while (j < n && haystack[i + j] == needle[j]) {
				if (j == n - 1) {
					return i;
				}
				else {
					j++;
				}
			}
		}

		return -1;
	}
};