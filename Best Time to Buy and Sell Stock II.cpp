class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() < 2)
            return 0;
        
        int cur = prices[0];
        bool own = false;
        if (cur <= prices[1])
            own = true;
        int result = 0;
        
        for (int i = 1; i != prices.size() - 1; i++){
            if (!own && prices[i] <= prices[i-1] && prices[i] <= prices[i+1])
                cur = prices[i], own=true;
            if (own && prices[i] >= prices[i-1] && prices[i] >= prices[i+1])
                result += prices[i] - cur, own=false;
        }
        if (prices[prices.size() - 1] > prices[prices.size() - 2] && prices[prices.size() -1] > cur)
            result += prices[prices.size() - 1] - cur;
            
        return result;
        
    }
};