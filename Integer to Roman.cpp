string t[] = {"", "M", "MM", "MMM"};
string h[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
string ten[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
string f[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string result = "";
        result += t[num/1000];
        result += h[(num%1000)/100];
        result += ten[(num%100)/10];
        result += f[num%10];
        
        return result;
    }
};