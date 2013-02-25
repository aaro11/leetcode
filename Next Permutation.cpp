class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
        int ind = -1, ind2;
        for (int i = len - 1; i != 0; i--){
            if (num[i-1] < num[i]){
                ind = i - 1;
                break;
            }
        }
        if (ind == -1){
            sort(num.begin(), num.end());
        }else{
            for (int i = len - 1; i != ind; i--){
                if (num[i] > num[ind]){
                    ind2 = i;
      			break;
                }
            }
            int tmp = num[ind2];
            num[ind2] = num[ind];
            num[ind] = tmp;
            sort(num.begin() + ind+1, num.end());
        }
        return ;
    }
};
