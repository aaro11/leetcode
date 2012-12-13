
string cnt(string &src){
    int len = src.size();
    string result = "";
    
    for (int i = 0; i != len; i++){
        int cnt = 1;
        while( i < len - 1 && src[i] == src[i+1]){
            cnt++;
            i++;
        }
        result += cnt+'0';
        result += src[i];
    }
    return result;
}

class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string prev = "1";
        string next = "1";
        
        for (int i = 1; i != n; i++){
            next = cnt(prev);
            prev = next;
        }
        return next;
    }
};
