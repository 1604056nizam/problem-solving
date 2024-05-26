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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;

        return buildSubtree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
    }

    TreeNode* buildSubtree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorderMap) {

        if (preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int indexOfRootInorder = inorderMap[root->val];
        int leftTreeSize = indexOfRootInorder - inStart;

        root->left = buildSubtree(preorder, preStart + 1, preStart + leftTreeSize, inorder, inStart, indexOfRootInorder - 1, inorderMap);
        root->right = buildSubtree(preorder, preStart + leftTreeSize + 1, preEnd, inorder, indexOfRootInorder + 1, inEnd, inorderMap);

        return root;
    }
};