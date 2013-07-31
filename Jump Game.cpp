class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int* reach = new int[n+100];
        memset(reach, 0, n * sizeof(int));
        reach[0] = 1;
        
        for (int i = 0; i != n; i++){
            if (!reach[i] || reach[i + A[i]])
                continue;
            for (int j = 1; j <= A[i]; j++){
                reach[i+j] = 1;
            }
        }
        
        return reach[n-1];
    }
};