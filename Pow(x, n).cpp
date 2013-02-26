double p[33];

double abspow(double x, int n){
    if (n == 0)
        return 1;
    double result;
    if (abs(n) == 1)
        result = x;
    else{
        double tmp = abspow(x, n/2);
        if (n % 2)
            result = x * tmp * tmp;
        else
            result = tmp * tmp;
    }
    
    return result;
}

class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double result = abspow(x, n);
        if (n < 0)
            return 1/result;
            
        return result;
    }
};
