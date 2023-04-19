#include <stack>
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
	bool isSymmetric(TreeNode* root) {
		if (!root) {
			return true;
		}
		
		if (!root->left && !root->right) {
			return true;
		}

		if (!root->left) {
			return false;
		}

		if (!root->right) {
			return false;
		}

		std::stack<std::pair<TreeNode*, TreeNode*>> stack;
		stack.push({ root->left, root->right });

		while (!stack.empty()) {
			TreeNode* l = stack.top().first;
			TreeNode* r = stack.top().second;
			stack.pop();

			if (r->val != l->val) {
				return false;
			}

			if (l->left && r->right) {
				stack.push({ l->left, r->right });
			}
			else if (l->left || r->right) {
				return false;
			}

			if (l->right && r->left) {
				stack.push({ l->right, r->left });
			}
			else if (l->right || r->left) {
				return false;
			}
		}

		return true;
	}


	//	bool isSymmetric(TreeNode* root) {
	//		if (!root) {
	//			return true;
	//		}
	//
	//		return isMirror(root->left, root->right);
	//	}
	//
	//private:
	//	bool isMirror(TreeNode* l, TreeNode* r) {
	//		if (!l && !r) {
	//			return true;
	//		}
	//
	//		if (!l || !r) {
	//			return false;
	//		}
	//
	//		return (l && r) && (l->val == r->val) && isMirror(l->left, r->right) && isMirror(l->right, r->left);
	//	}
};