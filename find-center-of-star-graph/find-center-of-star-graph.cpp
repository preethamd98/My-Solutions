class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> m;
        for(auto i:edges){
            m[i[0]]++;
            m[i[1]]++;
        }
        for(auto it:m){
            if(it.second == edges.size()){return it.first;}
        }
        return -1;
    }
};