class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int totallen = 0, len = S.size();
        vector<int> result;
        if (!len || !L.size() || !L[0].size()) 
    		return result;
        int dictlen = L[0].size();
        totallen = L.size() * dictlen;
		map<string, int> cnt;
		for (int i = 0; i != L.size(); i++)
			cnt[L[i]]++;
        vector<string>::iterator ibegin = L.begin(), iend = L.end(), ite;
        for (int i = 0; i < len - totallen + 1; i++){
            bool flag = true;
			map<string, int> tmp;
            for (int j = 0; j != L.size(); j++){
                string str = S.substr(i + j * dictlen, dictlen);
				tmp[str]++;
				if (tmp[str] > cnt[str]){
					flag = false;
					break;
				}
            }
            
            if (flag)   result.push_back(i);
        }
		return result;
    }
};