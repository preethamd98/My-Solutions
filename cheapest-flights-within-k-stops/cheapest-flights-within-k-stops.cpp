class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> prev_state(n,1e9);
        prev_state[src] = 0;
        for(int j=0;j<=K;j++){
            vector<int> current_state(prev_state);
            for(auto i:flights){
            current_state[i[1]] = min(current_state[i[1]],prev_state[i[0]]+i[2]);
          }
            prev_state = current_state;
        }
        return prev_state[dst]==1e9?-1:prev_state[dst];
    }
};
