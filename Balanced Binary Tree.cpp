/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool flag = true;
int height(TreeNode *root){
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    if (abs(right-left) > 1)
        flag = false;
    return max(right, left) + 1;
}
 
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        flag = true;
        height(root);
        return flag;
    }
};
