class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
		int len = num.size();
		int tmp = 3 * num[len-1] + abs(target) + 1;
		int result = 0;
		for (int i = 0; i != len; i++){
			int j = 0, k = len - 1;
			while(j < k){
				if (j == i){
					j++;
					continue;
				}else if (k == i){
					k--;
					continue;
				}
				int sum = num[i] + num[j] + num[k];
				if (abs(sum-target) < tmp){
					result = sum;
					tmp = abs(sum-target);
				}
				if (sum > target)
					k--;
				else if (sum < target)
					j++;
				else{
					return result;
				}
			}
		}
		return result;
    }
};
