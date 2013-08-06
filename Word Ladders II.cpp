vector<string> neighbours(string s, unordered_set<string> &dict){
    int len = s.size();
    string tmp;
    vector<string> result;
    for (int i = 0; i != len; i++){
        tmp = s;
        for (int j = 'a'; j <= 'z'; j++){
            if (j == s[i])  continue;
            tmp[i] = j;
            if (dict.find(tmp) != dict.end())
                result.push_back(tmp);
        }
    }
    return result;
}

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > result, tmp;
        vector<string> svec, neigh, next;
        int len = dict.size();
        if (!len){
            return result;
        }
        dict.insert(end);
        bool flag = true;
        svec.push_back(start);
        result.push_back(svec);
        
        while(flag && len-- && dict.size()){
            bool haveneighbour = false;
            int sz = result.size(), len1 = result[0].size();
            tmp.clear(), svec.clear();
            
            for (int i = 0; i != sz; i++){
                neigh = neighbours(result[i][len1-1], dict);
                for (int j = 0; j != neigh.size(); j++){
                    haveneighbour = true;
                    if (neigh[j] == end)    flag = false;
                    svec = result[i];
                    svec.push_back(neigh[j]);
                    tmp.push_back(svec);
                    next.push_back(neigh[j]);
                }
            }
            sort(next.begin(), next.end());
            unique(next.begin(), next.end());
            
            for (int i = 0; i != next.size(); i++){
                unordered_set<string>::iterator ite = dict.find(next[i]);
                if (ite != dict.end())  dict.erase(ite);
            }
            
            if (!haveneighbour) break;
            result = tmp;
        }
        
        tmp = result, result.clear();
        for (int i = 0; i != tmp.size(); i++){
            if (tmp[i][tmp[i].size() - 1] == end)
                result.push_back(tmp[i]);
        }
        return result;
    }
};