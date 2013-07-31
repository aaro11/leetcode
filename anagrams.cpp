class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> tmp = strs, result;
        int len = tmp.size();
        string str;
        map<string, int> counter;
        for (int i = 0; i != len; i++){
            sort(tmp[i].begin(), tmp[i].end());
            counter[tmp[i]]++;
            
        }
        for (int i = 0; i != len; i++){
            if (counter[tmp[i]] > 1){
                result.push_back(strs[i]);
            }
        }
        
        return result;
    }
};