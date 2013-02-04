class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = digits.size();
        digits[len-1] += 1;
        
        for (int i = len-2; i != -1; i--){
            if (digits[i+1]>9){
                digits[i+1] %= 10;
                digits[i]++;
            }
        }
        if (digits[0] > 9){
            digits[0] %= 10;
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};
