bool dp[100][100][100];
bool visited[100][100][100];

bool check(string s1, string s2, int start1, int start2, int len){
    if (visited[start1][start2][len])   return dp[start1][start2][len];
    
    visited[start1][start2][len] = true;

    if ( len == 1){
        return dp[start1][start2][len] = (s1[start1] == s2[start2]);
    }
        
    bool flag = false;
    for (int i = 1; i != len; i++){
        flag |= check(s1, s2, start1, start2, i) 
                && check(s1, s2, start1+i, start2+i, len - i);
                
        flag |= check(s1, s2, start1, start2+len-i, i) 
                && check(s1, s2, start1+i, start2, len - i);
    }
    return dp[start1][start2][len] = flag;
}

class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        memset(dp, 0, sizeof(dp));
        memset(visited, 0, sizeof(visited));
        return check(s1, s2, 0, 0, s1.size());
    }
};