
int str2int(string s){
    if (s[0] == '0' && s.size() > 1)	return 1000;
    stringstream ss;
    int ret;
    ss<<s;
    ss>>ret;
    return ret;
}
string int2str(int i){
	stringstream ss;
	ss<<i;
	string ret;
	ss>>ret;
	return ret;
}
vector<string> result;
void search(string s, int sind, int remain, string tmp){
    if (remain == 0){
        if( sind == s.size()){
            result.push_back(tmp.substr(1, tmp.size() - 1));
        }
        return ;
    } 
    
    for (int i = 0; i != 3 && i < s.size() - sind; i++){
		int subip = str2int(s.substr(sind, i+1));
        if (subip < 256){
            search(s, sind+i+1, remain-1, tmp+"."+int2str(subip));
        }
    }
}

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        search(s, 0, 4, "");
        
        return result;
    }
};
