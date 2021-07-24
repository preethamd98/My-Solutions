class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> hasStock(n,0);
        vector<int> noStock(n,0);
        hasStock[0] = -prices[0];
        for(int i=1;i<n;i++){
            hasStock[i] = max(hasStock[i-1], -prices[i]+noStock[i-1]);
            noStock[i] = max(noStock[i-1],prices[i]+hasStock[i-1]-fee);
        }
        return noStock[n-1];
    }
};