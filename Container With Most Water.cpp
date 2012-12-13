class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (height.size() < 2)
            return 0;
        if (height.size() == 2){
            return min(height[0], height[1]);
        }

    	int result = 0;
		int len = height.size();
		int s = 0, e = len - 1;
		while (s < e){
			int x = (e-s)*min(height[e], height[s]);
			if (x > result){
				result = x;
			}
			if (height[e] < height[s]){
				e--;
			}else{
				s++;
			}
		}

        return result;
    }
};