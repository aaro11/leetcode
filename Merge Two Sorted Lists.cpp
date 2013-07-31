/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!l1 && !l2)
            return NULL;
        ListNode *res, *ret;
        if (!l2 || (l1 && l1->val < l2->val)){
            res = ret = l1;
            l1=l1->next;
        }else{
            res = ret = l2;
            l2 = l2->next;
        }
        
        while(l1 || l2){
            if (!l2 || (l1 && l1->val < l2->val)){
                res->next = l1;
                res = res->next, l1=l1->next;
            }else{
                res->next = l2;
                res = res->next, l2 = l2->next;
            }
        }
        return ret;
    }
};
