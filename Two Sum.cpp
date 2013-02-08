struct Node{
    int val;
    int ind;
};

bool myfunc(Node n1, Node n2){
    return n1.val < n2.val;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sind = 0, eind = numbers.size() - 1;
        vector<int> result;
        
        vector<Node> ns;
        Node node;
        for (int i = 0; i != eind+1; i++){
            node.val = numbers[i], node.ind = i;
    		ns.push_back(node);
        }
        sort(ns.begin(), ns.end(), myfunc);
        
        while(sind < eind){
            if (ns[sind].val + ns[eind].val > target)
                eind--;
            else if (ns[sind].val + ns[eind].val < target)
                sind++;
            else{
                result.push_back(ns[sind].ind+1);
                result.push_back(ns[eind].ind+1);
                sort(result.begin(), result.end());
                return result;
            }
        }
    }
};