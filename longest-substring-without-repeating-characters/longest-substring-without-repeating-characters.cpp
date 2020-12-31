class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        int i = 0, j = 0;
        int res = 1;
        unordered_set<char> lookup;
        while(i < s.size()) {
            if(lookup.find(s[i]) == lookup.end()) {
                lookup.insert(s[i]);
            }
            else {
                res = max(res,i-j);
                while(s[j] != s[i]){
                    lookup.erase(s[j++]);
                }
                    
                lookup.erase(s[j]);
                j++;
                lookup.insert(s[i]);
            }
            i++;
        }
        res = max(res, i-j);
        return res;
    }
};
