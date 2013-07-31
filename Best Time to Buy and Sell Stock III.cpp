class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = prices.size();
        if (len < 2)
            return 0;
        int* prof1 = new int[len], *prof2 = new int[len];
        memset(prof1, 0, sizeof(int) * len);
        memset(prof2, 0, sizeof(int) * len);
        
        int price = prices[0];
        for (int i = 1; i != len; i++){
            if (prices[i] < price)
                price = prices[i];
            else
                prof1[i] = prices[i] - price;
    		prof1[i] = prof1[i-1] > prof1[i] ? prof1[i-1] : prof1[i];
        }
        
        price = prices[len - 1];
        for (int i = len-2; i != 0; i--){
            if (prices[i] > price)
                price = prices[i], prof2[i] = prof2[i+1];
            else
                prof2[i] = price - prices[i];
			prof2[i] = prof2[i+1] > prof2[i] ? prof2[i+1] : prof2[i];
        }
        int result = 0, max = 0;
        for (int i = 0; i != len; i++){
            if (prof1[i] + prof2[i] > result)
                result = prof1[i] + prof2[i];
        }
        return result;
    }
};