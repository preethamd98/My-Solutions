class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size()<=1){return false;}
        string n = s + s;
        n.pop_back();
        n = n.substr(1);
        return n.find(s)!=string::npos;
    }
};
