class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        unordered_map<int,char> M;
        for(int i=0;i<s.size();i++){
            M[indices[i]] = s[i];
        }
        string ss = "";
        for(int i=0;i<s.size();i++){
            ss+=M[i];
        }
        return ss;
    }
};
