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
 
void search(TreeNode* root, int height){
    if (!root)
        return ;
    if (result.size() < height+1){
        vector<int> tmp;
        result.push_back(tmp);
    }
    
    search(root->left, height+1);
    result[height].push_back(root->val);
    search(root->right, height+1);
}
 
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        search(root, 0);
        return result;
    }
};
