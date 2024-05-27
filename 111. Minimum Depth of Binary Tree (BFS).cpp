
  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode()  val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x)  val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode left, TreeNode right)  val(x), left(left),
  right(right) {}
  };
 
class Solution {
public
    int minDepth(TreeNode root) {
        if (!root)
            return 0;
        queueTreeNode q;
        q.push(root);
        int minDepth = 1;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i  levelSize; i++) {
                TreeNode curr = q.front();
                q.pop();
                if (!curr-left && !curr-right)
                    return minDepth;

                if(curr-left) q.push(curr-left);
                if(curr-right) q.push(curr-right);
            }
            minDepth+=1;
        }

        return minDepth;
    }
};