class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = matrix.size();
        if (!len1)   return false;
        int len2 = matrix[0].size();
        if (!len2)  return false;
        
        int l = 0, r = len1 * len2 - 1;
        
        while( l <= r ){
            int m = (l + r) / 2;
            int ind1 = m / len2, ind2 = m % len2;
            
            if (matrix[ind1][ind2] == target)   return true;
            
            if (matrix[ind1][ind2] < target){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return false;
    }
};