class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sz = strs.size();
        if (sz == 0)
            return "";
        if (sz == 1)
            return strs[0];
        int *len = new int[sz];
        for (int i = 0; i != sz; i++){
            len[i] = strs[i].size();
        }
        
        string result = "";
        int ind = 0;
        
        while(true){
            char c = strs[0][ind];
            
            for (int i = 1; i < sz; i++){
                if (ind >= len[i] || strs[i][ind] != c)
                    return result;
            }
            ind++;
            result += c;
        }
        
        return result;
    }
};