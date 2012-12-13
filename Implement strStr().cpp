class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!haystack || ! needle){
            return NULL;
        }
        
        int len1 = strlen(haystack);
        int len2 = strlen(needle);
        
        if (len1 < len2)
            return NULL;
        
        for (int i = 0; i != len1 - len2 + 1; i++){
            bool flag = true;
            for (int j = 0; j != len2; j++){
                if (haystack[i+j] != needle[j]){
                    flag = false;
                    break;
                }
            }
            if (flag)
                return haystack + i;
        }
        return NULL;
    }
};