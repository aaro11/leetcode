class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *left = new int[n];
        memset(left, 0, n * sizeof(int));
        if (n < 3)  return 0;
        left[0] = A[0];
        for (int i = 1; i != n; i++)
            left[i] = max(A[i], left[i-1]);
            
        int result = 0, right = A[n-1], tmp;
        for (int i = n - 2; i > 0; i--){
            right = max(right, A[i]);
            tmp = min(left[i-1], right) - A[i];
            result = tmp > 0 ? result + tmp : result;
        }
        
        return result;
    }
};