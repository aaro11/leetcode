/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int result = 100000;

void dfs(TreeNode *root, int depth){
    if (!root->left && !root->right){
        if (depth < result)
            result = depth;
    }
    if (root->left) dfs(root->left, depth+1);
    if (root->right) dfs(root->right, depth + 1);
}

class Solution {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result = 10000000;
        if (!root)
            return 0;
        dfs(root, 1);
        return result;
    }
};
