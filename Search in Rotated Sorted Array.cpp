class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = n - 1;
        
        while(l <= r){
            int m = (l + r) / 2;
            if (A[m] == target) return m;
            //left array is sorted
            if (A[m] >= A[l]){
                if (target >= A[l] && target <= A[m])   r = m - 1;
                else    l = m + 1;
            }else{
                //right array is sorted
                if (target >= A[m] && target <= A[r])   l = m + 1;
                else    r = m - 1;
            }
        }
        return -1;
    }
};