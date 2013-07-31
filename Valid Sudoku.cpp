class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int arr[10];
        //row
        for (int i = 0; i != 9; i++){
            memset(arr, 0, 10 * sizeof(int));
            for (int j = 0; j != 9; j++){
                if (board[i][j] != '.'){
                    arr[board[i][j] - '0']++;
                    if (arr[board[i][j] - '0'] > 1)
                        return false;
                }
            }
        }
        //column
        for (int i = 0; i != 9; i++){
            memset(arr, 0, 10 * sizeof(int));
            for (int j = 0; j != 9; j++){
                if (board[j][i] != '.'){
                    arr[board[j][i] - '0']++;
                    if (arr[board[j][i] - '0'] > 1)
                        return false;
                }
            }
        }
        //square
        for (int i = 0; i != 3; i++){
            for (int j = 0; j != 3; j++){
                memset(arr, 0, 10 * sizeof(int));
                int startx = i * 3;
                int starty = j * 3;
                for (int p = 0; p != 3; p++){
                    for (int q = 0; q != 3; q++){
                        char c = board[startx+p][starty+q];
                        if (c != '.'){
                            arr[c - '0']++;
                            if (arr[c - '0'] > 1)
                                return false;
                        }
                    }
                }
            }
        }
        return true;
        
    }
};