class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        if (!numRows)
            return result;
        vector<int> tmp;
        tmp.push_back(1);
        result.push_back(tmp);
        
        for (int i = 2; i <= numRows; i++){
            tmp.clear();
            
            tmp.push_back(1);
            for (int j = 1; j < i - 1; j++){
                tmp.push_back(result[i-2][j-1]+result[i-2][j]);
            }
            tmp.push_back(1);
            result.push_back(tmp);
        }
        
        return result;
    }
};
