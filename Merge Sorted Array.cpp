class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *arr = new int[m+n];
        memset(arr, 0, (m+n)*sizeof(int));
        int ind = 0, ind1 = 0, ind2 = 0;
        
        while(true){
            if (ind1 == m && ind2 == n)
                break;
                
            if (ind2==n || (ind1 < m && A[ind1] < B[ind2]))
                arr[ind++] = A[ind1++];
            else
                arr[ind++] = B[ind2++];
        }
        
        memcpy(A, arr, (m+n)*sizeof(int));
        
        return ;
    }
};
