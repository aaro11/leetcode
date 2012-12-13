#define GET(i, off)  (1&(i >> off))
inline int SET(int src, int ind, int v){
    if (v == 1)
		src |= 1 << ind;
	else
		src &= (1<<31) -  (1<<ind) - 1;
	return src;
}

int convert(int src, int len){
	for (int i = 0; i != len - 1; i++){
		src = SET(src, i, GET(src, i)^GET(src, i+1));
	}

	return src;
}

class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> result;
        if (!n){
            result.push_back(0);
            return result;
        }
		for (int i = 0; i != pow(2, n); i++){
			result.push_back(convert(i, n));
		}

		return result;
    }
};