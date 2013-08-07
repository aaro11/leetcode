/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result = INT_MIN;
        pathsum(root);
        return result;
    }
    
    int pathsum(TreeNode *root){
        if (!root)  return 0;
        int left = pathsum(root->left);
        int right = pathsum(root->right);
        
        if (left + root->val + right > result)
            result = left + root->val + right;
            
        int val = (left > right ? left : right) + root->val;
        return val > 0 ? val : 0;
    }
private:
    int result;
};