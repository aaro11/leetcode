class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!n) return 0;
        if (target <= A[0]) return 0;
        if (target > A[n-1])    return n;
        int start = 0, end = n - 1;
        
        while(start <= end){
            int m = (start + end) / 2;
            if (A[m] >= target && A[m-1] < target)  return m;
            if (A[m] < target){
                start = m + 1;
            }else{
                end = m - 1;
            }
        }
        return -1;
    }
};