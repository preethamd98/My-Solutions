class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_set<int> visited = {id};
        vector<int> q1 = {id};
        vector<string> res;
        while(level-- >0){
            vector<int> q2;
            for(auto it1:q1){
                for(auto it2:friends[it1]){
                    if(visited.insert(it2).second){
                        q2.push_back(it2);
                    }
                }
            }
            swap(q1,q2);
        }
        unordered_map<string,int> M;
        for(auto i:q1){
            for(auto j:watchedVideos[i]){
                M[j]++;
            }
        }
        set<pair<int,string>> S;
        for(auto& it:M){
            S.insert({it.second,it.first});
        }
        for(auto& it:S){
            res.push_back(it.second);
        }
        return res;
    }
