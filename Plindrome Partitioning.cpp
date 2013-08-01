bool legal(string s, int start, int end){
    //doesn't include s[end]
    end--;
    while(start < end){
        if (s[start] != s[end])
            return false;
        start++, end--;
    }
    return true;
}

vector<vector<string> > result;

void part(string s, int start, vector<string>& tmp){
    if (start == s.size()){
        result.push_back(tmp);
        return ;
    }
    for (int i = start+1; i <= s.size(); i++){
        if (legal(s, start, i)){
            tmp.push_back(s.substr(start, i - start));
            part(s, i, tmp);
            tmp.pop_back();
        }
    }
    return ;
}

class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        vector<string> tmp;
        part(s, 0, tmp);
        
        return result;
    }
};