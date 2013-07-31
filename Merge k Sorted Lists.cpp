
int inline left(int x){
    return x*2 + 1;
}
int inline right(int x){
    return (x+1)*2;
}
bool comp(ListNode* l1, ListNode* l2){
    return l1->val > l2->val;
}

void swap(vector<ListNode *> &lists, int x1, int x2){
    ListNode *tmp = lists[x1];
    lists[x1] = lists[x2];
    lists[x2] = tmp;
    
    return ;
}

void adjustHeap(vector<ListNode *> &lists, int start){
    if (left(start) >= lists.size())
        return ;
        
    int l = left(start), r = right(start);
    int ind = l;
    if (r < lists.size() && lists[r]->val < lists[l]->val)
        ind = r;
  if (lists[ind]->val < lists[start]->val){
		swap(lists, start, ind);
		adjustHeap(lists, ind);
	}
    
    return ;
}

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<ListNode *>::iterator ite;
		while((ite = find(lists.begin(), lists.end(), (ListNode *)NULL)) != lists.end())
			lists.erase(ite);
		
        if (!lists.size())
            return NULL;
        ListNode *ret = NULL, *root = NULL, *tmp;

        make_heap(lists.begin(), lists.end(), comp);

        if (lists[lists.size() - 1]){
            ret = root = lists[0];
            if (lists[0]->next){
				lists[0] = lists[0]->next;
				adjustHeap(lists, 0);
			}
            else{
                lists.erase(lists.begin(), lists.begin() + 1);
				make_heap(lists.begin(), lists.end(), comp);
			}
                
            while(lists.size()){
                root->next = lists[0];
                root = root->next;
                if (lists[0]->next){
					lists[0] = lists[0]->next;
					adjustHeap(lists, 0);
				}
                else{
					lists.erase(lists.begin(), lists.begin() + 1);
					make_heap(lists.begin(), lists.end(), comp);
				}
            }
        }
        if(root){
			root->next = NULL;
		}
        return ret;
    }
};
