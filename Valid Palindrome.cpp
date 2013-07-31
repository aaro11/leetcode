<<<<<<< HEAD
char toLowwerCase(char c){
    if (c >= 'A' && c <= 'Z'){
        return c - ('Z' - 'z');
    }
}

=======
>>>>>>> dc848690c9b2b27cf97555b489b09b3dea1dd372
class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
<<<<<<< HEAD
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
=======
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
>>>>>>> dc848690c9b2b27cf97555b489b09b3dea1dd372
