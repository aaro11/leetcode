class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *arr = new int[n];
        arr[0] = 1;
        arr[1] = 2;
        for (int i = 2; i < n; i++){
            arr[i] = arr[i-1]+arr[i-2];
        }
        
        return arr[n-1];
    }
};