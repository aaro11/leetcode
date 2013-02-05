class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        if (!len)
            return true;
        
        int sind = 0, eind = len - 1;
        while(sind < eind){
            while(!isalpha(s[sind]) && !isdigit(s[sind]) && sind < len)
                sind++;
            while(!isalpha(s[eind]) && !isdigit(s[eind]) && eind > 0)
                eind--;
                
            if (sind > eind)
                break;
                
            if (tolower(s[sind]) != tolower(s[eind]))
                return false;
            sind++, eind--;
        }
        return true;
    }
};
