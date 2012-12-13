bool visit[1000][1000], flag[1000][1000];
int len1, len2, len3;

bool cnt(string s1, string s2, string s3,int ind1, int ind2){
    if (visit[ind1][ind2])
        return flag[ind1][ind2];
    visit[ind1][ind2] = true;
    if (ind1==len1 && ind2 == len2)
        return flag[ind1][ind2] = true;
        
    if (ind1 < len1 && s1[ind1] == s3[ind1+ind2])
        flag[ind1][ind2] |= cnt(s1, s2, s3, ind1+1, ind2);
    if (ind2 < len2 && s2[ind2] == s3[ind1+ind2])
        flag[ind1][ind2] |= cnt(s1, s2, s3, ind1, ind2+1);
    return flag[ind1][ind2];
}

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        
        if (!(len1||len2||len3))
            return true;
        if (len1 + len2 != len3)
            return false;
        memset(visit, 0, 1000*1000*sizeof(bool));
        memset(flag, 0, 1000*1000*sizeof(bool));
            
        return cnt(s1, s2, s3, 0, 0);
    }
};