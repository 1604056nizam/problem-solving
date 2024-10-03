class Solution {
public:
    vector<string> result;

    void helper(TreeNode* root, string s) {
        if (!root) return;

        // Append current node value to the path
        if (!s.empty()) {
            s += "->";
        }
        s += to_string(root->val);

        // If it's a leaf node, push the current path to the result
        if (!root->left && !root->right) {
            result.push_back(s);
            return;
        }

        // Recurse on left and right subtrees
        helper(root->left, s);
        helper(root->right, s);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return result;  // Handle edge case if root is null
        helper(root, "");
        return result;
    }
};
