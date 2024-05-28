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
    vector<int> subResult;

    void helperFunc(TreeNode* root, int targetSum) {

        if (!root)
            return;

        subResult.push_back(root->val);

        if (!root->left && !root->right) {
            if (root->val == targetSum)
                result.push_back(subResult);

        } else {
            helperFunc(root->left, targetSum - root->val);
            helperFunc(root->right, targetSum - root->val);
        }

        subResult.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        helperFunc(root, targetSum);
        return result;
    }
};