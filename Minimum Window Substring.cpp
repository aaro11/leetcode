class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char, int> cnt, cur;
        int len1 = S.size(), len2 = T.size(), num = 0, sum = 0;
        int start = 0, end = len1;
        string result = "";
        for (int i = 0; i != len2; i++){
            cnt[T[i]]++;
        }
        for (map<char, int>::iterator ite = cnt.begin(); ite != cnt.end(); ite++){
            if (ite->second)
                sum++;
        }
        int find = 0;
        
        for (int j = 0; j != len1; j++){
            cur[S[j]]++;
            if (cur[S[j]] == cnt[S[j]]){
                num++;
                
                if (num == sum){
                    while(true){
                        find++;
                        cur[S[find-1]]--;
                        if (cur[S[find-1]] < cnt[S[find-1]]){
                            num--;
                            if (j - find + 1< end - start){
                                start = find - 1, end = j;
                                result = S.substr(start, end - start + 1);
                            }
                            break;
                        }
                        
                    }
                }
            }
        }
        return result;
    }
};