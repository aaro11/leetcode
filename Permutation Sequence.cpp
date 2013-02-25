class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cnt[10], occu[10];
      k--;
        cnt[0] = 1;
        occu[0] = 0;
        for (int i = 1; i != n + 1; i++){
            cnt[i] = cnt[i-1] * i;
            occu[i] = 0;
        }
        string result = "";
        while(n-1){
            int kth = k / cnt[n-1];
            k %= cnt[n-1];
            for (int i = 1; i != 10; i++){
                if (!occu[i]){
                    if (!kth){
                        result = result + (char)(i + '0');
                        occu[i] = 1;
                        break;
                    }
                    kth--;
                }
            }
			n--;
        }
		for (int i = 1; i != 10; i++){
			if (!occu[i]){
    			result = result + (char)(i+'0');
    		    break;   
			}
		}
        return result;
    }
};
