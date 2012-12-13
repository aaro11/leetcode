
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<vector<int> > > result(target + 2);
        for (int i = 0; i != target + 2; i++){
            vector<vector<int> > tmp;
            result[i] = tmp;
        }
        
        sort(candidates.begin(), candidates.end());
        int len = candidates.size();
        
        for (int i = 0; i != len; i++){
            for (int j = target + 1; j != 0; j--){
                int v = j - candidates[i];
                if (v < 0)
                    continue;
                
                if (v == 0){
                    vector<int> p ;
                    p.push_back(candidates[i]);
                    result[j].push_back(p);
                    continue;
                }
                
                for (int k = 0; k != result[v].size(); k++){
                    vector<int> p = result[v][k];
                    p.push_back(candidates[i]);
                    result[j].push_back(p);
                }
            }
        }
        
        sort(result[target].begin(), result[target].end());
        vector<vector<int> >::iterator ite = unique(result[target].begin(), result[target].end());
        result[target].erase(ite, result[target].end());
        
        return result[target];
    }
};