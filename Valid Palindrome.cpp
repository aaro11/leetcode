char toLowwerCase(char c){
    if (c >= 'A' && c <= 'Z'){
        return c - ('Z' - 'z');
    }
}

class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        string str;
        for (int i = 0; i != len; i++){
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                str += toLowwerCase(s[i]);
        }
        len = str.size();
        for (int i = 0; i != len / 2; i++){
            if (str[i] != str[len - i - 1])
                return false;
        }
        return true;
    }
};