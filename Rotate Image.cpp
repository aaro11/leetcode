void swap(vector<vector<int> > &matrix, int x1, int y1, int x2, int y2){
    int tmp = matrix[x1][y1];
    matrix[x1][y1] = matrix[x2][y2];
    matrix[x2][y2] = tmp;
}

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = matrix.size();
        
        for (int i = 0; i != len; i++){
            for (int j = 0; j != i; j++){
                swap(matrix, i, j, j, i);
            }
        }
        
        for (int i = 0; i != len; i++){
            for (int j = 0; j != len/2; j++){
                swap(matrix, i, j, i, len - j - 1);
            }
        }
        return ;
    }
};