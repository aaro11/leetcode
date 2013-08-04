int dp[100][100];
bool visit[100][100];
int paths(vector<vector<int> > &grid, int x, int y){
    if (grid[x][y] == 1)    return 0;
    if (x == grid.size() - 1 && y == grid[0].size() - 1){
        return 1;
    }
    if (visit[x][y])   return dp[x][y];
    int ret = 0;
    if (x < grid.size() - 1)    ret += paths(grid, x+1, y);
    if (y < grid[0].size() - 1) ret += paths(grid, x, y+1);
    visit[x][y] = true;
    return dp[x][y] = ret;
    
}
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        memset(dp, 0, sizeof(dp));
        memset(visit, 0, sizeof(visit));
        return paths(obstacleGrid, 0, 0);
    }
};
