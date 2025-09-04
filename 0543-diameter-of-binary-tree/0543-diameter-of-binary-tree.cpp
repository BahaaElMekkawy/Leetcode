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
private:
    int maxDiameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        GetNodeHieght(root);
        return maxDiameter;
    }
    //this is a normal getHight function but inside it i compute the maxDiameter inside it 
    int GetNodeHieght(TreeNode* node) {
        if (!node)
            return 0;
        int curLeftHieght = GetNodeHieght(node->left);
        int curRightHieght = GetNodeHieght(node->right);
        maxDiameter = max(maxDiameter, (curLeftHieght+ curRightHieght));
        return max(curLeftHieght, curRightHieght) + 1 ;
    }
};