class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = triangle.size();
        int *dp = new int[len];
        
        for (int i = len - 1; i != -1; i--){
            dp[i] = triangle[len-1][i];
        }
        for (int i = len - 2; i > -1; i--){
            for (int j = 0; j != i + 1; j++){
                dp[j] = triangle[i][j] + (dp[j] < dp[j+1] ? dp[j] : dp[j+1]);
            }
        }
        return dp[0];
    }
};