/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int result = 0;
int search(TreeNode *root){
    int value = 0;
    if (!root)
        return 0;
    
    int left = search(root->left);
    int right = search(root->right);
    
    if (left + right + root->val > result){
        result = left + right + root->val;
    }
    
    int val = (left > right ? left : right) + root->val;
    return val > 0 ? val : 0;
}
 
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result = -1000000;
        search(root);
        
        return result;
    }
};