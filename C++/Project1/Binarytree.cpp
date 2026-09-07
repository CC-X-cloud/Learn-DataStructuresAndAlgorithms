#include <iostream>
#include <vector>

using namespace std;

class BinaryTree {
public:
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};
	// 递归序遍历
	/* 递归序遍历的本质是函数的调用栈，函数的调用顺序就是递归序遍历的顺序
		递归序的来历：
		函数1进入发现Root不为空，压入栈，记一次经过
		执行子函数1（看左树），假设左子树为空，返回到上一个函数，继续执行函数1，记第二次经过
		执行子函数2（看右树），假设右子树为空，返回到上一个函数，继续执行函数1，记第三次经过
		其中第一次经过就是前序，第二次经过就是中序，第三次经过就是后序
	*/
	void RePreorderTraversal(TreeNode* root, vector<int>& result) {
		if (!root) return;
		//前序
		result.push_back(root->val);
		RePreorderTraversal(root->left, result);
		//中序写这里
		RePreorderTraversal(root->right, result);
		//后序写这里
	}

	//代码模拟前中后序遍历
};