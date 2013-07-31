class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> imap;
        int result = 0;
        int len = num.size();
        
        for (int i = 0; i != len; i++){
            imap[num[i]]++;
        }
        
        len = imap.size();
        for (map<int, int>::iterator ite = imap.begin(); ite != imap.end(); ite++){
            if (ite->second == 0)
                continue;
            int start = ite->first+1, tmp = 1;
            while(imap[start] !=0){
                tmp++;
                imap[start] = 0;
                start++;
            }
            start = ite->first - 1;
            while(imap[start] != 0){
                tmp++;
                imap[start] = 0;
                start--;
            }
            if (tmp > result)
                result = tmp;
        }
        return result;
    }
};