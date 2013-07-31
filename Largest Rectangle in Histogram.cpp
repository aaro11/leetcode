class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = height.size();
        if (!len)
            return 0;
        if (len == 1){
            return height[0];
        }
        stack<int> h, ind;
        int result = 0, cnt = 0;
        
        for (int i = 0; i != len; i++){
            if (!h.size() || height[i] >= h.top()){
				h.push(height[i]);
				ind.push(1);
            }else{
				cnt = 0;
                while(h.size() && h.top() > height[i]){
                    if ((cnt + ind.top()) * h.top() > result){
                        result = (cnt + ind.top()) * h.top();
                    }
					cnt += ind.top();
					ind.pop(), h.pop();
                }
				h.push(height[i]);
				ind.push(cnt+1);
            }
        }
        
		cnt = 0;
        while(ind.size()){
            if ((cnt + ind.top()) * h.top() > result){
                result = (cnt + ind.top()) * h.top();
            }
			cnt += ind.top();
			ind.pop(), h.pop();
        }
        
        return result;
    }
};