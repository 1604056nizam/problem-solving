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
/*
    1. We have "compareRootHeightsAndDecide" that decides wheter left height or rightHeight be same.
    2. If same then it is a perfect binary tree. So we calculate the nodes of a perfect binary tree by 2^h -1.
    3. If not same, we go down with leftSubTree and rightSubTree And try to find where it is same.
*/


    int leftTreeHeight(TreeNode* root, int height) {
        if (root == nullptr)
            return 0;

        return 1 + leftTreeHeight(root->left, height);
    }

    int rightTreeHeight(TreeNode* root, int height) {
        if (root == nullptr)
            return 0;

        return 1 + rightTreeHeight(root->right, height);
    }

    int compareRootHeightsAndDecide(TreeNode* root) {

        int leftHeight = leftTreeHeight(root, 0);
        int rightHeight = rightTreeHeight(root, 0);

        cout <<"leftHeight "<< leftHeight <<" rightHeight "<< rightHeight<<endl;

        if (leftHeight == rightHeight) {
            return pow(2, rightHeight) - 1;
        }

        return 1 + compareRootHeightsAndDecide(root->left)  + compareRootHeightsAndDecide(root->right);
    }

    int countNodes(TreeNode* root) { 
        if(!root) return 0;
        return compareRootHeightsAndDecide(root); 
    }
};