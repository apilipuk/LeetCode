#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(std::vector<int> &nums)
    {
        return makeNode(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *makeNode(std::vector<int> &nums, int first, int last)
    {
        if (first > last)
        {
            return nullptr;
        }

        int mid = (first + last) / 2;

        return new TreeNode (nums[mid], makeNode(nums, first, mid - 1), makeNode(nums, mid + 1, last));
    }

    // public:
    //     TreeNode *sortedArrayToBST(std::vector<int> &nums)
    //     {
    //         TreeNode *root = nullptr;

    //         makeNode(nums, 0, nums.size() - 1, root);

    //         return root;
    //     }

    // private:
    //     void makeNode(std::vector<int> &nums, int first, int last, TreeNode *&node)
    //     {
    //         if (first > last)
    //         {
    //             return;
    //         }

    //         int mid = (first + last) / 2;

    //         node = new TreeNode(nums[mid]);

    //         makeNode(nums, first, mid - 1, node->left);

    //         makeNode(nums, mid + 1, last, node->right);
    //     }
};