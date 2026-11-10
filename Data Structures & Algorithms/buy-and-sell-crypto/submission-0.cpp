class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSell = 0, maxProfit = INT_MIN;

        for(int i=1; i<prices.size(); ++i){
            maxProfit = max(maxProfit, prices[i]-prices[minSell]);

            if(prices[i] < prices[minSell]) minSell = i;
        }

        if(maxProfit < 0) return 0;

        return maxProfit;
    }
};
