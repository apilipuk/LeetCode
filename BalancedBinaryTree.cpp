#include <algorithm>
#include <cmath>
#include <stack>

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
    bool isBalanced(TreeNode *root) {
        bool result = true;

        isHeightBalanced(root, result);

        return result;
    }

   private:
    int isHeightBalanced(TreeNode *node, bool &res) {
        if(!node || !res) {
            return 0;
        }

        int leftHeight = isHeightBalanced(node->left, res);
        int rightHeight = isHeightBalanced(node->right, res);

        if(abs(leftHeight - rightHeight) > 1) {
            res = false;
        }

        return 1 + max(leftHeight, rightHeight);
    }

    //    public:
    //     bool isBalanced(TreeNode *root) {
    //         std::stack<TreeNode *> stack;

    //         TreeNode *curr = root;

    //         while(!stack.empty() || curr) {
    //             if(curr) {
    //                 stack.push(curr);
    //                 curr = curr->left;
    //             } else {
    //                 curr = stack.top();
    //                 stack.pop();

    //                 if(abs(maxDepth(curr->left) - maxDepth(curr->right)) > 1) {
    //                     return false;
    //                 }

    //                 curr = curr->right;
    //             }
    //         }

    //         return true;
    //     }

    //    private:
    //     int
    //     maxDepth(TreeNode *root) {
    //         if(!root) {
    //             return 0;
    //         }

    //         return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    //     }
};