string arr[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        result.push_back("");
        
        for (int i = 0; i != digits.size(); i++){
            vector<string> tmp = result;
            result.clear();
            int ind = digits[i] - '1';
            for (int j = 0; j != arr[ind].size(); j++){
                for (int k = 0; k != tmp.size(); k++){
                    result.push_back(tmp[k] + arr[ind][j]);
                }
            }
        }
        return result;
    }
};