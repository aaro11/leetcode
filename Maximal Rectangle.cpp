class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!matrix.size() || !matrix[0].size()){
            return 0;
        }
        
        int len1 = matrix.size(), len2 = matrix[0].size();
        int result = 0, tmp = 0;
        vector<vector<int> > sum(len1);
        
        for (int i = 0; i != len1; i++){
            sum[i].resize(len2);
            
            for (int j = 0; j != len2; j++){
                if (matrix[i][j] == '0')
                    sum[i][j] = 0;
                else if (!i)
                    sum[i][j] = 1;
                else
                    sum[i][j] = sum[i-1][j] + 1;
            }
            tmp = largestRectangleArea(sum[i]);
            result = max(result, tmp);
        }
        
        return result;
        
    }
    
private:
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