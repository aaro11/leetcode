class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *reach = new int[n];
        memset(reach, 0, n * sizeof(int));
        
        reach[0] = 1;
        for (int i = 0; i != n; i++){
            if (reach[i]){
                for (int j = i+1; j != n && j != i + A[i]; j++){
                    reach[j] = 1;
                }
            }
        }
        
        if (reach[n-1])
            return true;
        else
            return false;
    }
};
