#include <vector>

class Solution {
   public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0;

        for(int i = 0; i < nums.size(); i++) {
            result ^= nums[i];
        }

        return result;
    }
};

// #include <vector>
// #include <unordered_set>

// class Solution {
//    public:
//     int singleNumber(vector<int>& nums) {
//         std::unordered_set<int> uset;

//         for(int i = 0; i < nums.size(); i++) {
//             std::unordered_set<int>::iterator iter = uset.find(nums[i]);

//             if(iter != uset.end()) {
//                 uset.erase(iter);
//             } else {
//                 uset.insert(nums[i]);
//             }
//         }

//         return *uset.begin();
//     }
// };

// #include <vector>
// #include <algorithm>

// class Solution {
//    public:
//     int singleNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         for(int i = 0; i < nums.size() - 1; i + 2) {
//             if(nums[i] - nums[i + 1]) {
//                 return nums[i];
//             }
//         }

//         return nums[nums.size() - 1];
//     }
// };