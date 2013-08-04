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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *preM, *prev = dummy;
        for (int i = 1; i <= n; i++){
            if (i == m) preM = prev;
            if (i > m){
                prev->next = head->next;
                head->next = preM->next;
                preM->next = head;
                head = prev;
            }
            prev =  head;
            head = head->next;
        }
        return dummy->next;
    }
};