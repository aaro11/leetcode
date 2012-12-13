class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        vector<int> tmp;
        sort(num.begin(), num.end());
        if (num.size() < 3)
            return result;
        for (int i = 0; i != num.size() - 2; i++){
			if (num[i] > 0)
				break;
            for (int j = i+1; j != num.size() - 1; j++){
				if (num[i] + num[j] > 0)
					break;
				int n = 0 - num[i] - num[j];
				if(binary_search(num.begin()+j+1, num.end(), n)){
					tmp.clear();
					tmp.push_back(num[i]);
					tmp.push_back(num[j]);
					tmp.push_back(n);
					result.push_back(tmp);
				}
            }
        }
        sort(result.begin(), result.end());
        vector<vector<int> >::iterator iter = unique(result.begin(), result.end());
        result.erase(iter, result.end());
        return result;
    }
};
