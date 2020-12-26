class Solution {
public:
    bool helper(vector<int>& piles,int i,int j,int alex=0,int lee=0){
        if(i==j || i>j){return alex>lee;}
        return helper(piles,i+1,j,alex+piles[i],lee) || helper(piles,i,j-1,alex,lee+piles[j]);
        
    }
    bool stoneGame(vector<int>& piles) {
        return helper(piles,0,piles.size()-1);
    }
};
