class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<char> ivec;
        int len = s.size();
        for (int i = 0; i != len; i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                ivec.push_back(s[i]);
            else{
                if (ivec.size()){
                    char back = ivec.back();
                    if (!((back == '(' && s[i] == ')') || (back == '[' && s[i] == ']') || (back == '{' && s[i] == '}'))){
                        return false;
                    }
                    ivec.pop_back();
                }else{
                    return false;
                }
            }
        }
        if (ivec.size())
            return false;
        return true;
    }
};