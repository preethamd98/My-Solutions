class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> M;
        for(char c:s){M[c]++;}
        for(char c:t){M[c]--;}
        
        for(auto it=M.begin();it!=M.end();it++){
            if(it->second != 0){
                return false;
            }
        }
        return true;;
    }
};