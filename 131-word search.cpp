
int len1, len2;

bool mysearch(vector<vector<char> > &board, vector<vector<bool> > &visit, string word, int x, int y){
    bool result = false;
  if (!word.size())
		return true;
	if (x < 0 || x >= len1 || y < 0 || y >= len2 || word[0] != board[x][y] || visit[x][y] )
		return false;
	string subword = word.substr(1, word.size() - 1);

	visit[x][y] = true;
	result |= mysearch(board, visit, subword, x-1, y);
	if (!result) result |= mysearch(board, visit, subword, x+1, y);
	if (!result) result |= mysearch(board, visit, subword, x, y-1);
	if (!result) result |= mysearch(board, visit, subword, x, y+1);
	visit[x][y] = false;
	return result;
}

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        len1 = board.size(), len2 = board[0].size();
        vector<vector<bool> > visit(len1);
        for (int i = 0; i != len1; i++)
            visit[i].resize(len2);
        
        for (int i = 0; i != len1; i++){
            for (int j = 0; j != len2; j++){
				if (mysearch(board, visit, word, i, j))
					return true;
            }
        }
        return false;
    }
};
