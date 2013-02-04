void split(string &src, int* arr){
    int len = src.size();
    stringstream ss;
    
    for (int i = 0; i != (len-1)/4 + 1; i++){
      ss.clear();
        string tmp = src.substr(i*4, 4);
		ss<<tmp;
        ss>>arr[i];
    }
    
    return ;
}

bool inline iszero(string &s1){
	return (s1.size() == 1 && s1[0] == '0');
}

class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (iszero(num1) || iszero(num2))
			return "0";

        int arr1[100], arr2[100], result[201];
		stringstream ss;
		memset(arr1, 0, sizeof(arr1));
		memset(arr2, 0, sizeof(arr2));
		memset(result, 0, sizeof(result));
		int app = 0;
		while(num1.size() % 4)
			num1 = num1 + "0", app++;
		while(num2.size() % 4)
			num2 = num2 + "0", app++;

        int len1 = num1.size(), len2 = num2.size();
		
		string ret = "", tmp="";
        //reverse(num1.begin(), num1.end());
		//reverse(num2.begin(), num2.end());

        split(num1, arr1);
        split(num2, arr2);
        
        for (int i = 0; i != (len1-1)/4+1; i++){
            for (int j = 0; j != (len2-1)/4+1; j++){
                result[i+j] += arr1[i] * arr2[j];
            }
        }
        for (int i = len1/4+len2/4-1; i != -1; i--){
            result[i] += result[i+1]/10000;
            result[i+1] %= 10000;
        }
		ss<<result[0];
		ss>>tmp;
		ret += tmp;
		
		for (int i = 1; i != (len1-1)/4 + (len2-1)/4+1; i++){
			ss.clear();
			ss<<result[i];
			ss>>tmp;
			while(tmp.size() < 4)
				tmp = "0" + tmp;
			ret += tmp;
		}
		ret = ret.substr(0, ret.size() - app);
        return ret;
    }
};
