int dp[2000][2000];

class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        int arr[2000];
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
    	int sind, eind;
		for (int i = 0; i != len; i++){
			dp[i][i] = 1;
			sind = i - 1, eind = i + 1;
			while(sind >= 0 && eind < len){
				dp[sind][eind] = s[sind] == s[eind] ? dp[sind+1][eind-1] : -1;
				sind--, eind++;
			}
			dp[i][i+1] = s[i] == s[i+1] ? 1 : -1;
			sind = i - 1, eind = i + 2;
			while(sind >= 0 && eind < len){
				dp[sind][eind] = s[sind] == s[eind] ? dp[sind+1][eind-1] : -1;
				sind--, eind++;
			}
		}
        arr[0] = 0;
        for (int i = 0; i != len; i++){
            arr[i+1] = arr[i] + 1;
            for (int j = i - 1; j > -1; j--){
                if (dp[j][i] == 1 && arr[i+1] > arr[j] + 1){
                    arr[i+1] =arr[j] + 1;
                }
            }
        }
        return arr[len] - 1;
    }
};
