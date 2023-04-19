#include<stack>

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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q) {
			return true;
		}

		if (!p) {
			return false;
		}

		if (!q) {
			return false;
		}

		std::stack<std::pair<TreeNode*, TreeNode*>> stack;
		stack.push({ p, q });

		while (!stack.empty()) {
			TreeNode* P = stack.top().first;
			TreeNode* Q = stack.top().second;
			stack.pop();

			if (P->val != Q->val) {
				return false;
			}

			if (P->left && Q->left) {
				stack.push({ P->left, Q->left });
			}
			else if (P->left || Q->left) {
				return false;
			}
			
			if (P->right && Q->right) {
				stack.push({ P->right, Q->right });
			}
			else if (P->right || Q->right) {
				return false;
			}
		}

		return true;
	}


	//bool isSameTree(TreeNode* p, TreeNode* q) {
	//	if (!p && !q) {
	//		return true;
	//	}

	//	return (p && q) && (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	//}
};