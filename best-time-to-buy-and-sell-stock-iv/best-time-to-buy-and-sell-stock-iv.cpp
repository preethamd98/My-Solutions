class Solution {
public:
    int maxP(vector<int> & p) {
        int res = 0;
        for (int i = 1; i < p.size(); i++) {
            if (p[i] > p[i-1]) {
                res += p[i] - p[i-1];
            }
        }
        return res;
    }    
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if(k<1 || size==0){
            return 0;
        }
        vector<vector<int>> buy(k+1,vector<int>(size,0));
        vector<vector<int>> sell(k+1,vector<int>(size,0));
        
        if (k >= prices.size() / 2) {
            return maxP(prices);
        }
        
        
        
        for(int i=1;i<=k;i++){
            buy[i][0] = -prices[0];
        }
        
        for(int i=1;i<size;i++){
            buy[1][i] = max(-prices[i],buy[1][i-1]);
            sell[1][i] = max(sell[1][i-1],buy[1][i-1] + prices[i]);
            for(int j=2;j<=k;j++){
                buy[j][i] = max(buy[j][i-1],sell[j-1][i-1] - prices[i]);
                sell[j][i] = max(sell[j][i-1],buy[j][i-1] + prices[i]);
            }
        }
        return sell[k][size-1];
    }
};

