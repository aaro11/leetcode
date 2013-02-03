class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *arr = new int[m+n];
        
        int l1 = 0, l2 = 0, ind = 0;
        while(true){
            if (l1 == m && l2 == n)
                break;
            if (l2 >= n || (l1 < m && A[l1] < B[l2])){
                arr[ind++] = A[l1++];
            }else{
                arr[ind++] = B[l2++];
            }
        }
        memcpy(A, arr, (m+n)*sizeof(int));
    }
};
