class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> M;
        M['}'] = '{';
        M[')'] = '(';
        M[']'] = '[';
        stack<char> S;
        for(char c:s){
            if(M.find(c)==M.end()){
                S.push(c);
            }
            else if(S.size()>0 and S.top() == M[c]){
                S.pop();
            }
            else if(S.size() == 0 and M.find(c)!=M.end()){
                return false;
            }
            else if(M.find(c)!=M.end() and S.top() != M[c]){
                return false;
            }
        }
        return S.size() == 0;
    }
};