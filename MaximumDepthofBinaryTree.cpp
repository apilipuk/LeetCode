#include <iostream>
#include <queue>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root) {
			return 0;
		}

		std::queue<TreeNode*> queue;
		queue.push(root);

		int depth = 0;
		TreeNode* front = nullptr;

		while (!queue.empty()) {
			int size = queue.size();

			while (size--) {
				front = queue.front();
				queue.pop();

				if (front->left) {
					queue.push(front->left);
				}

				if (front->right) {
					queue.push(front->right);
				}
			}

			depth++;
		}

		return depth;
	}

	//int maxDepth(TreeNode* root) {
	//	if (!root) {
	//		return 0;
	//	}
	//
	//	return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
	//}
};