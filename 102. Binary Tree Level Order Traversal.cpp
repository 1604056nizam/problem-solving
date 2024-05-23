/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> subResult;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = q.front();
                q.pop();
                subResult.push_back(currentNode->val);
                if (currentNode->left) q.push(currentNode->left);
                if (currentNode->right) q.push(currentNode->right);
            }
            if (subResult.size() > 0)
                result.push_back(subResult);
        }

        return result;
    }
};