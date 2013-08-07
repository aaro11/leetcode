class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        map<int, vector<vector<int> > > hash;
        int len = num.size();
        if (len < 4)    return result;
        vector<int> tmp(2);
        
        for (int i = 0; i != len - 1; i++){
            tmp[0] = i;
            for (int j = i + 1; j != len; j++){
                tmp[1] = j;
                hash[num[i] + num[j]].push_back(tmp);
            }
        }
        
        map<int, vector<vector<int> > >::iterator ite = hash.begin(), iend = hash.end();
        
        for (; ite != iend; ite++){
            vector<vector<int> > vec1 = ite->second, vec2 = hash[target-ite->first];
            
            if (vec1.size() && vec2.size()){
                for (int i = 0; i != vec1.size(); i++){
                    for (int j = 0; j != vec2.size(); j++){
                        if (vec1[i][0] != vec2[j][0] && vec1[i][1] != vec2[j][0] && vec1[i][0] != vec2[j][1] && vec1[i][1] != vec2[j][1]){
                            tmp.clear();
                            for (int k = 0; k != 2; k++){
                                tmp.push_back(num[vec1[i][k]]);
                                tmp.push_back(num[vec2[j][k]]);
                            }
                            sort(tmp.begin(), tmp.end());
                            result.push_back(tmp);
                        }
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        vector<vector<int> >::iterator uite = unique(result.begin(), result.end());
        result.erase(uite, result.end());
        
        return result;
    }
};