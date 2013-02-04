class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0)
            return false;
        int exp = (int)log10(x);
        int lim = pow(10, exp);
        
        while(x){
            if (x%10 != x/lim)
                return false;
                
            x = x % lim;
            x = x/10;
            lim /= 100;
        }
        return true;
    }
};
