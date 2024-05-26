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
    vector<vector<int>> result;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        if(!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int levelSize = q.size();
            vector<int> subResult;
            for(int i=0; i< levelSize; i++) {
                TreeNode* frontNode = q.front();
                q.pop();
                subResult.push_back(frontNode->val);
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            result.push_back(subResult);   
        }
        reverse(result.begin(), result.end());
        return result;
        
    }
};