/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int res;
void sum(TreeNode *root, int cur){
    if (!root->left && !root->right){
        res += cur*10 + root->val;
    }
    cur = cur*10 + root->val;
    if (root->left) sum(root->left, cur);
    if (root->right) sum(root->right, cur);
} 
 
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res = 0;
        if (!root)  return 0;
        sum(root, 0);
        
        return res;
    }
};