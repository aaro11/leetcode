void expand(vector<vector<char> >& board, vector<vector<char> > &orig, int x, int y){
    if (orig[x][y] != 'O' || board[x][y] == 'O')
        return ;
    
    board[x][y] = 'O';
    if (x > 0)                      expand(board, orig, x-1, y);
    if (x < board.size() - 1)       expand(board, orig, x+1, y);
    if (y > 0)                      expand(board, orig, x, y-1);
    if (y < board[0].size() - 1)    expand(board, orig, x, y+1);
    
    return ;
}

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = board.size();
        if (len1 < 3)   return ;
        int len2 = board[0].size();
        if (len2 < 3)  return ;
        vector<vector<char> > orig = board;
        
        for (int i = 0; i != len1; i++){
            for (int j = 0; j != len2; j++){
                board[i][j] = 'X';
            }
        }
        
        for (int i = 0; i != len1; i++){
            expand(board, orig, i, 0);
            expand(board, orig, i, len2 - 1);
        }
        for (int j = 0; j != len2; j++){
            expand(board, orig, 0, j);
            expand(board, orig, len1-1, j);
        }
        
        return ;
    }
};