class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = strlen(s);
        if (len < 1)
            return 0;
        bool flag = false;
        int result = 0;
        for (int i = len - 1; i != -1; i--){
            if (isalpha(s[i]))
                flag = true;
            if (flag && s[i] == ' ')
                break;
            if (flag)
                result++;
        }
        return result;
    }
};
