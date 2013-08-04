class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int p0 = 0, p2 = n - 1, ind = 0;
        while(ind <= p2){
            if (A[ind] == 0){
                if (ind == p0){
                    ind++, p0++;
                    continue;
                }
                A[ind] = A[p0];
                A[p0] = 0;
                p0++;
            } else if (A[ind] == 2){
                A[ind] = A[p2];
                A[p2] = 2;
                p2--;
            } else if (A[ind] == 1) {
                ind++;
            }
        }
        return ;
    }
};