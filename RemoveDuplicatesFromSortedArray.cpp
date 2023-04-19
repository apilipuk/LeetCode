#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
	int removeDuplicates(std::vector<int>& nums) {
		std::unordered_set<int> uset;
		int count = 0;

		for (int i = 0; i < nums.size();i++) {
			if (uset.find(nums[i]) == uset.end()) {
				uset.insert(nums[i]);
				std::swap(nums[i], nums[count++]);
			}
			
		}

		return count;
	}

	//int removeDuplicates(std::vector<int>& nums) {
	//	int count = 1;

	//	for (int i = 1; i < nums.size(); i++) {
	//		if (nums[i]!=nums[i-1]) {
	//			nums[count++] = nums[i];
	//		}
	//	}

	//	return count;
	//}
};

int main() {
	std::vector<int> data{ 0,0,0,0,1,1,1,2,2,3,3,4 };

	std::cout << "k=" << Solution().removeDuplicates(data);

	std::cout << std::endl;

	std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, " "));

	return 0;
}