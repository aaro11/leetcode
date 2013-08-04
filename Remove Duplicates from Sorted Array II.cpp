class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 3)  return n;
        
        int slow = 1, fast = 2;
        
        while(fast < n){
            if (A[fast] != A[slow] || A[fast] != A[slow-1]){
                A[++slow] = A[fast];
            }
            fast++;
        }
        return slow+1;
    }
};