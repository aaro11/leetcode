
int arr[600][600], len1, len2;
bool visit[600][600];

int cnt(string& word1, string &word2, int ind1, int ind2){
    if (visit[ind1][ind2])
        return arr[ind1][ind2];
    visit[ind1][ind2] = true;
    
    //delete
    if (ind2 == len2){
        return arr[ind1][ind2] = len1 - ind1;
    }
    //insert
    if (ind1 == len1){
        return arr[ind1][ind2] = len2 - ind2;
    }
    if (word1[ind1] == word2[ind2])
        return arr[ind1][ind2] = cnt(word1, word2, ind1+1, ind2+1);

    int res1 = cnt(word1, word2, ind1, ind2+1) + 1;     //insert
    int res2 = cnt(word1, word2, ind1+1, ind2) + 1;     //delete
    int res3 = cnt(word1, word2, ind1+1, ind2+1) + 1;   //modify
    
    return arr[ind1][ind2] = min(min(res1, res2), res3);
    
}

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //memset(arr, 0, 600*600*sizeof(int));
        memset(visit, 0, 600*600*sizeof(bool));
        len1 = word1.size(), len2 = word2.size();
        
        return cnt(word1, word2, 0, 0);
    }
};