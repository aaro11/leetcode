int result;

void search(TreeNode *root, int height){
    if (height > result)
        result = height;
    if (!root)
        return ;
    search(root->left, height+1);
    search(root->right, height+1);
}

class Solution {
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result = 0;
        search(root, 0);
        return result;
    }
};