class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = matrix.size();
        if (!len1)  return ;
        int len2 = matrix[0].size();
        if (!len2) return ;
        vector<int> row, column;
        for (int i = 0; i != len1; i++){
            for (int j = 0; j != len2; j++){
                if (!matrix[i][j]){
                    row.push_back(i);
                    column.push_back(j);
                }
            }
        }
        sort(row.begin(), row.end());
        sort(column.begin(), column.end());
        unique(row.begin(), row.end());
        unique(column.begin(), column.end());
        
        for (vector<int>::iterator ite = row.begin(); ite != row.end(); ite++)
            for (int j = 0; j != len2; j++)
                matrix[*ite][j] = 0;
        for (vector<int>::iterator ite = column.begin(); ite != column.end(); ite++)
            for (int i = 0; i != len1; i++)
                matrix[i][*ite] = 0;
                
        return ;
    }
};