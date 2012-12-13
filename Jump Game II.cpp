class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *result = new int[n];
        if (n == 1)
            return 0;
        memset(result, 0, sizeof(int) * n);
        result[0] = 1;
        for (int i = 0; i != n; i++){
            if (!result[i])
                continue;
            
            int e = A[i] + i;
            if (e >= n-1)
                return result[i];
            for (int j = e; j != i; j--){
                if (result[j])
                    break;
                result[j] = result[i]+1;
            }
        }
        
        return result[n-1] - 1;
    }
};