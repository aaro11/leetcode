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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int len = 0;
        ListNode *dummy = new ListNode(0), *phead = head;
        dummy->next = head;
        
        while(head){
            len++;
            head = head->next;
        }
        if (!len || !(k%len) || !dummy->next)    
            return dummy->next;
            
        head = dummy->next;
        k %= len;
        k++;
        
        ListNode *fast, *slow;
        fast = slow = head;
        while(k--){
            fast = fast->next;
        }
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        
        dummy->next = slow->next;
        head = dummy->next;
        while(head->next){
            head = head->next;
        }
        head->next = phead;
        
        slow->next = NULL;
        
        return dummy->next;
    }
};