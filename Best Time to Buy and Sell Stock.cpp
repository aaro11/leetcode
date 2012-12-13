class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() < 2)
            return 0;
            
        int result = 0, cur = prices[0];
        
        for (int i = 1; i != prices.size(); i++){
            if (prices[i] < cur){
                cur = prices[i];
            }
            else if(prices[i] - cur > result)
                result = prices[i] - cur;
        }
        return result;
        
    }
};