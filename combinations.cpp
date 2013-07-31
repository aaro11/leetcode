void search(int n, int k, int start, vector<vector<int> > &result, vector<int> &cur){
    if (k == 0){
        result.push_back(cur);
        return ;
    }
    if (start > n){
        return ;
    }
        
    cur.push_back(start);
    search(n, k - 1, start+1, result, cur);
    cur.pop_back();
    search(n, k, start + 1, result, cur);
    
    return ;
}

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        vector<int> cur;
        search(n, k, 1, result, cur);
        
        return result;
    }
};