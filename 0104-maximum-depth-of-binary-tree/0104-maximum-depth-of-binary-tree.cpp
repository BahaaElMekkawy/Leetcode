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
    int maxDepth(TreeNode* root) {
        int res = 0 ; 
        if (root) {
        res = 1;
            if (root->left)
                res = max(res, 1 + maxDepth(root->left));
            if (root->right)
                res = max(res, 1 + maxDepth(root->right));
        }
        return res;
    }
};