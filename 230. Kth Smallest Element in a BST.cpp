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
    
    void inOrderTraversal(TreeNode* root, vector<int>& sortedArray) {
        if(!root) return;
        
        inOrderTraversal(root->left, sortedArray);
        sortedArray.push_back(root->val);
        inOrderTraversal(root->right, sortedArray);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> sortedArray;
        inOrderTraversal(root, sortedArray);
        return sortedArray[k-1];
    }
};