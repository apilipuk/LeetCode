#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if(!root) {
            return false;
        }

        int remain = targetSum - root->val;

        if(!remain && !root->left && !root->right) {
            return true;
        }

        return hasPathSum(root->left, remain) || hasPathSum(root->right, remain);
    }
}
