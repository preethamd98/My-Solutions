class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> V = {first};
        for(int i:encoded){
            V.push_back(V.back()^i);
        }
        return V;
    }
};
