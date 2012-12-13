/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<int> result;

void search(TreeNode *root){
    if (!root)
        return ;
    search(root->left);
    result.push_back(root->val);
    search(root->right);
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        search(root);
        return result;
    }
};