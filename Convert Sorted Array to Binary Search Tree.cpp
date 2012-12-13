TreeNode *build(vector<int>& num, int start, int end){
    if (end == start)
        return NULL;
    int mid = (end+start)/2;
    TreeNode *root = new TreeNode(num[mid]);
    root->left = build(num, start, mid);
    root->right = build(num, mid+1, end);
    
    return root;
}

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below 
        // DO NOT write int main() function
        TreeNode *root = build(num, 0, num.size());
        return root;
    }
};