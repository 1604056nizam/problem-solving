/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> getArrayFromList(ListNode* head) {
        vector<int> list;

        if (!head) return list;

        while (head) {
            list.push_back(head->val);
            head = head->next;
        }

        return list;
    }

    TreeNode* getBinaryTreeFromList(vector<int>& array, int left, int right) {

        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(array[mid]);
        root->left = getBinaryTreeFromList(array, left, mid - 1);
        root->right = getBinaryTreeFromList(array, mid + 1, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> array = getArrayFromList(head);
        if (array.size() < 1) return nullptr;

        return getBinaryTreeFromList(array, 0, array.size() - 1);
    }
};