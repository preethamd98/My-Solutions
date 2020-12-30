class Leaderboard {
public:
    set<pair<int,int>> S;
    unordered_map<int,int> M;
    
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        S.erase(make_pair(M[playerId], playerId));
        M[playerId] += score;
        S.insert(make_pair(M[playerId], playerId));
    }
    
    int top(int K) {
        int res = 0;
        for(auto it=S.rbegin();it!=S.rend() and K--;it++){
            res+=it->first;
        }
        return res;
    }
    
    void reset(int playerId) {
        S.erase(make_pair(M[playerId], playerId));
        M[playerId] = 0;
    }
};
​
/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
