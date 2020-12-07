class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        map<int,char> M;
        for(int i=0;i<s.size();i++){
            M[indices[i]] = s[i];
        }
        string ss = "";
        for(auto it:M){
            ss+=it.second;
        }
        return ss;
    }
};
