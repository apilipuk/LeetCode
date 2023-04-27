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
    int minDepth(TreeNode *root) {
        int depth = 0;

        if(!root) {
            return depth;
        }

        std::queue<TreeNode *> queue;
        queue.push(root);
        depth++;

        while(!queue.empty()) {
            int size = queue.size();

            while(size--) {
                TreeNode *node = queue.front();
                queue.pop();

                if(isLeaf(node)) {
                    return depth;
                }

                if(node->left) {
                    queue.push(node->left);
                }

                if(node->right) {
                    queue.push(node->right);
                }
            }

            depth++;
        }

        return depth;
    }

    bool isLeaf(TreeNode *node) {
        return !node->left && !node->right;
    }

    // int minDepth(TreeNode *root) {
    //     if(!root) {
    //         return 0;
    //     }

    //     int leftDepth = minDepth(root->left);
    //     int rightDepth = minDepth(root->right);

    //     if(!root->left) {
    //         return 1 + rightDepth;
    //     }

    //     if(!root->right) {
    //         return 1 + leftDepth;
    //     }

    //     return 1 + std::min(minDepth(root->left), minDepth(root->right));
    // }
}