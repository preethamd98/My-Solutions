class Solution {
public:
    vector<string> V;
    void helper(string s, int n, int k) {
    if(V.size()==k){
        return;
    }
    else if(s.size()==n){
        V.push_back(s);
        return;
    }
    for(auto c:{'a','b','c'}){
        if(s.size()==0 or s.back()!=c){
            helper(s+c,n,k);
        }
    }
}
    string getHappyString(int n, int k) {
            helper("",n,k);
            if(V.size()<k){return "";}
            return V[k-1];
    }
};
