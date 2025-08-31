// * Approach:
//  * - A tree is symmetric if its left subtree is a mirror of its right subtree.
//  * - To check mirrors:
//  *    1. If both nodes are null → symmetric at this level.
//  *    2. If one is null and the other isn’t → not symmetric.
//  *    3. If values differ → not symmetric.
//  *    4. Otherwise, check:
//  *        - left->left  vs right->right
//  *        - left->right vs right->left
//  * - We apply this recursively until we either find a mismatch or finish.
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isMirror(root->right, root->left);
    }
    bool isMirror(TreeNode* right, TreeNode* left) {
        bool res = true;
        if (!left && !right)
            return true; //both null 
        if (!left || !right)
            return false; //one is null the other not 
        if (right->val != left->val)
            return false;
        res = isMirror(right->right, left->left) &&
              isMirror(right->left, left->right);
        return res;
    }
};