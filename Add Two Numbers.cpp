class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > result;
        int len = candidates.size();
        if (target <= 0 || len == 0){
            return result;
        }
        
        
        for (int i = 0; i != len; i++){
            vector<int> tmp;
            if (candidates[i] == target){
                tmp.push_back(candidates[i]);
                result.push_back(tmp);
            }else{
                vector<vector<int> > res = combinationSum(candidates, target - candidates[i]);
                for (int j = 0; j != res.size(); j++){
                    res[j].push_back(candidates[i]);
                    result.push_back(res[j]);
                }
                
            }
        }
        
        for (int i = 0; i != result.size(); i++){
            sort(result[i].begin(), result[i].end());
        }
        
        sort(result.begin(), result.end());
        vector<vector<int> >::iterator ite = unique(result.begin(), result.end());
        result.erase(ite, result.end());
        return result;
    }
};