class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int days = prices.size();
        if(days==0){return 0;}
        vector<int> hasStock(days,0);
        vector<int> hasNoStock(days,0);
        
        //Base Case Initialization
        hasNoStock[0] = 0;
        hasStock[0] = -prices[0];
        
        for(int i=1;i<days;i++){
            hasNoStock[i] = max(hasNoStock[i-1],hasStock[i-1]+prices[i]-fee);
            hasStock[i] = max(hasStock[i-1],hasNoStock[i-1]-prices[i]);
        }
        return hasNoStock[days-1];
    }
};
