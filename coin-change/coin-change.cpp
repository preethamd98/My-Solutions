class Solution {
public:
    unordered_map<int,int> cache;
    int dfs(vector<int>& coins,int amount){
        if(amount==0){
            return 0;
        }
        else if(amount<0){
            return -1;
        }
        else if(cache.find(amount)!=cache.end()){
            return cache[amount];
        }
        int res = INT_MAX;
        for(int i:coins){
            int ans = dfs(coins,amount-i);
            if(ans>=0 and ans<res){
                res = ans + 1;
            }
        }
        return cache[amount] = res;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = dfs(coins,amount);
        return ans==INT_MAX?-1:ans;
    }
};
