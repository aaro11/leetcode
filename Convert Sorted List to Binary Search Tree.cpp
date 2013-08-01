/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> num;
        while(head){
            num.push_back(head->val);
            head = head->next;
        }
        return build(num, 0, num.size());
    }
};