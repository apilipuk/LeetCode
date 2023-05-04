#include <stack>
#include <vector>

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
    std::vector<int> preorderTraversal(TreeNode *root) {
        std::vector<int> result;

        if(!root) {
            return result;
        }

        std::stack<TreeNode *> stack;
        stack.push(root);

        while(!stack.empty()) {
            TreeNode *node = stack.top();
            stack.pop();

            result.push_back(node->val);

            if(node->right) {
                stack.push(node->right);
            }

            if(node->left) {
                stack.push(node->left);
            }
        }

        return result;
    }
};