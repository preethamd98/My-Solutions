class Solution {
public:
    int helper(vector<int>& stoneValue,int index,int player,int dp[][2]){
        if(index==stoneValue.size()){return 0;}
        if(dp[index][player]!=-1){return dp[index][player];}
        int score = 0;
        int size = stoneValue.size();
        if(player == 1){
            int maxi = INT_MIN;
            for(int i=index;i<min(index+3,size);i++){
                score += stoneValue[i];
                maxi = max(maxi, score+helper(stoneValue,i+1,0,dp));
            }
            return dp[index][player] = maxi;
        }
        else{
            int mini = INT_MAX;
            for(int i=index;i<min(index+3,size);i++){
                score -= stoneValue[i];
                mini = min(mini, score+helper(stoneValue,i+1,1,dp));
            }
            return dp[index][player] = mini;
        }
        return -1;
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        int size = stoneValue.size();
        int dp[size+1][2];
        memset(dp,-1,sizeof dp);
        int score = helper(stoneValue,0,1,dp);
        return score==0?"Tie":(score>0)?"Alice":"Bob";
    }
};
