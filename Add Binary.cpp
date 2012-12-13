class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int t = 0;
        int lena = a.size();
        int lenb = b.size();
        
        reverse(a);
        reverse(b);
        
        string str1, str2;
        string result = "";
        int len1 = lena > lenb ? lena : lenb; // the shorter one
        int len2 = lena > lenb ? lenb : lena;
        str1 = lena > lenb ? a : b;
        str2 = lena > lenb ? b : a;
        
        for (int i = 0; i != len2; i++){
            int x = str1[i] - '0' + str2[i] - '0' + t;
            t = x/2;
            result = result + (char)(x%2 + '0');
        }
        for (int i = len2; i != len1; i++){
            int x = str1[i] - '0' + t;
            t = x / 2;
            result = result + (char)(x%2 + '0');
        }
        if (t)
            result = result + '1';
        
        reverse(result);
		return result;
        
    }
};