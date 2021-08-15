class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> dict;
        for(char c:t){dict[c]++;}
        int counter = t.size();
        int start = 0;
        int l = INT_MAX;
        int startIndex = 0;
        for(int end=0;end<s.size();end++){
            if(dict[s[end]]-->0){counter--;}
            while(counter==0){
                if(end-start<l){startIndex = start;l = end-start+1;}
                dict[s[start]]++;
                if(dict[s[start]]>0){counter++;}
                start++;
            }
        }
        return l==INT_MAX?"":s.substr(startIndex,l);
    }
};