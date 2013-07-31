<<<<<<< HEAD
struct number{
    int value;
    int ind;
};

int comp(const number &n1, const number &n2){
    return n1.value < n2.value;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<number> arr;
        vector<int> result;
        int len = numbers.size();
        
        for (int i = 0; i != len; i++){
            number n = number();
            n.value = numbers[i];
            n.ind = i;
            arr.push_back(n);
        }
        sort(arr.begin(), arr.end(), comp);
        
        int startind = 0, endind = len - 1;
        while(endind > startind){
            int sum = arr[startind].value + arr[endind].value;
            if (sum == target){
                result.push_back(arr[startind].ind + 1);
                result.push_back(arr[endind].ind + 1);
                break;
            }
            if (sum < target){
                startind++;
                continue;
            }
            if (sum > target){
                endind--;
                continue;
            }
            
        }
        sort(result.begin(), result.end());
        return result;
    }
=======
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
>>>>>>> dc848690c9b2b27cf97555b489b09b3dea1dd372
};