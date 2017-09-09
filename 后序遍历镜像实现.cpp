struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		TreeNode* newHead = new TreeNode(-1);
		newHead->left = root;
		vector<int> res;
		TreeNode* p = newHead;

		while (p) {
			if (!p->left) {
				p = p->right;
			}
			else {
				TreeNode* tmp = p->left;
				while (tmp->right&&tmp->right != p) {
					tmp = tmp->right;
				}
				if (!tmp->right) {
					tmp->right = p;
					p = p->left;
				}
				else {
					reverseAddNodes(p->left, tmp, res);
					tmp->right = nullptr;
					p = p->right;
				}
			}
		}
		return res;
	}

	void reverseNodes(TreeNode* p, TreeNode* last) {
		if (p == last)
			return;
		TreeNode* x = p, *y = p->right, *z = nullptr;
		x->right = nullptr;
		while (x != last) {
			z = y->right;
			y->right = x;
			x = y;
			y = z;
		}
	}

	void reverseAddNodes(TreeNode* start, TreeNode* end, vector<int>& nodes) {
		reverseNodes(start, end);
		TreeNode* node = end;
		while (true) {
			nodes.push_back(node->val);
			if (node == start) break;
			node = node->right;
		}
		reverseNodes(end, start);
	}
};