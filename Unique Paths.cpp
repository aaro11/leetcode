int arr[100][100];

int search(int m, int n){
    if (arr[m][n])
        return arr[m][n];
        
    if (m == 0 || n == 0){
        return 1;
    }
    
    return arr[m][n] = search(m-1, n) + search(m, n-1);
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        memset(arr, 0, sizeof(arr));
        return search(m - 1, n - 1);
    }
};