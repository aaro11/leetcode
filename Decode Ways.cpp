int val(string &s, int a, int b){
    string tmp = "";
    for (int i = a; i <= b; i++){
        tmp += s[i];
    }
    stringstream ss;
    ss<<tmp;
    int ret;
    ss>>ret;
    
    return ret;
}

inline bool valid1(int v){
    return v > 0 && v < 27;
}

inline bool valid2(int v){
    return v > 9 && v < 27;
}

class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        int cnt = 0;
        
        if (!len)
            return 0;
        vector<int> result = vector<int>(len);
        
        if (s[0] == '0')
            result[0] = 0;
        else
            result[0] = 1;
        
        if (valid2(val(s,0,1)))
            cnt += 1;
        if (valid1(val(s,1,1)))
            cnt += result[0];
        result[1] = cnt;
        
        for (int i = 2; i < len; i++){
            cnt = 0;
            if (valid2(val(s,i-1, i)))
                cnt += result[i-2];
            if (valid1(val(s,i,i)))
                cnt += result[i-1];
            result[i] = cnt;
        }
        
        return result[len-1];
    }
};