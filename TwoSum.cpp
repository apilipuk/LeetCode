// TwoSum.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		//	std::vector<int>::iterator iter0 = nums.begin();
		//	std::vector<int>::iterator iter1 = nums.begin();
		//	std::vector<int>::iterator iter2 = nums.end();

		//	while (iter2 == nums.end() && iter1 != nums.end()) {
		//		iter0 = iter1;
		//		iter2 = std::find(++iter1, nums.end(), target - *iter1);
		//	}

		//	int first_pos = iter0 - nums.begin();
		//	int second_pos = iter2 - nums.begin(); 

		//	return std::vector<int> {first_pos, second_pos};
		//}

		std::unordered_map<int, int> umap;
		for (int i = 0; i < nums.size(); i++) {
			std::unordered_map<int, int>::const_iterator citer = umap.find(target - nums[i]);
			if (citer != umap.cend()) {
				return { citer->second, i };
			}
			else
			{
				umap.insert({ nums[i], i });
			}
		}
	}
};

int main()
{
	std::vector<int> nums = { 3,2,4 };
	int target = 6;

	std::vector<int> res = Solution().twoSum(nums, target);

	std::cout << res[0] << ", " << res[1];

	int x; 
	return 0;
}