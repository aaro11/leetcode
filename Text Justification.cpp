string spaces[100];
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        spaces[0] = "";
        for (int i = 1; i != 100; i++){
            spaces[i] = spaces[i-1] + " ";
        }
        int s = 0, len = words.size();
        vector<string> result;
        if (!L){
            result.push_back("");
            return result;
        }
        while(s < len){
            int i = 1, accu = words[s].size();
            string tmp = "";
            while(s+i < len && accu + words[s+i].size() + 1 <= L){
                accu += words[s+i].size() + 1;
                i++;
            }
            
            int fill = L - accu;
            if (i != 1 && s+i != len){
                for (int j = s; j != s + i; j++){
                    int cnt = ceil((double)fill/(s+i-j-1));
                    tmp += words[j] + spaces[ cnt +1];
                    fill -= cnt;
                }
            }else{
                for (int j = s; j != s + i; j++){
                    tmp += words[j] + " ";
                }
            }
            tmp += spaces[fill];
            s = s + i;
            tmp = tmp.substr(0, L);
            result.push_back(tmp);
        }
        return result;
    }
};