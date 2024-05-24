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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return result;
        queue<TreeNode*> list;
        list.push(root);
    
        bool leftToRight = true;

        while (!list.empty()) {
        
            int size = list.size();
            vector<int> subResult(size);
            

            for (int i = 0; i < size; i++) {
                TreeNode* currentNode = list.front();
                list.pop();

                int index = leftToRight ? i : size - i -1;
                subResult[index] = currentNode->val;

                if(currentNode->left) list.push(currentNode->left);
                if(currentNode->right) list.push(currentNode->right);

            }

            result.push_back(subResult);
            leftToRight = !leftToRight;
        }

        return result;
    }
};