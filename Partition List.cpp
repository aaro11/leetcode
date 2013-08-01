class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *a = new ListNode(0), *b = new ListNode(0);
        ListNode *pSmall = a, *pLarge = b;
        
        while(head){
            if (head->val < x){
                pSmall->next = head;
                pSmall = head;
            } else {
                pLarge->next = head;
                pLarge = head;
            }
            head = head->next;
        }
        pSmall->next = b->next;
        pLarge->next = NULL;
        
        return a->next;
    }
};