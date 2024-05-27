/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;

        for(int i= 0; i < postorder.size(); i++) inorderMap[inorder[i]] = i;

        return buildSubtree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inorderMap);
    }

    TreeNode* buildSubtree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& inorderMap) {

        if(inStart > inEnd || postStart > postEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int rootIndexInInorder = inorderMap[root->val];
        int leftSubtreeSize = rootIndexInInorder - inStart;

        root->left = buildSubtree(inorder, inStart, rootIndexInInorder - 1, postorder, postStart, postStart + leftSubtreeSize -1, inorderMap);
        root->right= buildSubtree(inorder, rootIndexInInorder + 1, inEnd, postorder, postStart + leftSubtreeSize, postEnd-1, inorderMap);

        return root;
    }
};