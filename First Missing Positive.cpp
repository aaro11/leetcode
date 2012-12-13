class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int arr[10000];
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i != n; i++){
            if (A[i] > 0)
                arr[A[i]] = 1;
        }
        for (int i = 1; i != 10000; i++){
            if (!arr[i])
                return i;
        }
    }
};