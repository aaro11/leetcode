class Solution {
public:
    string longestPalindrome(string s) {
        // sind typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        int result = 1;
        int sind=0 , eind=0;
        int j;
        for (int i = 0; i != len; i++){
            //以i为中心，奇数个
            int tmp = -1;
            for (j = 0; j != i+1 && j != len - i; j++){
                if (s[i-j] == s[i+j]){
                    tmp += 2;
                }else{
                    break;
                }
            }
            if (tmp > result)
                result = tmp, sind = i-j+1, eind = i+j-1;
            tmp = 0;
            for (j = 0; j != i+1 && j != len - i; j++){
                if (s[i-j] == s[i+j+1]){
                    tmp += 2;
                }else{
                    break;
                }
            }
            if (tmp > result){
                result = tmp, sind = i-j+1, eind = i+j;
    		}
        }
        string res = "";
        for (int i = sind; i != eind + 1; i++){
            res += s[i];
        }
        return res;
    }
};