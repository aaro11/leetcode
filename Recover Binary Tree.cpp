/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode *first, *second;
 
void search(TreeNode *root, int minval, int maxval){
    if (root->val <= minval || root->val >= maxval){
        if (!first) first = root;
        else    second = root;
    }
    search(root->left, minval, root->val);
    search(root->right, root->val, maxval);
}
 
class Solution {
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        first = second = NULL;
        search(root, INT_MIN, INT_MAX);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
        
        return ;
    }
};