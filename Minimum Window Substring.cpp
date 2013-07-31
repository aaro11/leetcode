bool flag;
bool inline satis(map<char, int>& cnt, map<char, int> imap){
    for(map<char, int>::iterator ite = cnt.begin(); ite != cnt.end(); ite++){
        if (cnt[ite->first] > imap[ite->first])
            return false;
    }
    flag = true;
    return true;
}

class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
  	flag = false;
        map<char, int> cnt;
        for (int i = 0; i != T.size(); i++)
            cnt[T[i]]++;
        map<char, int> imap;
        int ind1=-1, ind2=-1, len = S.size();
        
        int curmin = 10000;
        string result = "";
        char c;

        while(ind2 < len){
            ind2++;
            if (cnt[S[ind2]])
                imap[S[ind2]]++;
            else
                continue;
                
            if ((flag && S[ind2] == c) || (!flag && satis(cnt, imap))){
                while(ind1 < ind2){
                    ind1++;
                    if (!cnt[S[ind1]])
                        continue;
                        
                    if (imap[S[ind1]] > cnt[S[ind1]]){
                        imap[S[ind1]]--;
                    }else{
                        if (curmin > ind2-ind1){
                            curmin = ind2-ind1;
                            result = S.substr(ind1, ind2-ind1+1);
                        }
                        imap[S[ind1]]--;
						c = S[ind1];
                        break;
                    }
                }
            }
        }
        return result;
    }
};
