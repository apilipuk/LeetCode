#include <iostream>
#include <vector>

class Solution {
public:
	int removeElement(std::vector<int>& nums, int val) {
		int count = 0;
		int i = 0;

		while (i < nums.size() - count)
		{
			if (nums[i] == val) {
				std::swap(nums[i], nums[nums.size()-++count]);
			}
			else {
				i++;
			}
		}

		return nums.size() - count;
	}
};

int main() {

	std::vector<int> data{ 0,1,2,2,3,0,4,2 };

	std::cout << "k=" << Solution().removeElement(data, 2);

	std::cout << std::endl;

	std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, " "));

	return 0;
}