#include <vector>
#include <iostream>

class Solution {
public:
	//std::vector<int> getConcatenation(std::vector<int>& nums) {
	//	std::vector<int> ans;
	//	std::copy(nums.begin(), nums.end(), std::back_inserter(ans));
	//	std::copy(nums.begin(), nums.end(), std::back_inserter(ans));

	//	return ans;
	//}

	//std::vector<int> getConcatenation(std::vector<int>& nums) {

	//	std::vector <int> ans = nums;

	//	for (int i = 0; i < nums.size(); i++) {
	//		ans.push_back(nums[i]);
	//	}

	//	return ans;
	//}

	std::vector<int> getConcatenation(std::vector<int>& nums) {
		std::vector<int> ans(nums.size() * 2);

		for (int i = 0; i < nums.size(); i++) {
			ans[i + nums.size()] = ans[i] = nums[i];
		}

		return ans;
	}
};

int main() {
	std::vector<int> data{ 1, 2, 3 };

	std::vector<int> ans = Solution().getConcatenation(data);

	std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));

	return 0;
}