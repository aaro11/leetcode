/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *f1= NULL, *f2 = NULL;
        TreeNode *current, *pre, *parent = NULL;
        if (!root)  return ;
        bool found = false;
        current= root;
        
        while(current){
            if (!current->left){
                if (parent && parent->val > current->val){
                    if (!found){
                        f1 = parent;
                        found = true;
                    }
                    f2 =current;
                }
                parent = current;
                current = current->right;
            } else {
                pre = current->left;
                while(pre->right != NULL && pre->right != current)
                    pre = pre->right;
                    
                if (!pre->right){
                    pre->right = current;
                    current = current->left;
                } else {
                    pre->right = NULL;
                    if(parent->val > current->val)
                    {
                        if(!found)
                        {
                            f1 = parent;       
                            found = true;
                        }
                        f2 = current;
                    }
                    parent = current;
                    current = current->right;     

                }
            }
        }
        if (f1 && f2){
            swap(f1->val, f2->val);
        }
    }
};