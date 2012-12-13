class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = -1000000;
        int tmp = 0;
        for (int i = 0; i != n; i++){
            tmp += A[i];
            if (tmp > result){
                result = tmp;
            }
            if (tmp < 0)
                tmp = 0;
        }
        return result;
    }
};