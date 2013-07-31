vector<vector<string> > result;

void pushresult(vector<int>& res){
    int len = res.size();
    vector<string> svec;
    string tmp = "";
    
    for (int i = 0; i !=  len; i++)
        tmp += ".";
        
    for (int i = 0; i != len; i++)
        svec.push_back(tmp);
        
    for (int i = 0; i != len; i++)
        svec[i][res[i]] = 'Q';
        
    result.push_back(svec);
}

void setmask(vector<vector<int> >&mask, int step, int pos){
    int len = mask.size();
    
    for (int i = 0; i != len; i++)
        mask[step][i] = mask[i][pos] = 1;
        
    int lb = 0 - min(pos, step), ub = len - max(step, pos);
    for (int i = lb; i != ub; i++){
        mask[step+i][pos+i] = 1;
    }
    
    for (int i = -10; i != 11; i++){
        if (step-i < len && step-i>-1 && pos+i < len && pos + i > -1)
            mask[step-i][pos+i] = 1;
    }
    
    return ;
}

void search(vector<vector<int> >& mask, int step, int sz, vector<int>& res){
    if (step == sz){
        pushresult(res);
        return ;
    }
    
    for (int i = 0; i != sz; i++){
        if (!mask[step][i]){
            vector<vector<int> > tmp = mask;
            res.push_back(i);
            setmask(tmp, step, i);
            search(tmp, step + 1, sz, res);
            res.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >mask(n);
        result.clear();
        for (int i = 0; i != n; i++){
            mask[i].resize(n);
        }
        vector<int> res;
        search(mask, 0, n, res);
        
        return result;
    }
};
