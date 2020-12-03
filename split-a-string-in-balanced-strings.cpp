class Solution {
public:
    int balancedStringSplit(string s) {
        int r = 0;
        int l = 0;
        int counter = 0;
        for(char c:s){
            if(c=='R'){r++;}
            else{l++;}
            if(l==r){counter++;}
        }
        return counter;
    }
};
