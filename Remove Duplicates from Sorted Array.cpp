class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!n)
            return 0;
        
        int ind = 0;
        for (int i = 1; i != n; i++){
            if (A[i] != A[ind])
                ind++;
            A[ind] = A[i];
        }
        return ind+1;
    }
};
