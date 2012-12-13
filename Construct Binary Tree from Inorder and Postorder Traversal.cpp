TreeNode *build(vector<int> &inorder, vector<int> &postorder, int instart, int inend, int poststart, int postend){
    if (postend - poststart <1 || inend - instart < 1)
        return NULL;
    int val = postorder[postend-1];
    int split = instart;
    
    for (int i = instart; i != inend; i++){
        if (inorder[i] == val){
            split = i;
        }
    }
    
    TreeNode *root = new TreeNode(val);
    root->left = build(inorder, postorder, instart, split, poststart, poststart + split - instart);
    root->right = build(inorder, postorder, split+1, inend, poststart+split-instart, postend-1);
    
    
    return root;
}
 
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = inorder.size();
        TreeNode *root = build(inorder, postorder, 0, len, 0, len);
        return root;
    }
};