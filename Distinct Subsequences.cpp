int len1, len2;
unsigned int arr[11000][100];
bool visit[11000][100];
unsigned int cnt(string &s, string &t, int ind1, int ind2){
    if (arr[ind1][ind2] || visit[ind1][ind2])
        return arr[ind1][ind2];
	visit[ind1][ind2] = true;
    if (ind2 == len2)
        return arr[ind1][ind2] = 1;
    if (ind1 == len1){
        return arr[ind1][ind2] = 0;
	}
        
    if (s[ind1] == t[ind2]){
        arr[ind1+1][ind2+1] = cnt(s,t,ind1+1,ind2+1);
        arr[ind1+1][ind2] = cnt(s,t,ind1+1, ind2);
        return arr[ind1][ind2] = arr[ind1+1][ind2+1] + arr[ind1+1][ind2];
    }
    else{
        arr[ind1+1][ind2] = cnt(s,t,ind1+1, ind2);
        return arr[ind1][ind2] = arr[ind1+1][ind2];
    }
    
}

class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		memset(arr, 0, 11000*100*sizeof(int));
        memset(visit, 0, 11000*100*sizeof(bool));
        len1 = S.size(), len2 = T.size();
        return cnt(S, T, 0, 0);
    }
};