#include <stack>
#include <vector>
#include <algorithm>

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
    std::vector<int> postorderTraversal(TreeNode *root) {
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

            if(node->left) {
                stack.push(node->left);
            }

            if(node->right) {
                stack.push(node->right);
            }
            
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};

// class Solution {
//    public:
//     std::vector<int> postorderTraversal(TreeNode *root) {
//         std::vector<int> result;

//         if(!root) {
//             return result;
//         }

//         std::stack<TreeNode *> stack;
//         stack.push(root);

//         while(!stack.empty()) {
//             TreeNode *node = stack.top();
//             stack.pop();

//             result.push_back(node->val);

//             if(node->left) {
//                 stack.push(node->left);
//             }

//             if(node->right) {
//                 stack.push(node->right);
//             }
            
//         }

//         std::reverse(result.begin(), result.end());

//         return result;
//     }
// };