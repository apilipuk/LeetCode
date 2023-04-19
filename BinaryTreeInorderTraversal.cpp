#include<vector>
#include<queue>
#include<stack>

//Definition for a binary tree node.
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
	std::vector<int> inorderTraversal(TreeNode* root) {				//DSF iterative inorder=stack
		std::vector<int> result;
		std::stack<TreeNode*> stack;

		TreeNode* curr = root;

		while (!stack.empty() || curr) {
			if (curr) {
				stack.push(curr);
				curr = curr->left;
			}
			else {
				curr = stack.top();
				stack.pop();
				result.push_back(curr->val);
				curr = curr->right;
			}
		}

		return result;
	}

	//std::vector<int> result;										//BSF iterative levelorder=queue
	//
	//std::vector<int> inorderTraversal(TreeNode* root) {
	//	std::queue<TreeNode*> queue;
	//	if (!root) {
	//		return result;
	//	}
	//
	//	queue.push(root);
	//
	//	while (!queue.empty()) {
	//		TreeNode* temp= queue.front();
	//		result.push_back(temp->val);
	//		queue.pop();
	//
	//		if (temp->left) {
	//			queue.push(temp->left);
	//		}
	//		
	//
	//		if (temp->right) {
	//			queue.push(temp->right);
	//		}
	//	}
	//
	//	return result;
	//}

//public:
//	std::vector<int> inorderTraversal(TreeNode* root) {			//DSF recursion inorder 
//		std::vector<int> result;
//		get(root, result);
//
//		return result;
//	}
//
//private:
//	void get(const TreeNode* tree, std::vector<int>& res) {
//		if (tree) {
//			res.push_back(tree->val);
//			get(tree->left, res);
//			get(tree->right, res);
//		}
//	}
//};