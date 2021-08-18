class Solution {
public:
    string preFix(string s1,string s2){
        int i = 0;
        for(;i<min(s1.length(),s2.length());i++){
            if(s1[i]!=s2[i]){break;}
        }
        return s1.substr(0,i);
        
    }
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        for(int i=1;i<strs.size();i++){
            s = preFix(s,strs[i]);
        }
        return s;
    }
};