/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool valid(TreeNode *root, int minval, int maxval){
    if (!root)  return true;
    
    return root->val > minval && root->val < maxval &&
            valid(root->left, minval, root->val) &&
            valid(root->right, root->val, maxval);
    
}
 
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return valid(root, INT_MIN, INT_MAX);
    }
};