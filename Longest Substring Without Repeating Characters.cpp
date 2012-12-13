class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int arr[26];
        memset(arr, 0, sizeof(arr));
        int len = 0;
        int result = 0;
        for (int i = 0; i != s.size(); i++){
            if (!arr[s[i] - 'a']){
                arr[s[i]-'a'] = i+1;
                len++;
            }else{
                if (len > result){
                    result = len;
                }
                for (int j = 0; j != 26; j++){
                    if (arr[j] && arr[j] < arr[s[i] - 'a'])
                        arr[j] = 0, len--;
                }
                arr[s[i]-'a'] = i+1;
            }
        }
        if (len > result)
            result = len;
        return result;
    }
};