class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> chars;
        int currentNum = 0;
        string res = "";
        
        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                currentNum = currentNum * 10 + (s[i] - '0');
            }
            else if(isalpha(s[i])) {
                res += s[i];
            }
            else if(s[i] == '[') {
                nums.push(currentNum);
                chars.push(res);
                currentNum = 0;
                res = "";
            }
            else {
                string temp = res;
                int count = nums.top();
                nums.pop();
                for(int i = 0; i < count-1; i++) {
                    temp += res;
                }                
                string topString = chars.top();
                chars.pop();
                topString += temp;
                res = topString;
            }
            
        }
        return res;
    }
};
