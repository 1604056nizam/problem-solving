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
    int helper(TreeNode* root, int num) {
        if (!root)
            return 0;

        num = num * 10 + root->val;

        if (!root->left && !root->right)
            return num;


        int leftSum = helper(root->left, num);
        int rightSum = helper(root->right, num);

        return (leftSum + rightSum);
    }
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        return helper(root, 0);
    }
};