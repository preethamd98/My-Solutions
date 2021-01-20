class Solution {
public:
    unordered_map<string,bool> cache;
    bool dfs(string s,unordered_set<string>& S){
        if(s.length()==0){
            return true;
        }
        if(cache.find(s)!=cache.end()){
            return cache[s];
        }
        for(int i=1;i<=s.size();i++){
            string word = s.substr(0,i);
            if(S.find(word)!=S.end() and dfs(s.substr(i),S)){
                return cache[s] = true;
            }
        }
        return cache[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> S(wordDict.begin(),wordDict.end());
        return dfs(s,S);
    }
};
