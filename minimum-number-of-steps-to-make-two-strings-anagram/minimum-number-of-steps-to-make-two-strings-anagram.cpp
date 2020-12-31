class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> m;
        int count = 0;
        for(auto ch : s) {
            m[ch]++;
        }
        for(auto ch : t) {
            if(m.find(ch) == m.end()) {
                count++;
            }
            else {
                m[ch]--;
                if(m[ch] == 0)
                    m.erase(ch);
            }
        }
        return count;
    }
};
​
// b -> 1
// a -> -1
    
//     abb
//     aab
