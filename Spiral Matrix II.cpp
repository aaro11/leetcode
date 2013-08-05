class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result(n);
        if (!n) return result;
        for (int i = 0; i != n; i++)    result[i].resize(n);
        int ind = 1;
        int start1 = 0, end1 = n - 1, start2 = 0, end2 = n - 1;
            while(true){
            //right
            for (int i = start2; i <= end2; i++){
                result[start1][i] = ind++;
            }
            if (++start1 > end1)    break;
            //bottom
            for (int i = start1; i <= end1; i++){
                result[i][end2] = ind++;
            }
            if (--end2 < start2)    break;
            //left
            for (int i = end2; i >= start2; i--){
                result[end1][i] = ind++;
            }
            if (--end1 < start1)    break;
            for (int i = end1; i >= start1; i--){
                result[i][start2] = ind++;
            }
            if (++start2 > end2)    break;
        }
        return result;
    }
};