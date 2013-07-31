/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<vector<int> > result;
 
void dfs(TreeNode *root, int sum, int cur, vector<int> path){
    cur += root->val;
    path.push_back(root->val);
    if (!root->left && !root->right && cur == sum)
        result.push_back(path);
        
    if (root->left) dfs(root->left, sum, cur, path);
    if (root->right) dfs(root->right, sum, cur, path);
}
 
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        if (!root)
            return result;
        vector<int> path;
        dfs(root, sum, 0, path);
        return result;
    }
};
