
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        int len = num.size();
        vector<vector<int> > result;
        if (len < 4)
            return result;
        vector<int> tmp(4);
        
        for (int i = 0; i != len - 1; i++){
            for (int j = i+1; j != len; j++){
                int tar = target - num[i] - num[j];
                tmp[0] = num[i];
                tmp[1] = num[j];
                int p = 0, q = len - 1;
                while(p < q){
                    if (p == i || p == j){
                        p++;
                        continue;
                    }
                    if (q == i || q == j){
                        q--;
                        continue;
                    }
                    
                    int sum = num[p] + num[q];
                    if (sum == tar){
                        tmp[2] = num[p];
                        tmp[3] = num[q];
                        result.push_back(tmp);
                        p++;
						q--;
						continue;
                    }else if (sum > tar)
                        q--;
                    else if (sum < tar)
                        p++;
                }
            }
        }
        for (int i = 0; i != result.size(); i++){
			sort(result[i].begin(), result[i].end());
		}
        sort(result.begin(), result.end());
	    vector<vector<int> >::iterator iter = unique(result.begin(), result.end());
	    result.erase(iter, result.end());
	    return result;

    }
};