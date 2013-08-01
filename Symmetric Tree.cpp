/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool mirror(TreeNode *left, TreeNode *right){
    bool ret = true;
    if (!left && !right)            //two null
        return true;
    if (!left || !right)            //one null
        return false;   
    if (left->val != right->val)    //not equal value
        return false;

    ret &= mirror(left->left, right->right);
    ret &= mirror(left->right, right->left);
    
    return ret;
}
 
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)
            return true;
        return mirror(root->left, root->right);
    }
};