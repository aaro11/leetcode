class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result(2);
        
        int l = 0, r = n - 1, m = 0;
        result[0] = result[1] = -1;
        //left side
        while(l <= r){
            m = (l + r) / 2;
            if (A[m] < target)  l = m + 1;
            else                r = m - 1;
        }
        result[0] = l;
        r = n - 1;
        while(l <= r){
            m = (l + r) / 2;
            if (A[m] > target)  r = m - 1;
            else                l = m + 1;
        }
        result[1] = r;
        if (A[result[0]] != target){
            result[0] = result[1] = -1;
        }
        return result;
    }
};