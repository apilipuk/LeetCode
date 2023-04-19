#include <vector>
#include <iostream>

class Solution {
public:
	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
		int i = m - 1;
		int j = n - 1;
		int max = m + n - 1;

		while (i >=0 && j >= 0) {
			if (nums1[i] > nums2[j]) {
				nums1[max--] = nums1[i--];
			}
			else {
				nums1[max--] = nums2[j--];
			}
		}

		while (i >= 0) {
			nums1[max--] = nums1[i--];
		}
		
		while (j >= 0) {
			nums1[max--] = nums2[j--];
		}
	}
};

int main() {
	std::vector<int> nums1{ 1,2,3,0,0,0 };
	std::vector<int> nums2{ 2,5,6 };

	Solution().merge(nums1, 3, nums2, 3);


	std::copy(nums1.begin(), nums1.end(), std::ostream_iterator<int>(std::cout, " "));

	return 0;
}