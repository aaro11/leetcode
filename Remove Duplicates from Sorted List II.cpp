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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head || !head->next)   return head;
        ListNode *dummy = new ListNode(0);
        ListNode *pdummy = dummy;
        int dupval;
        
        while(head && head->next){
            while (head->val == head->next->val){
                dupval = head->val;
                while(head){
                    if (head->val != dupval)    break;
                    head = head->next;
                }
    			if (!head || !head->next)	break;
            }
            
            dummy->next = head;
            dummy = head;

            if (!head)  break;
            
            head = head->next;
        }
        
        return pdummy->next;
    }
};