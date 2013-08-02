int dp[1000];

int cnt(int n){
    if (dp[n])  return dp[n];
    if (n < 2)  return 1;
    for (int i = 0; i != n; i++){
        dp[n] += cnt(i) * cnt(n-i-1);
    }
    return dp[n];
}

class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        memset(dp, 0, sizeof(dp));
        return cnt(n);
    }
};