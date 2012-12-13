class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = 2 * n;
        vector<vector<string> > result = vector<vector<string> >(len);
        vector<vector<int> > cnt = vector<vector<int> >(len);
        
        string start = "(";
        vector<string> tmp;
        tmp.push_back(start);
        result[0] = tmp;
        int x1 = 1;
        vector<int> ivec;
        ivec.push_back(x1);
        cnt[0] = ivec;
        
        for (int i = 1; i != len; i++){
            ivec.clear(), tmp.clear();
            
            for (int j = 0; j != result[i-1].size(); j++){
    			x1 = cnt[i-1][j];
				if (x1 < len / 2){
					ivec.push_back(x1+1);
					tmp.push_back(result[i-1][j] + "(");
				}
                if (x1 > i/2){
                    ivec.push_back(x1);
                    tmp.push_back(result[i-1][j] + ")");
                }
            }
			result[i] = tmp;
			cnt[i] = ivec;
        }
        
        return result[len-1];
    }
};