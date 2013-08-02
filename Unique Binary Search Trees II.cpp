/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<TreeNode *> trees(int start, int end){
    vector<TreeNode *> ret;
    if (end < start) {
        ret.push_back(NULL);
        return ret;
    }
    for (int i = start; i <= end; i++){
        vector<TreeNode *> left = trees(start, i-1);
        vector<TreeNode *> right = trees(i+1, end);
        
        for (int p = 0; p != left.size(); p++){
            for (int q = 0; q != right.size(); q++){
                TreeNode *root = new TreeNode(i);
                root->left = left[p];
                root->right = right[q];
                ret.push_back(root);
            }
        }
    }
    
    return ret;
}
 
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return trees(1, n);
    }
};