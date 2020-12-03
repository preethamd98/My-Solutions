class Solution {
public:
    int balancedStringSplit(string s) {
        int u = 0;
        int l = 0;
        int counter = 0;
        for(char c:s){
            if(c=='R'){u++;}
            else{l++;}
            if(l==u){counter++;}
        }
        return counter;
    }
};
