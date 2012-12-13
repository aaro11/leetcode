
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (divisor == 1)
            return dividend;
            
        long long cur = abs((long long)divisor);
        long long tar = abs((long long)dividend);
        
        long long arr[34];
        memset(arr, 0, sizeof(arr));
        arr[0] = cur;
        for (int i = 1; i != 33; i++){
            arr[i] = arr[i-1] << 1;
            if (arr[i] < 0){
                arr[i] = 0;
            }
        }
        
        cur = 0;
        long long result = 0;
        for (int i = 33; i != -1; i--){
            if (!arr[i])
                continue;
                
            cur += arr[i];
            if (cur > tar)
                cur -= arr[i];
            else
                result += 1<<i;
        }
        int flag = (divisor ^ dividend) >> 31;
        if (flag)
            return -result;
        else
            return result;
    }
};