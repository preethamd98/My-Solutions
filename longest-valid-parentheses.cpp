class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0;
        for(int i=0;i<s.size();i++){
            int counter = 0;
            for(int j=i;j<s.size();j++){
                if(s[j]=='('){counter++;}
                else{counter--;}
                if(counter<0){break;}
                if(counter==0){longest = max(longest,j-i+1);}
            }
        }
        return longest;
    }
};
