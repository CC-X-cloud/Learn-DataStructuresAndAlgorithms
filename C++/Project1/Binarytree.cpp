#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (!root) return res;

		std::stack<TreeNode*> stk;
		stk.push(root);

		while (!stk.empty()) {
			TreeNode* node = stk.top();
			stk.pop();
			res.push_back(node->val); // 前序遍历，先访问根节点

			if (node->right) stk.push(node->right); // 先右后左，保证左子树先被访问
			if (node->left) stk.push(node->left);
		}
		return res;
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		std::stack<TreeNode*> st;
		TreeNode* curr = root;
		while (curr != nullptr || !st.empty()) {
			while (curr != nullptr) {
				st.push(curr);
				curr = curr->left;
			}
			curr = st.top();
			st.pop();
			res.push_back(curr->val); // 中序遍历，访问根节点
			curr = curr->right;
		}
		return res;
	}
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		if (!root) return res;
		std::stack<TreeNode*> st;

		TreeNode* curr = root;
		TreeNode* prev = nullptr;

		while (curr != nullptr || !st.empty()) {
			while (curr != nullptr) {
				st.push(curr);
				curr = curr->left;
			}

			curr = st.top();

			if(curr -> right == nullptr || curr->right == prev) {
				res.push_back(curr->val); // 后序遍历，访问根节点
				st.pop();
				prev = curr;
				curr = nullptr; // 防止再次进入左子树
			} else {
				curr = curr->right;
			}
		}
		return res;
	}

	//层序遍历
	vector<int> levelOrder(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) return res;

		std::queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop();
			res.push_back(node->val);

			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
		return res;
	}
	//层序遍历按层输出
	vector<vector<int>> levelOrderByLevel(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr) return res;

		std::queue<TreeNode*> q;
		q.push(root);
		while (q.empty()) {
			
			vector<int> level;
			int size = q.size();

			for(int i= 0;i< size;i++) {
				TreeNode* node = q.front();
				q.pop();
				level.push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			res.push_back(level);

		}
		return res;
	}
	//层序遍历哈希表存储
	vector<vector<int>> levelOrderByHash(TreeNode* root) {
		std::vector<std::vector<int>> result;
		if (!root) return result;

		std::queue<TreeNode*> q;
		std::unordered_map<TreeNode*, int> depthMap; // 1. 哈希表：节点指针 -> 深度

		q.push(root);
		depthMap[root] = 0; // 根节点深度为 0

		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop();

			int depth = depthMap[node]; // 2. 从哈希表获取当前节点深度

			// 3. 如果 result 还没有这一层的容器，则创建一个新的
			if (result.size() == depth) {
				result.push_back(std::vector<int>());
			}
			result[depth].push_back(node->val); // 4. 放入对应层的数组中

			// 5. 子节点入队，并在哈希表中记录其深度为 父节点深度 + 1
			if (node->left) {
				depthMap[node->left] = depth + 1;
				q.push(node->left);
			}
			if (node->right) {
				depthMap[node->right] = depth + 1;
				q.push(node->right);
			}
		}
		return result;
	}
	//层序遍历滚动更新
	vector<vector<int>> levelOrderByRollingUpdate(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr) return res;

		TreeNode* curEnd = root; // 当前层的最后一个节点
		TreeNode* nextEnd = nullptr; // 下一层的最后一个节点

		std::queue<TreeNode*> q;
		q.push(root);
		
		while (!q.empty()) {
			std::vector<int> level;
			
			TreeNode* node = q.front();
			q.pop();
			level.push_back(node->val);

			if (node->left) {
				q.push(node->left);
				nextEnd = node->left; // 更新下一层的最后一个节点
			}
			if(node -> right) {
				q.push(node->right);
				nextEnd = node->right; // 更新下一层的最后一个节点
			}
			if (node == curEnd) {
				res.push_back(level);
				curEnd = nextEnd;
			}
		}
		return res;
	}
	//搜索二叉树判断
	bool isVailTree(TreeNode* root) {
		vector<long long> vals;
		inorder(vals, root);
		int size = vals.size();
		for (int i = 0; i < size - 1; i++) {
			if (vals[i] > vals[i + 1]) {
				return false;
			}
		}
		return true;
	}
	void inorder(vector<long long>& vals,TreeNode* root) {
		if (root == nullptr) return;

		inorder(vals,root->left);
		vals.push_back(root->val);
		inorder(vals, root->right);
	}
	bool inorderv2(TreeNode* root) {
		if (root == nullptr) return true;
		TreeNode* pre = nullptr;
		if(!inorderv2(root->left)) return false;
		if (pre != nullptr && pre->val > root->val) {
			return false;
		}
		pre = root;
		inorderv2(root->right);
	}
	bool inorderv3(TreeNode* root) {
		std::stack<TreeNode*> st;
		st.push(root);

		TreeNode* cur = root;
		TreeNode* pre = nullptr;
		while (!st.empty()) {
			while (!cur) {
				st.push(cur);
				cur = cur->left;
			}
			cur = st.top();
			st.pop();
			//处理
			if (!pre && pre->val > cur->val) {
				return false;
			}
			pre = cur;
			cur = cur->right;
		}
		return true;
	}

};