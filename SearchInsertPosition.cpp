#include <vector>
#include <iostream>

class Solution {
public:
	int searchInsert(std::vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;

		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			if (nums[mid] < target) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		return left;
	}
};

int main() {
	std::vector<int> data{ 1, 3, 5, 6 };

	std::cout << Solution().searchInsert(data, 2);

	return 0;
}

//Input: nums = [1, 3, 5, 6], target = 7
//Output : 4

//Input: nums = [1, 3, 5, 6], target = 2
//Output : 1