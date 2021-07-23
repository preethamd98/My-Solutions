class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> M;
        int left = 0;
        int counter = 0;
        int size = s.size();
        int ans = 0;
        for(int right=0;right<size;right++){
            M[s[right]]++;
            while(left<size and M['a'] and  M['b'] and M['c']){
                counter++;
                M[s[left]]--;
                left++;
            }
            ans += counter;
        }
        return ans;
    }
};