class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        int len1 = matrix.size();
        if (!len1)   return result;
        int len2 = matrix[0].size();
        if (!len2)  return result;
        
        int start1 = 0, end1 = len1 - 1, start2 = 0, end2 = len2 - 1;
        while(true){
            //right
            for (int i = start2; i <= end2; i++){
                result.push_back(matrix[start1][i]);
            }
            if (++start1 > end1)    break;
            //bottom
            for (int i = start1; i <= end1; i++){
                result.push_back(matrix[i][end2]);
            }
            if (--end2 < start2)    break;
            //left
            for (int i = end2; i >= start2; i--){
                result.push_back(matrix[end1][i]);
            }
            if (--end1 < start1)    break;
            for (int i = end1; i >= start1; i--){
                result.push_back(matrix[i][start2]);
            }
            if (++start2 > end2)    break;
        }
        return result;
    }
};