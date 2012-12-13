TreeNode *build(vector<int> &inorder, vector<int> &preorder, int instart, int inend, int prestart, int preend){
    if (preend - prestart <1 || inend - instart < 1)
        return NULL;
    int val = preorder[prestart];
    int split = instart;
    
    for (int i = instart; i != inend; i++){
        if (inorder[i] == val){
            split = i;
        }
    }
    
    TreeNode *root = new TreeNode(val);
    root->left = build(inorder, preorder, instart, split, prestart+1, prestart + split - instart+1);
    root->right = build(inorder, preorder, split+1, inend, prestart+split-instart+1, preend);
    
    
    return root;
}
 
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = inorder.size();
        TreeNode *root = build(inorder, preorder, 0, len, 0, len);
        return root;
    }
};