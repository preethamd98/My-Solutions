class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<int> buy(size,0);
        vector<int> sell(size,0);
        buy[0] = -prices[0];
        sell[0] = INT_MIN;
        for(int i=1;i<size;i++){
            buy[i] = max(buy[i-1], -prices[i]);
            sell[i] = max(sell[i-1], prices[i]+buy[i-1]);
        }
        return max(0,sell[size-1]);
    }
};